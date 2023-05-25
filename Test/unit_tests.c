
#include <check.h>

#include "../smart_calc.h"
#define ACCURACY 1e-6

START_TEST(calc_test_1) {
  char input_string[256] = "(5+5)*-2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, -20.000000, ACCURACY);
}

START_TEST(calc_test_2) {
  char input_string[256] = "(10+10*2)/-3";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq(res, -10.000000);
}

START_TEST(calc_test_3) {
  char input_string[256] = "2.0/(3.0+2.0)*5.0";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 2.000000, ACCURACY);
}

START_TEST(calc_test_4) {
  char input_string[256] = "10.0+10.0*10.0";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 110.000000, ACCURACY);
}

START_TEST(calc_test_5) {
  char input_string[256] = "-5+-4*-2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 3.000000, ACCURACY);
}
//
START_TEST(calc_test_6) {
  char input_string[256] = "-5.0%-3.0";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq(res, -2.000000);
}

START_TEST(calc_test_7) {
  char input_string[256] = "1.0/2.0*(2.0-1.0)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq(res, 0.500000);
}

START_TEST(calc_test_8) {
  char input_string[256] = "1.1+2.0+(3.0*4.0)+(5.0+6.8)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq(res, 26.900000);
}

START_TEST(calc_test_9) {
  char input_string[256] = "1.10+2.0+(3.0-5.5)*(1.5-6.5)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq(res, 15.600000);
}

START_TEST(calc_test_10) {
  char input_string[256] = "6.6-1.1-2.2-3.3-4.4-5.5";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq(res, -9.900000);
}

START_TEST(calc_test_11) {
  char input_string[256] = "1.1-2.2-3.3-4.4-5.5+6.6";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, -7.7000000, ACCURACY);
}

START_TEST(calc_test_12) {
  char input_string[256] = "-1.1*5";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq(res, -5.5);
}

START_TEST(calc_test_13) {
  char input_string[256] = "2^2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq(res, 4.000000);
}

START_TEST(calc_test_14) {
  char input_string[256] = "5^3";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq(res, 125.000000);
}

START_TEST(calc_test_16) {
  char input_string[256] = "(2^2)^3";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq(res, 64.000000);
}

START_TEST(calc_test_17) {
  char input_string[256] = "-5+3*2^2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq(res, 7.000000);
}

START_TEST(calc_test_19) {
  char input_string[256] = "5%-1.5";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq(res, 0.500000);
}

START_TEST(calc_test_20) {
  char input_string[256] = "(5%-1.5*4)^2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq(res, 25.000000);
}

START_TEST(calc_test_21) {
  char input_string[256] = "sin(30)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, -0.988032, ACCURACY);
}

START_TEST(calc_test_22) {
  char input_string[256] = "sin(45)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.850904, ACCURACY);
}

START_TEST(calc_test_23) {
  char input_string[256] = "sin(60)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, -0.304811, ACCURACY);
}

START_TEST(calc_test_24) {
  char input_string[256] = "sin(90)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.893997, ACCURACY);
}

START_TEST(calc_test_25) {
  char input_string[256] = "sin(120)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.580611, ACCURACY);
}

START_TEST(calc_test_26) {
  char input_string[256] = "sin(180)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, -0.801153, ACCURACY);
}

START_TEST(calc_test_27) {
  char input_string[256] = "sin(270)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, -0.176046, ACCURACY);
}

START_TEST(calc_test_28) {
  char input_string[256] = "sin(360)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.958916, ACCURACY);
}

START_TEST(calc_test_29) {
  char input_string[256] = "sin(0)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.000000, ACCURACY);
}

START_TEST(calc_test_30) {
  char input_string[256] = "cos(30)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.154251, ACCURACY);
}

START_TEST(calc_test_31) {
  char input_string[256] = "cos(45)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.525322, ACCURACY);
}

START_TEST(calc_test_32) {
  char input_string[256] = "cos(90)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, -0.448074, ACCURACY);
}

START_TEST(calc_test_33) {
  char input_string[256] = "cos(120)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.814181, ACCURACY);
}

START_TEST(calc_test_34) {
  char input_string[256] = "cos(180)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, -0.598460, ACCURACY);
}

