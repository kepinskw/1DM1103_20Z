#include "zad5_dziekanat.h"
#include "zad5_studenci.h"


int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    ile = wczytaj(dane, argv[1]);
    if (strcmp(argv[2],"student")==0)
    {
        najlepszy_student(dane,ile);
    }
    if (strcmp(argv[2],"przedmiot")==0)
    {
        naj_przedmiot(dane,ile);
    }

    return 0;
}