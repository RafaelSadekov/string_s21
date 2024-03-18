CC = gcc
CFLAGS = 
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
SOURCES = s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memset.c s21_strlen.c s21_strncmp.c s21_strchr.c add_memory.c
OBJ = $(SOURCES:.c=.o)
TEST_LIBS = s21_main_test.c
LIB_NAME = libs21_string.a
EXEC = test

LIBS=-lcheck
OPEN = open
OS := $(shell uname -s)
ifeq ($(OS),Linux)
LIBS += -lsubunit -lm -lrt -lpthread 
OPEN = xdg-open
endif

.PHONY: all check clean cppcheck test gcov_report

all: clean s21_string.a test

%.o: %.c
	$(CC) $(CFLAGS) -g -o $@ -c $< 

s21_string.a: $(OBJ)
	ar rcs $(LIB_NAME) $^

test: $(TEST_LIBS)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -o $@ $(TEST_LIBS) -L. -ls21_string $(LIBS)
	rm -f $(OBJ) $(LIB_NAME)
	./test

gcov_report: clean s21_string.a test
	mkdir -p coverage
	./$(EXEC)
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage
	$(OPEN) coverage/index.html
	rm -rf *.g* gcov_rep* coverage.info

rebuild: clean all

clean:
	rm -f $(OBJ) $(EXEC) $(LIB_NAME) *.gcda *.gcno *.gcov *.info
	rm -rf coverage