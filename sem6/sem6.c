#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// mini baza studentow, tabela, przedmioty, ocena
// cel: ranking.
typedef struct _student 
{
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student, *pstudent;

int wczytaj (student dane[100], char *fnazwa)
{
    FILE *fin = fopen(fnazwa,"r");
    int cnt,i;
    char bufor[1024];
    char *w;

    fgets(bufor,1023,fin);
    sscanf (bufor, "%d",&cnt);

    for (i=0;i<cnt;i++)
    {
        fgets(bufor,1023,fin);
        //printf("%s\n",bufor);
        w = strtok(bufor,"|");
        strncpy(dane[i].imie,w,24);
        //dane[i].imie[24]=0;

        w = strtok(NULL,"|");
        strncpy(dane[i].nazwisko,w,49);

        w = strtok(NULL,"|");
        strncpy(dane[i].nr_albumu,w,9);

        w = strtok(NULL,"|");
        strncpy(dane[i].kod_przed,w,9);

        w = strtok(NULL,"|");
        strncpy(dane[i].nazwa_przed,w,254);

        w = strtok(NULL,"|");
        strncpy(dane[i].imie,w,24);

        w = strtok(NULL,"|");
        dane[i].ocena = atof(w);

        w = strtok(NULL,"|");
        dane[i].ects = atoi(w);
    }
    fclose(fin);
    return cnt;
}

void wypisz(student dane[100], int n)
{
    for (int i=0;i<n;i++)
    {
        printf("{student:%s - %s %s, z przedmiotu [%s] %s za ECTS %d otrzymal %.1f\n", dane[i].nr_albumu,dane[i].imie,dane[i].nazwisko,dane[i].kod_przed,dane[i].nazwa_przed, dane[i].ects, dane[i].ocena);
    }
}

int znajdz(char *nr, char nr_albmumow[100][10],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        if (strcmp(nr,nr_albmumow[i])==0)
            return i;
    }
    return -1;
}

int znajdz_studentow(char nr_albumow[100][10], student dane[100],int n)
{
    int ileznalazlem=0;
    int i;
    for(i=0 ;i<n;i++)
    {
        if (znajdz(dane[i].nr_albumu,nr_albumow,ileznalazlem)==-1)
        {
            strncpy(nr_albumow[ileznalazlem],dane[i].nr_albumu,9);
            ileznalazlem++;
        }
    }


    return ileznalazlem;
}

void naj (student dane[100],int ile)
{
    char studenci[100];
    float sumy_ocenw[100];
    int sumy_ects[100];
    float srednie[100];
    int iles;
    char nr_albumow[100][10];
    iles=znajdz_studentow(nr_albumow,dane,ile);
    for (int i=0;i<iles;i++)
    {
        printf("Student [%d]: %s",i+1,nr_albumow[i]);
    }
    int pozycja;
    for (int i=0;i<ile;i++)
    {
        pozycja= znajdz(dane[i].nr_albumu, nr_albumow,iles);
        sumy_ocenw[pozycja]+= dane[i].ocena*dane[i].ects;
        sumy_ects[pozycja]+=dane[i].ects;
    }

    for(int i=0;i<iles;i++)
    {
        printf("Student [%d]: %s - %f:%d - %f\n", i+1,nr_albumow[i],sumy_ocenw[i],sumy_ects[i], sumy_ocenw[i]/sumy_ects[i]);
    }


}
int main (int argc, char *argv[])
{
    student dane[100];
    int ile;
    ile=wczytaj(dane, argv[1]);

    wypisz(dane,ile);


    return 0;
}