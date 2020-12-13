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

    struct _Student *poprz;
    struct _Student *nast;
} Student;

typedef struct _Przedmiot {
    char * kod_przedmiotu;
    char * nazwa ;
    char * semestr;
    
    struct _Przedmiot *poprz;
    struct _Przedmiot *nast;
} Przedmiot;

typedef struct _Ocena {
    char * nr_albumu;
    char * kod_przedmiotu;

    float ocena;
    char * komentarz;

    struct _Ocena *poprz;
    struct _Ocena *nast;
} Ocena;


typedef struct _SBaza {
    Student *lista_studentow; /* Głowa listy! */
    Przedmiot *lista_przedmiotow;
    Ocena *lista_ocen;
} SBaza;
void wyszukaj (SBaza *baza, char *przedmiott);
void wyszukajOcenystudenta (SBaza *baza, char *przedmiott);
Przedmiot *wczytaj_przedmiot (FILE *fin);
Przedmiot * filtruj(Przedmiot * glowa, char *kod_przedmiotu);
Ocena *wczytaj_ocene (FILE *fin);
void listuj_studentow(SBaza *baza);
void listuj_przedmioty(SBaza *baza);
void listuj_oceny(SBaza *baza);
Przedmiot * zwrocp(Przedmiot *glowa, int i);
SBaza * wczytaj_baze(char *nazwa_pliku);
SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza);
void listuj_przedmioty_od_konca(SBaza *b);
void listuj_studentow_od_konca(SBaza *baza);
void zwolnij(SBaza *baza);
int ile_studentow(SBaza *baza);
void zwolnij_przedmioty(Przedmiot *s);
void zwolnij_oceny(Ocena *s);
void zwolnij_liste_przedmiotow(Przedmiot *s);
void zwolnij_liste_ocen(Ocena *s);
int ile_przedmiotow(SBaza *baza);
int ile_ocen(SBaza *baza);
SBaza * add_student(SBaza * baza, char *imie, char *nazwisko, char *nr_albumu, char *email);
SBaza *add_course (SBaza *baza,char *kod_przedmiotu,char *nazwa_przedmiotu, char *semestr);
SBaza *add_student_to_course (SBaza *baza,char *nr_albumu,char *kod_przedmiotu, char *ocenka, char *koment);
Przedmiot *ostatnip(Przedmiot *glowa);
Przedmiot *usunp(Przedmiot *glowa, Przedmiot *el);
Przedmiot *najwiekszyKOD (Przedmiot *el);
Przedmiot *najwiekszyNAZWA (Przedmiot *el);
Przedmiot *sortuj_przez_wybieranieKOD (Przedmiot *glowa);
Przedmiot *sortuj_przez_wybieranieNazwa (Przedmiot *glowa);
Student * sortuj_przez_wybieranie(Student *glowa);
void wypisz_rekurencyjnie(Student *el);
void wypisz_rekurencyjnie_od_konca(Student *el);
void listuj_studentow_od_konca(SBaza *b);

#endif