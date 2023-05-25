#include "smart_calc.h"

double algorithm(char *input, double x) {
  double res = 0;
  // printf("input: %s\n", input);
  if (check(input) == CORRECT) {
    res = parser(input, x);
    // printf("%f\n", res);
  }
  return res;
}

void result(num *number_stack, calc *oper_stack) {
  if (oper_stack->count > 0) {
    while (oper_stack->count != 0) {
      double number = popNum(number_stack);
      operation_compl(number, number_stack, popOper(oper_stack));
    }
  } else {
    double number = popNum(number_stack);
    operation_compl(number, number_stack, popOper(oper_stack));
  }
}

void what_end_num(num *stack, int *с, char *input) {
  char str[256] = {'\0'};
  int cnt = 0;
  if (input[*с] == '+' || input[*с] == '-') {
    str[cnt] = input[*с];
    cnt++;
    (*с)++;
  }
  while ((input[*с] > 47 && input[*с] < 58) || input[*с] == '.') {
    str[cnt] = input[*с];
    cnt++;
    (*с)++;
  }
  (*с)--;
  pushNum(stack, atof(str));
}

void findPriority(calc *oper_stack, char *str, int с, num *number_stack) {
  if (oper_stack->count > 0) {
    char Last = popOper(oper_stack);
    if (getPriority(Last) < getPriority(str[с])) {
      pushOper(oper_stack, Last);
      readTrigonom(oper_stack, str, с);
    } else {
      double number2 = popNum(number_stack);
      operation_compl(number2, number_stack, Last);
      pushOper(oper_stack, str[с]);
    }
  } else {
    readTrigonom(oper_stack, str, с);
  }
}

void readTrigonom(calc *oper_stack, char *str, int с) {
  if ((str[с]) == 'a') {
    if ((str[с + 1]) == 't') {
      pushOper(oper_stack, 'T');
    } else if ((str[с + 1]) == 'c') {
      pushOper(oper_stack, 'C');
    } else if ((str[с + 1]) == 's') {
      pushOper(oper_stack, 'S');
    }
  } else if ((str[с]) == 'l') {
    ((str[с + 1]) == 'n') ? pushOper(oper_stack, 'l')
                          : pushOper(oper_stack, 'L');
  } else if ((str[с]) == 's') {
    ((str[с + 1]) == 'i') ? pushOper(oper_stack, 's')
                          : pushOper(oper_stack, 'q');
  } else if ((str[с]) == 'm') {
    pushOper(oper_stack, 'm');
  } else if ((str[с]) == 'c') {
    pushOper(oper_stack, 'c');
  } else if ((str[с]) == 't') {
    pushOper(oper_stack, 't');
  } else {
    pushOper(oper_stack, str[с]);
  }
}

void operation_compl(double number, num *number_stack, char с) {
  double number_2 = 1;
  if (number_stack->count > 0 && getPriority(с) < 5) {
    number_2 = popNum(number_stack);
  }
  if (с == '+') {
    pushNum(number_stack, (number + number_2));
  } else if (с == '-') {
    pushNum(number_stack, (number_2 - number));
  } else if (с == '/') {
    if (number == 0)
      pushNum(number_stack, 0);
    else
      pushNum(number_stack, (number_2 / number));
  } else if (с == '*') {
    pushNum(number_stack, (number_2 * number));
  } else if (с == '^') {
    pushNum(number_stack, (pow(number_2, number)));
  } else if (с == '%') {
    pushNum(number_stack, (fmod(number_2, number)));
  } else if (с == 'L') {
    pushNum(number_stack, (log10(number)));
  } else if (с == 'l') {
    pushNum(number_stack, (log(number)));
    // printf("ln %lf\n", number);
  } else if (с == 'T') {
    pushNum(number_stack, (atan(number)));
  } else if (с == 'C') {
    pushNum(number_stack, (acos(number)));
  } else if (с == 'S') {
    pushNum(number_stack, (asin(number)));
  } else if (с == 'q') {
    pushNum(number_stack, (sqrt(number)));
  } else if (с == 's') {
    pushNum(number_stack, (sin(number)));
  } else if (с == 'c') {
    pushNum(number_stack, (cos(number)));
  } else {
    pushNum(number_stack, (tan(number)));
  }
}

