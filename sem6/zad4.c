#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student, *pstudent;

int wczytaj(student dane[100], char *fnazwa) {
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) {
        fgets(bufor, 1023, fin);
        // printf("%s", bufor);
        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}



int znajdz(char *szukany_nr, char kody[100][10], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_nr, kody[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_przedmiot(char kody[100][10], student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (znajdz(dane[i].kod_przed, kody, ile_znalazlem ) == -1) {
            strncpy(kody[ile_znalazlem], dane[i].kod_przed, 9);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}


void naj_przedmiot(student dane[100], int ile_rekordow) {
    char kody[100][10];
    int ile_przedmiotow;
    float suma_ocen[100];
    int ile_ocen[100];
    float srednie[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    int najgorsza_pozycja;
    float najlepsza = 0.0f;
    float najgorsza =100.0f;
    int nl,ng;
    for (int k=0;k<ile_rekordow;k++)
    {
        suma_ocen[k]=0;
        ile_ocen[k]=0;
    }
    ile_przedmiotow = znajdz_przedmiot(kody, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].kod_przed, kody, ile_przedmiotow );
        suma_ocen[pozycja] += dane[i].ocena;
        ile_ocen[pozycja]++;
    }    

    for (i=0; i < ile_przedmiotow; i++) {
        if (najlepsza < suma_ocen[i] / ile_ocen[i]) {
            najlepsza = suma_ocen[i] / ile_ocen[i];
            najlepsza_pozycja = i;
        }
    }
    for(i=0;i<ile_przedmiotow;i++)
    {
        if(najgorsza>suma_ocen[i] / ile_ocen[i])
        {
            najgorsza=suma_ocen[i] / ile_ocen[i];
            najgorsza_pozycja=i;
        }
    }
    
    for (int j=0; j<ile_rekordow;j++)
    {
        if ((strcmp(kody[najlepsza_pozycja], dane[j].kod_przed) == 0)) 
        {
            nl=j;
            break;
        }
    }
      for (int d=0; d<ile_rekordow;d++)
    {
        if ((strcmp(kody[najgorsza_pozycja], dane[d].kod_przed) == 0)) 
        {
            ng=d;
            break;
        }
    }
    

    printf("Najlepsza średnia: %s - %s: %.1f",kody[najlepsza_pozycja],dane[nl].nazwa_przed, suma_ocen[najlepsza_pozycja]/ile_ocen[najlepsza_pozycja]);
    printf("\n");
    printf("Najlgorsza średnia: %s - %s: %.1f",kody[najgorsza_pozycja],dane[ng].nazwa_przed, suma_ocen[najgorsza_pozycja]/ile_ocen[najgorsza_pozycja]);
    printf("\n");
    
    

}

int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    ile = wczytaj(dane, argv[1]);

    naj_przedmiot(dane, ile);

    return 0;
}