START_TEST(calc_test_35) {
  char input_string[256] = "cos(270)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.984382, ACCURACY);
}

START_TEST(calc_test_36) {
  char input_string[256] = "cos(360)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, -0.283691, ACCURACY);
}

START_TEST(calc_test_37) {
  char input_string[256] = "cos(0)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1.000000, ACCURACY);
}

START_TEST(calc_test_38) {
  char input_string[256] = "tan(90)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, -1.995200, ACCURACY);
}

START_TEST(calc_test_40) {
  char input_string[256] = "(sin(45)+cos(30)+tan(45)+tan(90))*2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1.25946, ACCURACY);
}

START_TEST(calc_test_41) {
  char input_string[256] = "tan(180)^2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1.792091, ACCURACY);
}

START_TEST(calc_test_43) {
  char input_string[256] = "asin(0.5)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.523598, ACCURACY);
}

START_TEST(calc_test_44) {
  char input_string[256] = "acos(0.5)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1.047198, ACCURACY);
}

START_TEST(calc_test_45) {
  char input_string[256] = "acos(1)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.000000, ACCURACY);
}

START_TEST(calc_test_46) {
  char input_string[256] = "atan(0)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.000000, ACCURACY);
}

START_TEST(calc_test_47) {
  char input_string[256] = "atan(1)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.785398, ACCURACY);
}

START_TEST(calc_test_49) {
  char input_string[256] = "ln(5)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1.609438, ACCURACY);
}

START_TEST(calc_test_50) {
  char input_string[256] = "-5.0%-3.0";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, -2.000000, ACCURACY);
}

START_TEST(calc_test_51) {
  char input_string[256] = "log(10)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1.000000, ACCURACY);
}

START_TEST(calc_test_52) {
  char input_string[256] = "1.0/2.0*(2.0-1.0)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.500000, ACCURACY);
}

START_TEST(calc_test_53) {
  char input_string[256] = "1.1+2.0+(3.0*4.0)+(5.0+6.8)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 26.900000, ACCURACY);
}

START_TEST(calc_test_54) {
  char input_string[256] = "10^10";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 10000000000.000000, ACCURACY);
}

START_TEST(calc_test_55) {
  char input_string[256] = "10000000000 - 10000000000";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.000000, ACCURACY);
}

START_TEST(calc_test_57) {
  char input_string[256] =
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 128.000000, ACCURACY);
}

START_TEST(calc_test_58) {
  char input_string[256] =
      "1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*"
      "1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*"
      "1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*"
      "1*1*1*1*1*1*1*1*1*1*1*1*1*1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1.000000, ACCURACY);
}

START_TEST(calc_test_60) {
  char input_string[256] = "1+1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 2.000000, ACCURACY);
}

START_TEST(calc_test_61) {
  char input_string[256] = "(1+1)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 2.000000, ACCURACY);
}

START_TEST(calc_test_62) {
  char input_string[256] = "(1+1)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 2.000000, ACCURACY);
}

START_TEST(calc_test_63) {
  char input_string[256] = "(1+1)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 2.000000, ACCURACY);
}

START_TEST(calc_test_64) {
  char input_string[256] = "(1+1)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 2.000000, ACCURACY);
}

// START_TEST(calc_test_65) {
//   char input_string[256] = "((((1)+(1))))";
//   double res = algorithm(input_string, 0);
//   ck_assert_double_eq_tol(res, 2.000000, ACCURACY);
// }

START_TEST(calc_test_66) {
  char input_string[256] = "(5*9)-(2+(3-(2/1)+35))";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, (5 * 9) - (2 + (3 - (2 / 1) + 35)), ACCURACY);
}

START_TEST(calc_test_67) {
  char input_string[256] = "(";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_68) {
  char input_string[256] = "()";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_69) {
  char input_string[256] = "1+)3";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_70) {
  char input_string[256] = "18/9.3)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0, ACCURACY);
}

START_TEST(calc_test_72) {
  char input_string[256] = "1.000002+5";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1.000002 + 5, ACCURACY);
}

START_TEST(calc_test_73) {
  char input_string[256] = "1.000002+5+9+6";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1.000002 + 5 + 9 + 6, ACCURACY);
}

