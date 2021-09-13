# all: shell prototype main
all: shell main

clean:
	rm -f main.out shell.o

shell: src/shell.c
	clang -D_STRICT_ANSI -std=c17 -include src/headers/shell.h -c src/shell.c

main: main.c shell.o
	clang -D_GNU_SOURCE -std=c18 -g shell.o main.c -o main.out

# prototype: main.c
# 	clang -D_GNU_SOURCE -std=17 -c main.c
	
# main:
# 	clang -g -o main main.o shell.o