#include "baza.h"
// rekurencja


Student * ostatni(Student *glowa) {
    Student *el = glowa;
    if (el != NULL) {
        while (el->nast != NULL)
            el = el->nast;

        return el;
    } else
        return NULL;
}
Student * usun(Student *glowa, Student *el) {
    Student *c = glowa;
    if (glowa == el) {
        glowa = glowa->nast;
    } else {
        while (c != NULL) {
            if (c == el) {
                c->poprz->nast = c->nast;
                if (c->nast != NULL)
                    c->nast->poprz = c->poprz;

                break;
            }

            c = c->nast;
        }
    }
    c->nast = NULL;
    c->poprz = NULL;
    return glowa;
}
Student * najwiekszy(Student *el) {
    Student * max = NULL;
    while (el != NULL) {
        if (max == NULL) {
            max = el;
        } else {
            if ( strcmp(el->nazwisko, max->nazwisko) > 0 ) 
                max = el;
        }
        el = el->nast;
    }
    return max;
}
Student * sortuj_przez_wybieranie(Student *glowa) {
    Student * nglowa = NULL;
    Student * m;
    Student * o; // = NULL;

    while (glowa != NULL) {
        m = najwiekszy(glowa);
        glowa = usun(glowa, m);
        
        o = ostatni(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            m->poprz = o;
        }
        // o = m;

        // printf("Najwiekszy: %s\n", m->nazwisko);
        // wypisz_rekurencyjnie(glowa);
    }

    return nglowa;
}
Student * zwroc(Student *glowa, int i) {
    while (glowa != NULL && i-- > 0) // i jest zmniejszany postfixowo - czyli po porownaniu z 0
        glowa = glowa->nast;    
    
    return glowa;
}

Przedmiot *ostatnip(Przedmiot *glowa)
{
    Przedmiot *el = glowa;
    if(el != NULL)
    {
        while (el->nast != NULL)
            el = el->nast;
        
        return el;
    }
    else 
        return NULL;
}
Przedmiot *usunp(Przedmiot *glowa, Przedmiot *el)
{
    Przedmiot *c=glowa;
    if ( glowa == el )
    {
        glowa = glowa->nast;
    }
    else 
    {
        while ( c!=NULL)
        {
            if ( c == el)
            {
                c->poprz->nast = c->nast;
                if (c->nast != NULL)
                    c->nast->poprz = c->poprz;
                break;
            }
            c=c->nast;
            
        }
    }
    c->nast=NULL;
    c->poprz=NULL;
    return glowa;
}
Przedmiot *najwiekszyKOD (Przedmiot *el)
{
    Przedmiot *max=NULL;
    while (el != NULL)
    {
        if (max==NULL){
            max=el;
        }else{
            if( strcmp(el->kod_przedmiotu, max->kod_przedmiotu)>0)
                max =el;
        }
        el=el->nast;
    }
    return max;
}
Przedmiot *najwiekszyNAZWA (Przedmiot *el)
{
    Przedmiot *max=NULL;
    while (el != NULL)
    {
        if (max==NULL){
            max=el;
        }else{
            if( strcmp(el->nazwa, max->nazwa)>0)
                max =el;
        }
        el=el->nast;
    }
    return max;
}
Przedmiot *sortuj_przez_wybieranieKOD (Przedmiot *glowa)
{
    Przedmiot *nglowa=NULL;
    Przedmiot *m;
    Przedmiot *o;

    while (glowa != NULL)
    {
        m=najwiekszyKOD(glowa);
        glowa = usunp(glowa,m);

        o = ostatnip(nglowa);
        if(o==NULL){
            nglowa =m;
        } else {
            o->nast = m;
            m->poprz=o;
        }
    }
    return nglowa;
}
Przedmiot *sortuj_przez_wybieranieNazwa (Przedmiot *glowa)
{
    Przedmiot *nglowa=NULL;
    Przedmiot *m;
    Przedmiot *o;

    while (glowa != NULL)
    {
        m=najwiekszyNAZWA(glowa);
        glowa = usunp(glowa,m);

        o = ostatnip(nglowa);
        if(o==NULL){
            nglowa =m;
        } else {
            o->nast = m;
            m->poprz=o;
        }
    }
    return nglowa;
}
Przedmiot * zwrocp(Przedmiot *glowa, int i) {
    while (glowa != NULL && i-- > 0) // i jest zmniejszany postfixowo - czyli po porownaniu z 0
        glowa = glowa->nast;    
    
    return glowa;
}

// Przedmiot * filtruj(Przedmiot * glowa, char *kod_przedmiotu) 
// {
//     Przedmiot *nowa_glowa=NULL;
//     Przedmiot *last_przedmiot=NULL;
//     while (glowa!=NULL)
//     {
//       Przedmiot *przed = (Przedmiot*) malloc(sizeof(Przedmiot));
//         przed->nast=NULL;
//         if((strcmp(glowa->kod_przedmiotu,kod_przedmiotu)==0)&&(nowa_glowa=NULL))
//         {
//             nowa_glowa=glowa;
//         }
//         else 
//             last_przedmiot->nast=przed;
//         last_przedmiot=przed;

        
//         przed->kod_przedmiotu= (char*) malloc ( sizeof(char) * (strlen(glowa->kod_przedmiotu) + 1 ));
//         strcpy(przed->kod_przedmiotu,glowa->kod_przedmiotu);

        
//         przed->nazwa= (char*) malloc ( sizeof(char) * (strlen(glowa->nazwa) + 1));
//         strcpy(przed->nazwa,glowa->nazwa);

        
//         przed->semestr= (char*) malloc ( sizeof(char) * (strlen(glowa->semestr) + 1));
//         strcpy(przed->semestr,glowa->semestr);
        