//?
START_TEST(calc_test_74) {
  char input_string[256] = "1.54837495+1.34521343+";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_75) {
  char input_string[256] = "(1.54837495+1.34521343)+";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_76) {
  char input_string[256] = "1.54837495+1.34521343+";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_77) {
  char input_string[256] = "1.54837495+1.34521343+";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_78) {
  char input_string[256] = "1.54837495+1.345213431+(-(5)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_79) {
  char input_string[256] = "+";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_80) {
  char input_string[256] = "1-1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_81) {
  char input_string[256] = "1-0";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1 - 0, ACCURACY);
}

START_TEST(calc_test_82) {
  char input_string[256] = "1-0.000001";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1 - 0.000001, ACCURACY);
}

START_TEST(calc_test_83) {
  char input_string[256] = "1-0.000001-";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_84) {
  char input_string[256] = "-";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_85) {
  char input_string[256] = "156156*3";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 156156 * 3, ACCURACY);
}

START_TEST(calc_test_86) {
  char input_string[256] = "156156*3*3*0.1*0.1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 156156 * 3 * 3 * 0.1 * 0.1, ACCURACY);
}

START_TEST(calc_test_87) {
  char input_string[256] = "156156*3*3*0.1*0.1*";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_88) {
  char input_string[256] = "*156156*3*3*0.1*0.1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_89) {
  char input_string[256] = "156156*3*3*0.1*0.1*()";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_90) {
  char input_string[256] = "156/2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 156 / 2, ACCURACY);
}

START_TEST(calc_test_91) {
  char input_string[256] = "512/2/2/2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 512 / 2 / 2 / 2, ACCURACY);
}

START_TEST(calc_test_92) {
  char input_string[256] = "512/2/2/2/0.5";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 512 / 2 / 2 / 2 / 0.5, ACCURACY);
}

START_TEST(calc_test_94) {
  char input_string[256] = "1/0.5/";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_98) {
  char input_string[256] = "-2+12";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 10, ACCURACY);
}

START_TEST(calc_test_99) {
  char input_string[256] = "(-2)^2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 4, ACCURACY);
}

START_TEST(calc_test_100) {
  char input_string[256] = "ln(9.980000^123)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 282.9717201, ACCURACY);
}

START_TEST(calc_test_101) {
  char input_string[256] = "2^2^";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_102) {
  char input_string[256] = "^2^2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_103) {
  char input_string[256] = "2^^2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_104) {
  char input_string[256] = "3.4%3";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.4, ACCURACY);
}

START_TEST(calc_test_106) {
  char input_string[256] = "% 0";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_107) {
  char input_string[256] = "%1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_108) {
  char input_string[256] = "1%";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_110) {
  char input_string[256] = "1% %3";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_111) {
  char input_string[256] = "21513+1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 21514, ACCURACY);
}

START_TEST(calc_test_112) {
  char input_string[256] = "2/2+(1)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 2, ACCURACY);
}

START_TEST(calc_test_113) {
  char input_string[256] = "1+(1)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 2, ACCURACY);
}

START_TEST(calc_test_114) {
  char input_string[256] = "1+(54*2+1)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 110, ACCURACY);
}

START_TEST(calc_test_115) {
  char input_string[256] = "1+1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 2.0, ACCURACY);
}

START_TEST(calc_test_116) {
  char input_string[256] = "121/121*(369%2)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1.0, ACCURACY);
}

START_TEST(calc_test_117) {
  char input_string[256] = "216/31+13*24";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 318.967742, ACCURACY);
}

START_TEST(calc_test_118) {
  char input_string[256] = "1.54837495*5.34521343";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 8.2763946, ACCURACY);
}

START_TEST(calc_test_119) {
  char input_string[256] = "1.54837495+1.34521343";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 2.893588, ACCURACY);
}

START_TEST(calc_test_120) {
  char input_string[256] = "2125/613+(74*1.34521343)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 103.012351, ACCURACY);
}

START_TEST(calc_test_121) {
  char input_string[256] = "-1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, -1, ACCURACY);
}

