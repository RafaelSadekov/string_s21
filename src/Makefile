CC = gcc
CFLAGS = -Wall -Wextra -Werror
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
SOURCES = s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memset.c s21_strlen.c s21_strncmp.c s21_strchr.c main_test.c
OBJ = $(SOURCES:.c=.o)
TEST_LIBS = s21_main_test.c
LIB_NAME = libs21_string.a
EXEC = test
TEST2_EXEC = main_test

all: $(LIB_NAME) $(EXEC) 

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(TEST_LIBS)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -o $@ $(TEST_LIBS) -L. -ls21_string $(CHECK_LIBS)

$(TEST2_EXEC): main_test.c $(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ main_test.c -L. -ls21_string
	rm -f $(OBJ) $(LIB_NAME)

gcov_report: clean $(EXEC)
	mkdir -p coverage
	./$(EXEC)
	./$(TEST2_EXEC)
	gcov $(GCOV_FLAGS) $(SOURCES)
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage

clean:
	rm -f $(OBJ) $(EXEC) $(TEST2_EXEC) $(LIB_NAME) *.gcda *.gcno *.gcov *.info
	rm -rf coverage