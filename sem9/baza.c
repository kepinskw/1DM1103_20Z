#include "baza.h"

Student * wczytaj_studentow(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Student *last_student = NULL;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
    }

    return glowa;
}
Przedmiot *wczytaj_przedmiot (FILE *fin)
{
    char bufor[255];
    int n;
    char *s;
    Przedmiot *last_przedmiot = NULL;
    Przedmiot *glowa = NULL;
    fgets(bufor,254,fin);
    sscanf(bufor,"%d",&n);

    for (int i=0;i<n;i++)
    {
        Przedmiot *przed = (Przedmiot*) malloc(sizeof(Przedmiot));
        przed->nast=NULL;
        if (last_przedmiot==NULL)
        {
            glowa=przed;
        }
        else 
            last_przedmiot->nast=przed;
        last_przedmiot=przed;

        fgets(bufor,254,fin);
        s = strtok(bufor,";");
        przed->kod_przedmiotu= (char*) malloc ( sizeof(char) * (strlen(s) + 1 ));
        strcpy(przed->kod_przedmiotu,s);

        s = strtok(NULL,";");
        przed->nazwa= (char*) malloc ( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->nazwa,s);

        s = strtok(NULL,"\n");
        przed->semestr= (char*) malloc ( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->semestr,s);
    }
    return glowa;

}
Ocena *wczytaj_ocene (FILE *fin)
{
    char bufor[255];
    int n,i;
    char *s;
    float f;

    

    Ocena *last_ocena = NULL;
    Ocena *glowa = NULL;
    fgets(bufor,254,fin);
    sscanf(bufor,"%d",&n);

    for(i=0;i<n;i++)
    {
        Ocena *ocen = (Ocena*) malloc(sizeof(Ocena));
        ocen->nast=NULL;
        if(last_ocena==NULL)
            glowa=ocen;
        else 
            last_ocena->nast=ocen;
        last_ocena=ocen;

        fgets(bufor,254,fin);
        s = strtok(bufor,";");
        ocen->kod_przedmiotu= (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocen->kod_przedmiotu,s);

        s = strtok(NULL,";");
        ocen->nr_albumu= (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocen->nr_albumu,s);

        s = strtok(NULL,";");
        f = atof(s);
        ocen->ocena=f;

        s = strtok(NULL,"\n");
        ocen->komentarz= (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocen->komentarz,s);

        
    }
    return glowa;
}
SBaza * wczytaj_baze(char *nazwa_pliku) {
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
    baza->lista_studentow = wczytaj_studentow(fin);
    baza->lista_przedmiotow = wczytaj_przedmiot(fin);
     baza->lista_ocen = wczytaj_ocene(fin);



    fclose(fin);
    return baza;
}

