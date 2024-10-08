BUILD_DIR = build
CC = gcc

CFLAGS = -Wextra -Wall -g -I"/usr/include" -I"./include"

LDLIBS = -L"/usr/lib/x86_64-linux-gnu/" -lm

SRCS = src/libpds.c

OBJS = $(SRCS:.c=.o)

EXE = $(BUILD_DIR)/libpds

all: $(EXE)

# Rule to build the target executable
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*

# ------- Tests -------

test:
	$(CC) $(CFLAGS) tests/test.c src/libpds.c -o build/test