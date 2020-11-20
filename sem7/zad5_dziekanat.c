#include "zad5_dziekanat.h"
#include <string.h>
#include <stdio.h>

void najlepszy_student(student dane[100], int ile_rekordow) {
    char nr_albumow[100][10];
    int ile_studentow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    float srednie[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;

    ile_studentow = znajdz_studentow(nr_albumow, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].nr_albumu, nr_albumow, ile_studentow );
        // if (pozycje >= 0)
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    

    for (i=0;i<ile_studentow; i++) 
        printf("Student [%d]: %s - %f:%d - %f \n", i+1, nr_albumow[i], 
        sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    for (i=0; i < ile_studentow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepszy student: \n");
    printf("Student [%d]: %s - %f \n", 
        najlepsza_pozycja+1, nr_albumow[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );

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
