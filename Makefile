CC = gcc
CFLAGS = -W -Wall -g
LDFLAGS = 
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
AOUT = main

all : $(AOUT) 

main : $(OBJS)
	 $(CC) $(LDFLAGS) -o $@ $^
%.o : %.c
	 $(CC) $(CFLAGS) -o $@ -c $<
clean :
	 @rm *.o
cleaner : clean
	@rm $(AOUT)
