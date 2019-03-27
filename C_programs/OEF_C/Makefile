#compileert alles met .c extensie
CC=gcc
SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))

comp: $(PROGS)

%: %.c

	$(CC) $(CFLAGS)  -o $@ $<



#verwijderd alle .exe files in alle mappen
clean :
	find . -type f -executable -delete
#alle .exe in een bepaalde map
cleanfolder :
	-rm *.exe