int ile_studentow(SBaza *baza) {
    int n = 0;
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}
int ile_przedmiotow(SBaza *baza) {
    int n = 0;
    Przedmiot * przed = baza->lista_przedmiotow;
    while (przed != NULL) {
        n++;
        przed = przed->nast;
    }
    return n;
}
int ile_ocen(SBaza *baza) {
    int n = 0;
    Ocena * ocen = baza->lista_ocen;
    while (ocen != NULL) {
        n++;
        ocen = ocen->nast;
    }
    return n;
}
void listuj_studentow(SBaza *baza) {
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}
void listuj_przedmioty(SBaza *baza) {
    Przedmiot * przed = baza->lista_przedmiotow;
    while (przed != NULL) {
        printf("%s %s %s \n", przed->kod_przedmiotu, przed->nazwa, przed->semestr);
        przed = przed->nast;
    }
}
void listuj_oceny(SBaza *baza) {
    Ocena * ocen = baza->lista_ocen;
    while (ocen != NULL) {
        if(ocen->ocena==0){
        printf("%s %s - %s\n", ocen->kod_przedmiotu, ocen->nr_albumu, ocen->komentarz);
        ocen = ocen->nast;
        }
        else
        {
            printf("%s %s %f %s\n", ocen->kod_przedmiotu, ocen->nr_albumu, ocen->ocena, ocen->komentarz);
        ocen = ocen->nast;
        }
        
    }
}
SBaza * add_student(SBaza * baza, char *imie, char *nazwisko, char *nr_albumu, char *email)
{
    Student *nowy = (Student*) malloc(sizeof(Student));
  	Student *ostatni = NULL;
  	nowy->nast = NULL;

  	nowy->imie = (char*) malloc(sizeof(char) * (strlen(imie) + 1));
    strcpy(nowy->imie, imie);

    nowy->nazwisko = (char*) malloc(sizeof(char) * (strlen(nazwisko) + 1));
    strcpy(nowy->nazwisko, nazwisko);

    nowy->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);

    nowy->email = (char*) malloc(sizeof(char) * (strlen(email) + 1));
    strcpy(nowy->email, email);

    ostatni=baza->lista_studentow;
    
    if(ile_studentow(baza) == 0)
    {
      baza->lista_studentow = nowy;
    }
    else
    {
      for(int i=1; i<ile_studentow(baza); i++)
      {
        ostatni = ostatni->nast;
      }
      ostatni->nast = nowy;
    }   
    return NULL;
}
SBaza *add_course (SBaza *baza,char *kod_przedmiotu,char *nazwa_przedmiotu, char *semestr)
{
    Przedmiot *przed = (Przedmiot*) malloc(sizeof(Przedmiot));
    Przedmiot *ostatni=NULL;
    przed->nast=NULL;

    przed->kod_przedmiotu=(char*) malloc(sizeof(char) * (strlen(kod_przedmiotu)+1));
    strcpy(przed->kod_przedmiotu,kod_przedmiotu);

    przed->nazwa=(char*) malloc(sizeof(char) * (strlen(nazwa_przedmiotu)+1));
    strcpy(przed->nazwa,nazwa_przedmiotu);

    przed->semestr=(char*) malloc(sizeof(char) * (strlen(semestr)+1));
    strcpy(przed->semestr,semestr);

    ostatni=baza->lista_przedmiotow;

    if(ile_przedmiotow(baza)==0)
    {
        baza->lista_przedmiotow = przed;
    }
    else
    {
        for(int i=1;i<ile_przedmiotow(baza);i++)
        {
            ostatni=ostatni->nast;
        }
        ostatni->nast=przed;
    }
    return NULL;
    

}
SBaza *add_student_to_course (SBaza *baza,char *nr_albumu,char *kod_przedmiotu)
{
    Ocena *nocena = (Ocena*) malloc(sizeof(Ocena));
    Ocena *ostatni=NULL;
    nocena->nast=NULL;

    nocena->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu)+1));
    strcpy(nocena->nr_albumu,nr_albumu);

    nocena->kod_przedmiotu = (char*) malloc(sizeof(char) * (strlen(kod_przedmiotu)+1));
    strcpy(nocena->kod_przedmiotu,kod_przedmiotu);

    ostatni=baza->lista_ocen;

    if(ile_ocen(baza) == 0)
    {
      baza->lista_ocen = nocena;
    }
    else
    {
      for(int i=1; i<ile_ocen(baza); i++)
      {
        ostatni = ostatni->nast;
      }
      ostatni->nast = nocena;
    }

     return NULL;
}
SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza) 
{
    FILE *fout = fopen(nazwa_pliku,"w+");
    Student *stud=baza->lista_studentow;
    Przedmiot *przed=baza->lista_przedmiotow;
    Ocena *ocen=baza->lista_ocen;
    
    fprintf(fout,"%d\n",ile_studentow(baza));
    for (int i=0;i<ile_studentow(baza);i++)
    {
        fprintf(fout, "%s;%s;%s;%s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }

    fprintf(fout,"%d\n",ile_przedmiotow(baza));
    for(int j=0;j<ile_przedmiotow(baza);j++)
    {
        fprintf(fout, "%s;%s;%s\n", przed->kod_przedmiotu, przed->nazwa, przed->semestr);
        przed = przed ->nast;   
    }
    
    fprintf(fout,"%d\n",ile_ocen(baza));
    for(int k=0;k<ile_ocen(baza);k++)
    {
        fprintf(fout, "%s;%s\n", ocen->kod_przedmiotu, ocen->nr_albumu);
        ocen = ocen->nast;
    }
    
    fclose(fout);
    return NULL;
}
void zwolnij_student(Student *s) {
    free(s->imie);
    free(s->nazwisko);
    free(s->nr_albumu);
    free(s->email);
    free(s);
}
void zwolnij_przedmioty(Przedmiot *s) {
    free(s->kod_przedmiotu);
    free(s->nazwa);
    free(s->semestr);
    free(s);
}
void zwolnij_oceny(Ocena *s) {
    free(s->nr_albumu);
    free(s->kod_przedmiotu);
    free(s->komentarz);
    free(s);
}
void zwolnij_liste_studentow(Student *s) {
    Student *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_student(s);
        s = n;
    }
}
void zwolnij_liste_przedmiotow(Przedmiot *s) {
    Przedmiot *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_przedmioty(s);
        s = n;
    }
}
void zwolnij_liste_ocen(Ocena *s) {
    Ocena *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_oceny(s);
        s = n;
    }
}

void zwolnij(SBaza *baza) {
    zwolnij_liste_studentow(baza->lista_studentow);
    zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
    zwolnij_liste_ocen(baza->lista_ocen);
    free(baza);
}

