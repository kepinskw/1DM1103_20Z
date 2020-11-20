
#zad5_main:zad5_main.c zad5_studenci.c zad5_dziekanat.c zad5_studenci.h zad5_dziekanat.h
DEPS=zad5_main.o zad5_dziekanat.o zad5_studenci.o
zad5_main: $(DEPS)
	cc $^ -o $@ 

%.o:%.c
	cc -c $^ -o $@
clean:
	rm zad5_main
	rm *.o
	  