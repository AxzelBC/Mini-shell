# all: shell prototype main
all: shell main

clean:
	rm -f main.out shell.o

shell: src/shell.c
	clang -D_GNU_SOURCE -D_STRICT_ANSI -fno-stack-protector -std=c18 -include src/shell.h -c src/shell.c
	# clang -D_STRICT_ANSI  -std=c17 -include include/shell.h -c src/shell.c

main: main.c shell.o
	clang -D_GNU_SOURCE -std=c18 -g shell.o main.c -o vagon_sh.out