START_TEST(calc_test_122) {
  char input_string[256] = "-1+21";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 20, ACCURACY);
}

START_TEST(calc_test_123) {
  char input_string[256] = "1-(1)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0, ACCURACY);
}

START_TEST(calc_test_127) {
  char input_string[256] = "-1--1-1--1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_131) {
  char input_string[256] = "1.54837495+1.34521343";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1.54837495 + 1.34521343, ACCURACY);
}

START_TEST(calc_test_133) {
  char input_string[256] = "sin(90)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, sin(90), ACCURACY);
}

START_TEST(calc_test_134) {
  char input_string[256] = "cos(90)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, cos(90), ACCURACY);
}

START_TEST(calc_test_135) {
  char input_string[256] = "tan(90)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, tan(90), ACCURACY);
}

START_TEST(calc_test_136) {
  char input_string[256] = "sqrt(90)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, sqrt(90), ACCURACY);
}

START_TEST(calc_test_137) {
  char input_string[256] = "ln(90)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, log(90), ACCURACY);
}

START_TEST(calc_test_138) {
  char input_string[256] = "log(90)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, log10(90), ACCURACY);
}

START_TEST(calc_test_139) {
  char input_string[256] = "acos(0.5)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, acos(0.5), ACCURACY);
}

START_TEST(calc_test_140) {
  char input_string[256] = "asin(0.5)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, asin(0.5), ACCURACY);
}

START_TEST(calc_test_141) {
  char input_string[256] = "atan(90)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, atan(90), ACCURACY);
}

START_TEST(calc_test_143) {
  char input_string[256] = "-1+-2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, -3.0, ACCURACY);
}

START_TEST(calc_test_147) {
  char input_string[256] = "(-3)*(-3.141592-(7*(-7))";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0, ACCURACY);
}

START_TEST(calc_test_148) {
  char input_string[256] = "sin(sin(sin(sin(sin(90)))))";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, sin(sin(sin(sin(sin(90))))), ACCURACY);
}

START_TEST(calc_test_150) {
  char input_string[256] = "(123)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, (123), ACCURACY);
}

START_TEST(calc_test_151) {
  char input_string[256] = "*1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_152) {
  char input_string[256] = "1(";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_153) {
  char input_string[256] = "1)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_154) {
  char input_string[256] = "asin";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_155) {
  char input_string[256] = "1.3.4";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_157) {
  char input_string[256] = "sqrt4";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 2.0, ACCURACY);
}

START_TEST(calc_test_158) {
  char input_string[256] = "-*3";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_159) {
  char input_string[256] = "5%4";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1, ACCURACY);
}

START_TEST(calc_test_161) {
  char input_string[256] = "123-34-";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_163) {
  char input_string[256] = "%";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_164) {
  char input_string[256] = "sin(2)+1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, sin(2) + 1, ACCURACY);
}

START_TEST(calc_test_165) {
  char input_string[256] = "cos(2)+2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, cos(2) + 2, ACCURACY);
}

START_TEST(calc_test_167) {
  char input_string[256] = "acos(0.3)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, acos(0.3), ACCURACY);
}

START_TEST(calc_test_168) {
  char input_string[256] = "ln(ln(2))";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, -0.366513, ACCURACY);
}

START_TEST(calc_test_169) {
  char input_string[256] = "sqrt(8)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 2.828427, ACCURACY);
}

START_TEST(calc_test_170) {
  char input_string[256] = "1/(-3-4+7)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_171) {
  char input_string[256] = "1+tan(1.5707963267948)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1 + tan(1.5707963267948), ACCURACY);
}

START_TEST(calc_test_185) {
  char input_string[256] = "sin(5+3";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_186) {
  char input_string[256] = "(1+5)-2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 4.0, ACCURACY);
}

START_TEST(calc_test_187) {
  char input_string[256] = "cos(1*2)-1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, -1.4161468, ACCURACY);
}

START_TEST(calc_test_188) {
  char input_string[256] = "(1+2)*4+3";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 15.0, ACCURACY);
}

START_TEST(calc_test_189) {
  char input_string[256] = "2/(3+2)*5";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 2.0, ACCURACY);
}

START_TEST(calc_test_190) {
  char input_string[256] = "2/4-1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, -0.5, ACCURACY);
}

