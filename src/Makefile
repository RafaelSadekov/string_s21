CC = gcc
CFLAGS = -Wall -Wextra -Werror
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
SOURCES = s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memset.c s21_strlen.c s21_strncmp.c s21_strchr.c main_test.c
OBJ = $(SOURCES:.c=.o)
TEST_LIBS = s21_main_test.c
LIB_NAME = libs21_string.a
EXEC = test
TEST2_EXEC = main_test

OS=$(shell uname -s)

all: clean s21_string.a test gcov_report

s21_string.a: $(OBJ)
	ar rcs $(LIB_NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_LIBS)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -o $@ $(TEST_LIBS) -L. -ls21_string -lcheck -lsubunit -lm
	rm -f $(OBJ) $(LIB_NAME)
	./test

testmac: $(LIB_EXEC) $(TEST_LIBS)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -o $@ $(TEST_LIBS) -L. -ls21_string -lcheck
	rm -f $(OBJ) $(LIB_NAME)
	./testmac

$(TEST2_EXEC): main_test.c $(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ main_test.c -L. -ls21_string
	rm -f $(OBJ) $(LIB_NAME)

gcov_report: clean $(LIB_EXEC) $(EXEC) 
	mkdir -p coverage
	./$(EXEC)
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage
	open coverage/index.html
	rm -rf *.g* gcov_rep* coverage.info

gcov_report_mac: clean $(LIB_EXEC) testmac
	mkdir -p coverage
	./testmac
	lcov --capture --directory . --output-file test.info
	genhtml test.info --output-directory coverage
	open coverage/index.html
	rm -rf *.g* gcov_rep* coverage.info

rebuild: clean all

clean:
	rm -f $(OBJ) $(EXEC) $(TEST2_EXEC) $(LIB_NAME) *.gcda *.gcno *.gcov *.info
	rm -rf coverage