all: luna prospetto

luna: luna.c
	gcc -Wall -Wextra -g -lnova -o luna luna.c

prospetto: prospetto.c
	gcc -Wall -Wextra -g -lnova -o prospetto prospetto.c

clean:
	rm luna prospetto

.PHONY: clean
