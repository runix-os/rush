CC:=gcc
CCFLAGS:=-O2 -Wall -Werror

rush: src/rush.c
	$(CC) -o rush src/rush.c $(CCFLAGS)
all: rush

clean:
	rm -f rush.o rush
