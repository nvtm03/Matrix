CC=gcc
LC = lcov
CFLAGS = -c -Wall -Wextra -Werror -std=c11
AFLAGS = ar rc
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LCOVFLAGS = -c -d . -o
LIBSOURCES = $(wildcard s21_*.c)
TESTSOURSES =  tests.c
SOURCES = $(TESTSOURSES) $(LIBSOURCES)
LIBOBJECTS = $(patsubst %.c, %.o, $(LIBSOURCES))
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
EXECUTABLE = test
PROJECT_NAME = s21_matrix

ifeq ($(shell uname -s),Linux)
OPEN_CMD = xdg-open
OFLAGS =  -lcheck -lsubunit -lm -lrt -lpthread -lgcov -o 
endif
ifeq ($(shell uname -s),Darwin) # MacOS
OPEN_CMD = open
OFLAGS = -lcheck -lm -lpthread -lgcov -o
endif
all:  clean s21_matrix.a 

.c.o:
	$(CC) $(CFLAGS) $< $(GCOVFLAGS) -o $@

test: $(OBJECTS)
	$(CC) $(OBJECTS) $(OFLAGS) $@
	./$(EXECUTABLE)
	@rm -rf *.o

retest: clean test

s21_matrix.a:
	$(CC) $(CFLAGS) $(LIBSOURCES)
	$(AFLAGS) s21_matrix.a  $(LIBOBJECTS)
	rm -rf *.o

gcov_report: test
	$(LC) $(LCOVFLAGS) report.info
	genhtml report.info
	$(OPEN_CMD) ./index.html

check:
	clang-format --style=Google -n $(SOURCES) *.h

valgrind: test
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./$(EXECUTABLE)
	cat RESULT_VALGRIND.txt

clean:
	@-rm -rf src */*.o  *.png *.o 
	@-rm -rf *.gcno *.gcda *.gch *.info *.html *.a *.css
	@-rm -rf */*.gcno */*.gcda */*.gch */*.info */*.html */*.a */*.css
	@-rm ./test
	@-rm -rf ./usr
	@echo clear
rebuild: clean all