START_TEST(calc_test_191) {
  char input_string[256] = "2-4/1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 2 - 4 / 1, ACCURACY);
}

START_TEST(calc_test_192) {
  char input_string[256] = "2*4/1";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 2 * 4 / 1, ACCURACY);
}

START_TEST(calc_test_193) {
  char input_string[256] = "atan(5)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, atan(5), ACCURACY);
}

START_TEST(calc_test_195) {
  char input_string[256] = "log(55dududu";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_196) {
  char input_string[256] = "1%32";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1.0, ACCURACY);
}

START_TEST(calc_test_197) {
  char input_string[256] = "4+5/3-sqrt(14)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 1.92500927, ACCURACY);
}

START_TEST(calc_test_198) {
  char input_string[256] = "98^6";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 885842380864, ACCURACY);
}

START_TEST(calc_test_199) {
  char input_string[256] = "17/4+(14/2*(3-1^4))";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 18.25, ACCURACY);
}

START_TEST(calc_test_200) {
  char input_string[256] = "17/4+(14/2*(3-1^4)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_201) {
  char input_string[256] = "17/4(14/2*(3-1^4)";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_202) {
  char input_string[8] = "24+1/2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 24.5, ACCURACY);
}

START_TEST(calc_test_203) {
  char input_string[8] = "2)+2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

START_TEST(calc_test_204) {
  char input_string[8] = "2+2";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 4.0, ACCURACY);
}

START_TEST(calc_test_205) {
  char input_string[8] = "5*x";
  double res = algorithm(input_string, 30);
  ck_assert_double_eq_tol(res, 150.0, ACCURACY);
}

START_TEST(calc_test_206) {
  char input_string[8] = "325";
  double res = algorithm(input_string, 0);
  ck_assert_double_eq_tol(res, 325, ACCURACY);
}

START_TEST(calc_test_207) {
  char input_string[8] = "x+1";
  double res = algorithm(input_string, 2.0);
  ck_assert_double_eq_tol(res, 3.0, ACCURACY);
}

START_TEST(calc_test_208) {
  char input_string[8] = "x^2";
  double res = algorithm(input_string, 9.0);
  ck_assert_double_eq_tol(res, 81.0, ACCURACY);
}

START_TEST(calc_test_209) {
  char input_string[8] = "sin(x)";
  double res = algorithm(input_string, 1.0);
  ck_assert_double_eq_tol(res, 0.841471, ACCURACY);
}

START_TEST(calc_test_210) {
  char input_string[8] = "x-x";
  double res = algorithm(input_string, 400.0);
  ck_assert_double_eq_tol(res, 0.0, ACCURACY);
}

