#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza.h"

int main(int argc, char ** argv) {
    SBaza *baza;
    baza =wczytaj_baze(argv[1]);
    if (strcmp("list_students", argv[2]) == 0) {
        listuj_studentow(baza);
    } 
    else if (strcmp("list_przedmiot", argv[2]) == 0) {
        
        listuj_przedmioty(baza);
        listuj_oceny(baza);
    } 
    else if (strcmp("list_students_from_end", argv[2]) == 0) {
        listuj_studentow_od_konca(baza);
    } 
    else if (strcmp("sort_descending", argv[2]) == 0) {
        baza->lista_studentow = sortuj_przez_wybieranie(baza->lista_studentow); 
        listuj_studentow(baza);
    } 
    else if (strcmp("sort_ascending", argv[2]) == 0){
        baza->lista_studentow = sortuj_przez_wybieranie(baza->lista_studentow); 
        listuj_studentow_od_konca(baza);
    }
    else if (strcmp("add_student", argv[2]) == 0) {
        add_student(baza, argv[3], argv[4], argv[5], argv[6]);
        listuj_studentow(baza);
    } 
    else if (strcmp("count_students", argv[2]) == 0) {
        printf("Liczba studentów: %d\n", ile_studentow(baza));
    }  
    else if (strcmp("add_przedmiot", argv[2]) == 0) 
    {
        add_course(baza, argv[3], argv[4], argv[5]);
        listuj_przedmioty(baza);
    }
    else if (strcmp("add_stud_do_przed", argv[2]) == 0) 
    {
        add_student_to_course(baza, argv[3], argv[4], argv[5],argv[6]);
        listuj_oceny(baza);
        
    }
    else if (strcmp("sort_name", argv[2]) == 0) {
        baza->lista_przedmiotow = sortuj_przez_wybieranieNazwa(baza->lista_przedmiotow); 
        listuj_przedmioty_od_konca(baza);
    } 
    else if (strcmp("sort_id", argv[2]) == 0){
        baza->lista_przedmiotow = sortuj_przez_wybieranieKOD(baza->lista_przedmiotow); 
        listuj_przedmioty_od_konca(baza);
    }
    else if (strcmp("szukaj_poid", argv[2]) == 0){
        baza->lista_przedmiotow = sortuj_przez_wybieranieKOD(baza->lista_przedmiotow); 
        listuj_przedmioty(baza);
    }
    else if (strcmp("przedmiot-ocen", argv[2]) == 0){
        wyszukaj(baza,argv[3]);
    }
    else if (strcmp("student-ocen", argv[2]) == 0){
        wyszukajOcenystudenta(baza,argv[3]);
    }
    zapisz_baze(argv[1], baza);
    zwolnij(baza);
    return 0;
}