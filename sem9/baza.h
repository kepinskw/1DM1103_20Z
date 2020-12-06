#ifndef _BAZA_H
#define _BAZA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student {
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct _Student *nast;
} Student;

typedef struct _Przedmiot {
    char * kod_przedmiotu;
    char * nazwa ;
    char * semestr;
    

    struct _Przedmiot *nast;
} Przedmiot;

typedef struct _Ocena {
    char * nr_albumu;
    char * kod_przedmiotu;

    float ocena;
    char * komentarz;

    struct _Ocena *nast;
} Ocena;


typedef struct _SBaza {
    Student *lista_studentow; /* Głowa listy! */
    Przedmiot *lista_przedmiotow;
    Ocena *lista_ocen;
} SBaza;

SBaza * wczytaj_baze(char *nazwa_pliku);
SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza);
void listuj_studentow(SBaza *baza);
void listuj_przedmioty(SBaza *baza);
void listuj_oceny(SBaza *baza);

void zwolnij(SBaza *baza);
int ile_studentow(SBaza *baza);
int ile_ocen(SBaza *baza);
int ile_przedmiotow(SBaza *baza);

SBaza * add_student(SBaza * baza, char *imie, char *nazwisko, char *nr_albumu, char *email);
SBaza *add_course (SBaza *baza,char *kod_przedmiotu,char *nazwa_przedmiotu, char *semestr);
SBaza *add_student_to_course (SBaza *baza,char *nr_albumu,char *kod_przedmiotu);
#endif