int getPriority(char с) {
  int res = 0;
  if (с == '+' || с == '-') {
    res = plus;
  } else if (с == 'm' || с == '%') {
    res = modul;
  } else if (с == '*' || с == '/') {
    res = divide;
  } else if (с == '^') {
    res = power;
  } else if (с == '(' || с == ')') {
    res = bascket;
  } else {
    res = trigonom;
  }
  return res;
}

double parser(char *input, double x) {
  int length = strlen(input);
  calc oper_stack = {0};
  oper_stack.count = 0;
  num number_stack = {0};
  number_stack.count = 0;
  for (int c = 0; c < length; c++) {
    if (input[c] == '$' || input[c] == '@') {
      if (input[c] == '$') input[c] = '-';
      if (input[c] == '@') input[c] = '+';
      what_end_num(&number_stack, &c, input);
    } else if (input[c] == 'x') {
      pushNum(&number_stack, x);
    } else if (input[c] == '^' || input[c] == '*' || input[c] == '/' ||
               input[c] == '-' || input[c] == '+' || input[c] == '$' ||
               input[c] == '@' || input[c] == '%') {
      if (oper_stack.count == 0) {
        pushOper(&oper_stack, input[c]);
      } else {
        findPriority(&oper_stack, input, c, &number_stack);
      }
    } else if (input[c] > 47 && input[c] < 58) {
      what_end_num(&number_stack, &c, input);
    } else if (input[c] == '(') {
      pushOper(&oper_stack, input[c]);
    } else if (input[c] == ')') {
      char need_oper = popOper(&oper_stack);
      if (need_oper != '(') {
        for (; need_oper != '('; need_oper = popOper(&oper_stack)) {
          double number1 = popNum(&number_stack);
          operation_compl(number1, &number_stack, need_oper);
        }
      } else if (oper_stack.count > 0) {
        double number1 = popNum(&number_stack);
        operation_compl(number1, &number_stack, popOper(&oper_stack));
      }
    } else if (is_triginom(c, input)) {
      findPriority(&oper_stack, input, c, &number_stack);
      what_end_of_input(&c, input);
    }
  }
  if (oper_stack.count > 0) {
    while (oper_stack.count != 0) {
      double number = popNum(&number_stack);
      operation_compl(number, &number_stack, popOper(&oper_stack));
    }
  }
  if (number_stack.count > 1) {
    result(&number_stack, &oper_stack);
  }
  double res = final(&number_stack);
  return res;
}

int is_triginom(int c, char *input) {
  int res = 0;
  if (input[c] == 'm' || input[c] == 'c' || input[c] == 's' ||
      input[c] == 't' || input[c] == 'a' || input[c] == 'l') {
    res = 1;
  }
  return res;
}

