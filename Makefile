all: utf8code

utf8code: main.c
	gcc main.c -o utf8code

install: all
	cp utf8code /usr/local/bin

uninstall:
	rm -f /usr/local/bin/utf8code

clean:
	rm utf8code -f
