.PHONY: all clean s21_matrix_oop.a test gcov_report 

CC=g++
CFLAGS=-Wall -Werror -Wextra --std=c++17
LDFLAGS=-lgtest -lgtest_main -lpthread

GCOV_FLAGS=-lgcov -fprofile-arcs -ftest-coverage

FILES=sources/*.cpp
TEST_FILES=test/test.cpp

clean: 
	rm -f s21_gcov
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.info
	rm -rf report
	rm -f *.o
	rm -f test_exe
	rm -f s21_matrix.a

s21_matrix_oop.a: $(FILES)
	$(CC) -c $(CFLAGS) $(FILES)
	ar rcs s21_matrix.a *.o

test: s21_matrix_oop.a $(FILES) $(TEST_FILES)
	$(CC) $(CFLAGS) $(TEST_FILES) -L. s21_matrix.a -o test_exe $(LDFLAGS)
	./test_exe
	$(MAKE) clean

gcov_report: $(TEST_FILES)
	$(CC) $(CFLAGS) $(TEST_FILES) $(FILES) -o test_exe_gcov $(LDFLAGS) $(GCOV_FLAGS)
	./test_exe_gcov
	lcov --ignore-errors mismatch --ignore-errors inconsistent -t test_exe_gcov -o test.info -c -d .
	genhtml test.info -o report
	rm -rf *.gcda *.gcno *.info test_exe_gcov



all:  s21_matrix.a  test  gcov_report