int check(char *input) {
  int res = CORRECT;
  int length = strlen(input);
  int is_error = false;
  int bracket_cnt = 0;
  int is_last_dig = false;
  int is_last_op = false;
  int digit_cnt = 0;
  int dot_cnt = 0;

  for (int с = 0; с < length; с++) {
    if (input[с] == 'x') {
      с++;
      digit_cnt++;
    }
    if (input[с] == '(') {
      if (input[с + 1] == ')') {
        is_error = true;
        break;
      }
      is_last_dig = false;
      is_last_op = false;
      digit_cnt = 0;
      bracket_cnt++;
      continue;
    }
    if (input[с] == ')') {
      if (bracket_cnt < 1) {
        is_error = true;
        break;
      }
      bracket_cnt--;
      is_last_dig = false;
      is_last_op = false;
      digit_cnt = 0;
      continue;
    }
    if (input[с] == '.') {
      if ((digit_cnt == 0) || (dot_cnt > 0)) {
        is_error = true;
        break;
      }
      if (с + 1 == length) {
        is_error = true;
        break;
      }
      is_last_dig = false;
      is_last_op = false;
      digit_cnt = 0;
      dot_cnt++;
      continue;
    }
    if (dot_cnt > 0) {
      if (input[с] > 47 && input[с] < 58) {
        digit_cnt++;
        is_last_dig = true;
        is_last_op = false;
        continue;
      }
    }
    if (input[с] > 47 && input[с] < 58) {
      if (digit_cnt == 1 && is_last_dig == true && input[с - 1] == '0') {
        is_error = true;
        break;
      }
      if (is_last_op == true && input[с - 1] == '/' && input[с] == '0') {
        is_error = true;
        break;
      }
      digit_cnt++;
      is_last_dig = true;
      is_last_op = false;
      continue;
    }
    if (input[с] == 'm' || input[с] == 'c' || input[с] == 's' ||
        input[с] == 't' || input[с] == 'l') {
      correct_trigonom(&is_error, с, &is_last_dig, &is_last_op, input);
      if (is_error == true) break;
      what_end_of_input(&с, input);
      continue;
    }
    if (input[с] == '^' || input[с] == '*' || input[с] == '/' ||
        input[с] == '-' || input[с] == '+' || input[с] == '%') {
      if ((input[с] == '^' || input[с] == '*' || input[с] == '/' ||
           input[с] == '%') &&
          с == 0)
        is_error = true;
      if (input[с + 1] == '^' || input[с + 1] == '*' || input[с + 1] == '/' ||
          input[с + 1] == '%')
        is_error = true;
      if ((input[с + 1] == '-' || input[с + 1] == '+')) {
        if (input[с + 1] == '-') {
          input[с + 1] = '$';
        }
        if (input[с + 1] == '+') input[с + 1] = '@';
        is_last_dig = true;
      }
      if ((input[с] == '-' || input[с] == '+') &&
          (с == 0 || input[с - 1] == '(')) {
        if (input[с] == '-') {
          input[с] = '$';
        }
        if (input[с] == '+') input[с] = '@';
        is_last_dig = true;
      }
      if (is_last_op == true) {
        printf("here_8\n");
        is_error = true;
        break;
      }
      if (dot_cnt && is_last_op == false) dot_cnt--;
      // if (is_last_dig == false && input[с - 1] != ')') {
      //   printf("here_9\n");
      //   is_error = true;
      //   break;
      // }
      if (с + 1 == length) {
        is_error = true;
        break;
      }
      digit_cnt = 0;
      is_last_dig = false;
      continue;
    }
  }
  if ((is_bascket_corr(bracket_cnt, &is_error)) == 0) {
    if (is_error == true) {
      res = ERROR;
    }
  } else {
    res = ERROR;
  }
  return res;
}

int is_bascket_corr(int bracket_cnt, int *is_break) {
  int res = CORRECT;
  if (bracket_cnt != 0) {
    *(is_break) = 1;
    res = ERROR;
  }
  return res;
}

void correct_trigonom(int *is_break, int с, int *is_last_dig, int *is_last_op,
                      char *input) {
  if (input[с] == 'm') {
    if (*is_last_dig != 1 || с > 251) *is_break = 1;
  } else if (input[с] == 'c') {
    if (с > 0 && input[с - 1] == 'a') {
      if (с > 249) *is_break = 1;
    } else {
      if (с > 249) *is_break = 1;
    }
  } else if (input[с] == 't') {
    if (с > 0 && input[с - 1] == 'a') {
      if (с > 249) *is_break = 1;
    } else {
      if (с > 249) *is_break = 1;
    }
  } else if (input[с] == 's') {
    if (с > 249) {
      *is_break = 1;
    } else if (input[с + 1] == 'q') {
      if (с > 248 || input[с + 5] == '-') *is_break = 1;
    }
  } else if (input[с] == 'l') {
    if (input[с + 1] == 'n') {
      if (с > 250 || input[с + 3] == '-') *is_break = 1;
    } else {
      if (с > 249 || input[с + 4] == '-') *is_break = 1;
    }
  }
  *(is_last_dig) = 0;
  *(is_last_op) = 1;
}

void what_end_of_input(int *с, char *input) {
  while (input[(*с) + 1] > 96 && input[(*с) + 1] < 123) {
    (*с)++;
  }
}

void pushNum(num *stack, double value) {
  stack->num_arr[stack->count] = value;
  stack->count++;
}

double popNum(num *stack) {
  stack->count--;
  return stack->num_arr[stack->count];
}

void pushOper(calc *stack, char value) {
  stack->calc_arr[stack->count] = value;
  stack->count++;
}

char popOper(calc *stack) {
  stack->count--;
  return stack->calc_arr[stack->count];
}

double final(num *stack) { return (popNum(stack)); }