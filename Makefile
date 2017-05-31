CC=g++
CFLAGS := -g -Wall -std=c++11
SRCS = solver.cpp solver_class.cpp brute.cpp
OBJS = $(SRCS:.cpp=.o)
MAIN = solver

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)
