CC:=gcc
CCFLAGS:=-O2 -Wall -Werror

rush: src/rush.c src/rush_input.c
	$(CC) -o rush src/rush.c src/rush_input.c $(CCFLAGS)
all: rush

clean:
	rm -f rush.o rush_input.o rush
