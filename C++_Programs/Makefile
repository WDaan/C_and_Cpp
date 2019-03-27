#compileert alles met .c extensie
CC=g++
SRCS = $(wildcard *.cpp)
PROGS = $(patsubst %.cpp,%,$(SRCS))

comp: $(PROGS)

%: %.c

	$(CC) $(CFLAGS)  -o $@ $<



#deze makefile verwijderd alle .exe files in alle mappen
clean :
	find . -type f -executable -delete
#alle .exe in een bepaalde map
cleanfolder :
	-rm *.exe


