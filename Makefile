TARGET = evaluate

CC = gcc

CFLAGS = -Wall -g -std=c99

SRCS = main.c input.c evaluate.c calculate.c get.c pop.c push.c print.c empty.c

# compile eash .c file separately
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# if common.h has been changed all the files should be recompiled
%.o: %.c evaluate.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

re: clean all

