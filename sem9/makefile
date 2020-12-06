all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students

test-ile: all
	./mydb baza.csv count_students

test-student: all
	./mydb baza.csv add_student Jakub Kowalski 123321 Kowalski@wp.pl

test-scourse: all
	./mydb baza.csv add_stud_do_przed 123456 1DE1203

test-przed: all
	./mydb baza.csv add_przedmiot 1DE2103 "Metody numeryczne" 2020Z

test-memory: all
	valgrind ./mydb baza.csv count_students
clean:
	rm -f mydb