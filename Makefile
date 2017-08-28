CC = cc 
OPT = -O1
CFLAGS = -Wall -std=gnu99 -fstrict-aliasing -fopenmp $(OPT)
LDFLAGS = -Wall
LDLIBS = -fopenmp

targets = prog-hello prog-pi prog-pi2 prog-pi3 prog-pi4
objects = hello.o pi.o pi2.o  pi3.o pi4.o

.PHONY : default
default : all

.PHONY : all
all : clean $(targets)

prog-hello : hello.o
	$(CC) -o $@ $^ $(LDLIBS)
prog-pi : pi.o
	$(CC) -o $@ $^ $(LDLIBS)
prog-pi2 : pi2.o
	$(CC) -o $@ $^ $(LDLIBS)
prog-pi3 : pi3.o
	$(CC) -o $@ $^ $(LDLIBS)
prog-pi4 : pi4.o
	$(CC) -o $@ $^ $(LDLIBS)

%.o : %.c
	$(CC) -c $(CFLAGS) $<

.PHONY : clean
clean:
	rm -f $(targets) $(objects)