all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students
test-przedmiotw: all
	./mydb baza.csv list_przedmiot
test-od-konca: all
	./mydb baza.csv list_students_from_end

test-sortuj-malejaco: all
	./mydb baza.csv sort_descending
test-sortuj-rosnaco: all
	./mydb baza.csv sort_ascending
test-sortuj-id: all
	./mydb baza.csv sort_id
test-sortuj-name: all
	./mydb baza.csv sort_name
test-ile: all
	./mydb baza.csv count_students

test-memory: all
	valgrind ./mydb baza.csv count_students
test-student: all
	./mydb baza.csv add_student Jakub Kowalski 123321 Kowalski@wp.pl

test-scourse: all
	./mydb baza.csv add_stud_do_przed 123456 1DE1203 5 ekstra

test-przed: all
	./mydb baza.csv add_przedmiot 1DE2104 "Metody numeryczne" 2020Z
test-przedocen: all
	./mydb baza.csv przedmiot-ocen 1DA1245
test-studocen: all
	./mydb baza.csv student-ocen 000007
clean:
	rm -f mydb