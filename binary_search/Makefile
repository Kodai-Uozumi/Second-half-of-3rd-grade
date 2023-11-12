SRC=binary_search.c
OBJS=$(SRC:.c=.o)
TARGET=main.out
# TESTFILE=test/test1.txt

CC=gcc
LN=$(CC)
RM=rm

CFLAGS=-Wall -O0 -g
LDFLAGS=

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(LN) $(OBJS) $(LDFLAGS) -o $@

.PHONY : clean
clean:
	$(RM) $(OBJS) $(TARGET)

exec:
	./$(TARGET)