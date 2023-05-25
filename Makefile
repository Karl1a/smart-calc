.PHONY: all build static install uninstall rebuild dist test gcov_report clean
CC=gcc
CFLAGS= -Wall -Wextra -Werror 
FLAGS_TEST_LIBS = -lcheck -lm -lpthread

SRC=calc.c

NAME=smart_calc.a
OBJ=$(patsubst %.c, %.o, $(SRC))
OS = $(shell uname)

all: build static

build:
	$(CC) $(CFLAGS) -c $(SRC)

static:
	ar rc smart_calc.a $(OBJ)
	ranlib smart_calc.a

test: clean 
	gcc calc.c Test/unit_tests.c -o test_1 -lcheck
	./test_1

gcov_report: all
	$(CC) $(CFLAGS) --coverage Test/unit_tests.c $(SRC) $(NAME) $(FLAGS_TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html


install:
	@make clean
	@cd View && qmake && make && make clean && rm Makefile && mv test_3.app $(HOME)/Desktop/

uninstall:
	rm -rf build*

dvi:
	open README.txt

dist: install
	rm -rf Dist_SmartCalc/
	mkdir Dist_SmartCalc/
	mkdir Dist_SmartCalc/src
	mv ./build/SmartCalc.app Dist_SmartCalc/src/
	tar cvzf Dist_SmartCalc.tgz Dist_SmartCalc/
	rm -rf Dist_SmartCalc/
	rmdir build

clean:
	@/bin/rm -rf **/*.o *.a build *.gcno *gcda report *.info main *.dSYM *.out gcov_report $(EXE) View/.qmake.stash View/test_3.pro.user View/.qtc_clangd build-test_3-Desktop_x86_darwin_generic_mach_o_64bit-Debug ../Archive_test_3.tar.gz


rebuild: clean all
	
style:
	clang-format -style=Google -n *.c *.h *.cpp