int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  double res;

  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, calc_test_1);
  tcase_add_test(tc1_1, calc_test_2);
  tcase_add_test(tc1_1, calc_test_3);
  tcase_add_test(tc1_1, calc_test_4);
  tcase_add_test(tc1_1, calc_test_5);
  tcase_add_test(tc1_1, calc_test_6);
  tcase_add_test(tc1_1, calc_test_7);
  tcase_add_test(tc1_1, calc_test_8);
  tcase_add_test(tc1_1, calc_test_9);
  tcase_add_test(tc1_1, calc_test_10);
  tcase_add_test(tc1_1, calc_test_11);
  tcase_add_test(tc1_1, calc_test_12);
  tcase_add_test(tc1_1, calc_test_13);
  tcase_add_test(tc1_1, calc_test_14);
  tcase_add_test(tc1_1, calc_test_16);
  tcase_add_test(tc1_1, calc_test_17);
  tcase_add_test(tc1_1, calc_test_19);
  tcase_add_test(tc1_1, calc_test_20);
  tcase_add_test(tc1_1, calc_test_21);
  tcase_add_test(tc1_1, calc_test_22);
  tcase_add_test(tc1_1, calc_test_23);
  tcase_add_test(tc1_1, calc_test_24);
  tcase_add_test(tc1_1, calc_test_25);
  tcase_add_test(tc1_1, calc_test_26);
  tcase_add_test(tc1_1, calc_test_27);
  tcase_add_test(tc1_1, calc_test_28);
  tcase_add_test(tc1_1, calc_test_29);
  tcase_add_test(tc1_1, calc_test_30);
  tcase_add_test(tc1_1, calc_test_31);
  tcase_add_test(tc1_1, calc_test_32);
  tcase_add_test(tc1_1, calc_test_33);
  tcase_add_test(tc1_1, calc_test_34);
  tcase_add_test(tc1_1, calc_test_35);
  tcase_add_test(tc1_1, calc_test_36);
  tcase_add_test(tc1_1, calc_test_37);
  tcase_add_test(tc1_1, calc_test_38);
  tcase_add_test(tc1_1, calc_test_40);
  tcase_add_test(tc1_1, calc_test_41);
  tcase_add_test(tc1_1, calc_test_43);
  tcase_add_test(tc1_1, calc_test_44);
  tcase_add_test(tc1_1, calc_test_45);
  tcase_add_test(tc1_1, calc_test_46);
  tcase_add_test(tc1_1, calc_test_47);
  tcase_add_test(tc1_1, calc_test_49);
  tcase_add_test(tc1_1, calc_test_50);
  tcase_add_test(tc1_1, calc_test_51);
  tcase_add_test(tc1_1, calc_test_52);
  tcase_add_test(tc1_1, calc_test_53);
  tcase_add_test(tc1_1, calc_test_54);
  tcase_add_test(tc1_1, calc_test_55);
  tcase_add_test(tc1_1, calc_test_57);
  tcase_add_test(tc1_1, calc_test_58);
  tcase_add_test(tc1_1, calc_test_60);
  tcase_add_test(tc1_1, calc_test_61);
  tcase_add_test(tc1_1, calc_test_62);
  tcase_add_test(tc1_1, calc_test_63);
  tcase_add_test(tc1_1, calc_test_64);
  // tcase_add_test(tc1_1, calc_test_65);
  tcase_add_test(tc1_1, calc_test_66);
  tcase_add_test(tc1_1, calc_test_67);
  tcase_add_test(tc1_1, calc_test_68);
  tcase_add_test(tc1_1, calc_test_69);
  tcase_add_test(tc1_1, calc_test_70);
  tcase_add_test(tc1_1, calc_test_72);
  tcase_add_test(tc1_1, calc_test_73);
  tcase_add_test(tc1_1, calc_test_74);
  tcase_add_test(tc1_1, calc_test_75);
  tcase_add_test(tc1_1, calc_test_76);
  tcase_add_test(tc1_1, calc_test_77);
  tcase_add_test(tc1_1, calc_test_78);
  tcase_add_test(tc1_1, calc_test_79);
  tcase_add_test(tc1_1, calc_test_80);
  tcase_add_test(tc1_1, calc_test_81);
  tcase_add_test(tc1_1, calc_test_82);
  tcase_add_test(tc1_1, calc_test_83);
  tcase_add_test(tc1_1, calc_test_84);
  tcase_add_test(tc1_1, calc_test_85);
  tcase_add_test(tc1_1, calc_test_86);
  tcase_add_test(tc1_1, calc_test_87);
  tcase_add_test(tc1_1, calc_test_88);
  tcase_add_test(tc1_1, calc_test_89);
  tcase_add_test(tc1_1, calc_test_90);
  tcase_add_test(tc1_1, calc_test_91);
  tcase_add_test(tc1_1, calc_test_92);
  tcase_add_test(tc1_1, calc_test_94);
  tcase_add_test(tc1_1, calc_test_98);
  tcase_add_test(tc1_1, calc_test_99);
  tcase_add_test(tc1_1, calc_test_100);
  tcase_add_test(tc1_1, calc_test_101);
  tcase_add_test(tc1_1, calc_test_102);
  tcase_add_test(tc1_1, calc_test_103);
  tcase_add_test(tc1_1, calc_test_104);
  tcase_add_test(tc1_1, calc_test_106);
  tcase_add_test(tc1_1, calc_test_107);
  tcase_add_test(tc1_1, calc_test_108);
  tcase_add_test(tc1_1, calc_test_110);
  tcase_add_test(tc1_1, calc_test_111);
  tcase_add_test(tc1_1, calc_test_112);
  tcase_add_test(tc1_1, calc_test_113);
  tcase_add_test(tc1_1, calc_test_114);
  tcase_add_test(tc1_1, calc_test_115);
  tcase_add_test(tc1_1, calc_test_116);
  tcase_add_test(tc1_1, calc_test_117);
  tcase_add_test(tc1_1, calc_test_118);
  tcase_add_test(tc1_1, calc_test_119);
  tcase_add_test(tc1_1, calc_test_120);
  tcase_add_test(tc1_1, calc_test_121);
  tcase_add_test(tc1_1, calc_test_122);
  tcase_add_test(tc1_1, calc_test_123);
  tcase_add_test(tc1_1, calc_test_127);
  tcase_add_test(tc1_1, calc_test_131);
  tcase_add_test(tc1_1, calc_test_133);
  tcase_add_test(tc1_1, calc_test_134);
  tcase_add_test(tc1_1, calc_test_135);
  tcase_add_test(tc1_1, calc_test_136);
  tcase_add_test(tc1_1, calc_test_137);
  tcase_add_test(tc1_1, calc_test_138);
  tcase_add_test(tc1_1, calc_test_139);
  tcase_add_test(tc1_1, calc_test_140);
  tcase_add_test(tc1_1, calc_test_141);
  tcase_add_test(tc1_1, calc_test_143);
  tcase_add_test(tc1_1, calc_test_147);
  tcase_add_test(tc1_1, calc_test_148);
  tcase_add_test(tc1_1, calc_test_150);
  tcase_add_test(tc1_1, calc_test_151);
  tcase_add_test(tc1_1, calc_test_152);
  tcase_add_test(tc1_1, calc_test_153);
  tcase_add_test(tc1_1, calc_test_154);
  tcase_add_test(tc1_1, calc_test_155);
  tcase_add_test(tc1_1, calc_test_157);
  tcase_add_test(tc1_1, calc_test_158);
  tcase_add_test(tc1_1, calc_test_159);
  tcase_add_test(tc1_1, calc_test_161);
  tcase_add_test(tc1_1, calc_test_163);
  tcase_add_test(tc1_1, calc_test_164);
  tcase_add_test(tc1_1, calc_test_165);
  tcase_add_test(tc1_1, calc_test_167);
  tcase_add_test(tc1_1, calc_test_168);
  tcase_add_test(tc1_1, calc_test_169);
  tcase_add_test(tc1_1, calc_test_170);
  tcase_add_test(tc1_1, calc_test_171);
  tcase_add_test(tc1_1, calc_test_185);
  tcase_add_test(tc1_1, calc_test_186);
  tcase_add_test(tc1_1, calc_test_187);
  tcase_add_test(tc1_1, calc_test_188);
  tcase_add_test(tc1_1, calc_test_189);
  tcase_add_test(tc1_1, calc_test_190);
  tcase_add_test(tc1_1, calc_test_191);
  tcase_add_test(tc1_1, calc_test_192);
  tcase_add_test(tc1_1, calc_test_193);
  tcase_add_test(tc1_1, calc_test_195);
  tcase_add_test(tc1_1, calc_test_196);
  tcase_add_test(tc1_1, calc_test_197);
  tcase_add_test(tc1_1, calc_test_198);
  tcase_add_test(tc1_1, calc_test_199);
  tcase_add_test(tc1_1, calc_test_200);
  tcase_add_test(tc1_1, calc_test_201);
  tcase_add_test(tc1_1, calc_test_202);
  tcase_add_test(tc1_1, calc_test_203);
  tcase_add_test(tc1_1, calc_test_204);
  tcase_add_test(tc1_1, calc_test_205);
  tcase_add_test(tc1_1, calc_test_206);
  tcase_add_test(tc1_1, calc_test_207);
  tcase_add_test(tc1_1, calc_test_208);
  tcase_add_test(tc1_1, calc_test_209);
  tcase_add_test(tc1_1, calc_test_210);
  srunner_run_all(sr, CK_ENV);
  res = srunner_ntests_failed(sr);
  srunner_free(sr);
  return res == 0 ? 0 : 1;
}