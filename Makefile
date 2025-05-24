all:
	gcc -o sky_racer src/*.c cli-lib/*.c -Icli-lib -lncurses

clean:
	rm -f sky_racer

open:
	./abrir_terminal.sh

run: all
	./abrir_terminal.sh
