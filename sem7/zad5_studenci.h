#ifndef _zad5_studenci_h
#define _zad5_studenci_h

#include <stdlib.h>
#include <stdio.h>
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

int wczytaj(student dane[100], char *fnazwa);
void wypisz(student dane[100], int n);
int znajdz(char *szukany_nr, char kody[100][10], int n);
int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n);
int znajdz_przedmiot(char kody[100][10], student dane[100], int n);

#endif