//         if (last_przedmiot==NULL)
//         {
//             glowa=przed;
//         }
//         else 
//             last_przedmiot->nast=przed;
//         last_przedmiot=przed;
//         if((strcmp(glowa->kod_przedmiotu,kod_przedmiotu)==0)&&(nowa_glowa=NULL))
//         {
//             nowa_glowa=glowa;
//         }
//         else if (strcmp(glowa->kod_przedmiotu,kod_przedmiotu)==0)
//         {
//             last->nast=glowa;
//         }
//         glowa=glowa->nast;
//     }
  
//     return nowa_glowa;
// }

void wyszukaj (SBaza *baza, char *przedmiott)
{
    Ocena *a= baza->lista_ocen;
    while (a!=NULL)
    {
        if(strcmp(a->kod_przedmiotu,przedmiott)==0)
        {
            printf("%s %f\n", a->kod_przedmiotu, a->ocena);
        }
        a=a->nast;
    }
}
void wyszukajOcenystudenta (SBaza *baza, char *kodstudenta)
{
    Ocena *a= baza->lista_ocen;
    while (a!=NULL)
    {
        if(strcmp(a->nr_albumu,kodstudenta)==0)
        {
            printf("%s %s %f \n",a->kod_przedmiotu, a->nr_albumu, a->ocena);
        }
        a=a->nast;
    }
}

void wypisz_rekurencyjnie(Student *el) {
    if (el != NULL) {
        printf("%s %s %s %s\n", el->imie, el->nazwisko, el->nr_albumu, el->email);        
        wypisz_rekurencyjnie( el->nast );
    }
}
void listuj_przedmioty_od_konca(SBaza *b) 
{
    Przedmiot *c;
   
    int i;
    int n = ile_przedmiotow(b);
    for (i=(n-1); i >= 0; i--) {
        c = zwrocp(b->lista_przedmiotow, i);
        printf("%s %s %s \n", c->kod_przedmiotu, c->nazwa, c->semestr);        
    }
}
void listuj_studentow_od_konca(SBaza *b) {
    // Student *ogon = ostatni(b->lista_studentow);
    Student *c;
    /*
    while (c != null) {

        c = c->poprz;
    }
    */
    // for (c=ogon; c != NULL; c = c->poprz) {
    //     printf("%s %s %s %s\n", c->imie, c->nazwisko, c->nr_albumu, c->email);        
    // }

    int i;
    int n = ile_studentow(b);
    for (i=(n-1); i >= 0; i--) {
        c = zwroc(b->lista_studentow, i);
        printf("%s %s %s %s\n", c->imie, c->nazwisko, c->nr_albumu, c->email);        
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
void wypisz_rekurencyjnie_od_konca(Student *el) {
    if (el != NULL) {
        wypisz_rekurencyjnie( el->nast );
        printf("%s %s %s %s\n", el->imie, el->nazwisko, el->nr_albumu, el->email);        
    }
}
void listuj_studentow(SBaza *baza) {
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }

//    wypisz_rekurencyjnie(baza->lista_studentow);
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
Student * wczytaj_studentow(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);
    Student *c;

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;
        stud->poprz = NULL;

        if (glowa == NULL)
            glowa = stud;
        else {
            c = ostatni(glowa);
            c->nast = stud;
            stud->poprz = c;
        }

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
SBaza * wczytaj_baze(char *nazwa_pliku) {
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
    baza->lista_studentow = wczytaj_studentow(fin);
    baza->lista_przedmiotow=wczytaj_przedmiot(fin);
    baza->lista_ocen = wczytaj_ocene(fin);
    fclose(fin);
    return baza;
}


SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza) {
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
        fprintf(fout, "%s;%s;%f;%s\n", ocen->kod_przedmiotu, ocen->nr_albumu,ocen->ocena,ocen->komentarz);
        ocen = ocen->nast;
    }
    
    fclose(fout);
    return NULL;
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
SBaza *add_student_to_course (SBaza *baza,char *nr_albumu,char *kod_przedmiotu, char *ocenka, char *koment)
{
    Ocena *nocena = (Ocena*) malloc(sizeof(Ocena));
    Ocena *ostatni=NULL;
    nocena->nast=NULL;

    nocena->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu)+1));
    strcpy(nocena->nr_albumu,nr_albumu);

    nocena->kod_przedmiotu = (char*) malloc(sizeof(char) * (strlen(kod_przedmiotu)+1));
    strcpy(nocena->kod_przedmiotu,kod_przedmiotu);

    nocena->ocena = atof(ocenka);
    nocena->komentarz = (char*) malloc(sizeof(char) * (strlen(koment)+1));
    strcpy(nocena->komentarz,koment);
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
