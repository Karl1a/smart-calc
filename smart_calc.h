#ifndef SRC_SMART_CALC_H_
#define SRC_SMART_CALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 1
#define CORRECT 0
#define true 1
#define false 0

enum priority {
  bascket = 0,
  X = 2,
  plus = 1,
  minus = 1,
  modul = 2,
  divide = 3,
  mult = 3,
  power = 4,
  trigonom = 5,
};

// input
void what_end_of_input(int *c, char *input);
void correct_trigonom(int *is_brake, int c, int *is_last_dig, int *is_last_op,
                      char *input);
int is_bascket_corr(int bracket_cnt, int *is_brake);
int check(char *input);
char *input(char *s, char *c);

typedef struct num {
  double num_arr[256];
  int count;
} num;

typedef struct calc {
  char calc_arr[256];
  int count;
} calc;

// infix
double parser(char *input, double x);
int is_operand(int c, char *input);
int is_triginom(int c, char *input);

// stack
void pushNum(num *stack, double value);
double popNum(num *stack);
void pushOper(calc *stack, char value);
char popOper(calc *stack);
char peak(calc *stack);
double final(num *stack);
// calc
void clear_str(char *str);
double algorithm(char *input, double x);
double count_postfix(char *str);
void result(num *number_stack, calc *oper_stack);
void what_end_num(num *stack, int *c, char *input);
void findPriority(calc *oper_stack, char *str, int c, num *number_stack);
void readTrigonom(calc *oper_stack, char *str, int c);
void operation_compl(double up, num *number_stack, char c);
int getPriority(char c);
void fill_field(int arr[25][80], char *str, float res);
void output(int arr[25][80]);
#endif  // SRC_SMART_CALC_H_
