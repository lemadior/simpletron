TARGET = sbc

CC = gcc

CFLAGS = -Wall -g -std=c99
# Source files
MOD1_SRC = INFIX/checking.c INFIX/convert.c INFIX/input.c

MOD2_SRC = POSTFIX/calculate.c POSTFIX/evaluate.c POSTFIX/get.c

SRCS = main.c getCommand.c stack.c showHelp.c dataManager.c load.c save.c

# Object files list (generate automatically)
MOD1_OBJS = $(MOD1_SRC:.c=.o)

MOD2_OBJS = $(MOD2_SRC:.c=.o)

# compile eash .c file separately
OBJS = $(SRCS:.c=.o)

ALL_OBJS = $(OBJS) $(MOD1_OBJS) $(MOD2_OBJS)

all: $(TARGET)

$(TARGET): $(ALL_OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(ALL_OBJS) -lm

# if sbc.h has been changed all the files should be recompiled
%.o: %.c sbc.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(ALL_OBJS) $(TARGET)

re: clean all

