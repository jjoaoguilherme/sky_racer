all:
	gcc -o sky_racer src/*.c cli-lib/*.c -Icli-lib -lncurses

clean:
	rm -f sky_racer
