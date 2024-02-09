LIB_NAME=my_matrix.a

CC=gcc
OS=$(shell uname)
CC_FLAGS=-Wall -Werror -Wextra -std=c11
GCOV_FLAGS=-coverage -fprofile-arcs -ftest-coverage
FILES=$(shell find . -name "*.c" ! -name "*test*")
TEST_FILES=$(shell find . -name "*test.c")
ifeq ($(OS), Linux)
  LCHECK_FLAGS = -lcheck -pthread -lsubunit -lrt -lm
  OPEN=xdg-open
else
  LCHECK_FLAGS = -lcheck
  OPEN=open
endif

all: test

clean:
	rm -f *.o
	rm -f *.a
	rm -f test
	rm -f *info*
	rm -f *.gc*
	rm -rf report

test: $(LIB_NAME)
	$(CC) $(CC_FLAGS) -c $(TEST_FILES) 
	$(CC) -o test *.o $(CC_FLAGS) $(LCHECK_FLAGS) $(LIB_NAME) -g

.PHONY: $(LIB_NAME)
$(LIB_NAME):
	$(CC) $(CC_FLAGS) -c $(FILES) -g
	ar -rcs $@ *.o
	ranlib $@
	rm -rf *.o
	
style:
	clang-format -n */*.c
	clang-format -n */*.h

gcov_report: $(LIB_NAME) 
	$(CC) $(CC_FLAGS) $(FILES) $(TEST_FILES) $(LCHECK_FLAGS) $(GCOV_FLAGS)  -o info
	./info
	lcov -t "info" -o gcovreport.info -c -d .
	genhtml -o report gcovreport.info
	$(OPEN) report/index.html