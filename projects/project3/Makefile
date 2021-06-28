Scheduler: main.o display.o file.o
	gcc -o Scheduler main.o display.o file.o

main.o: main.c display.h
	gcc -c main.c

display.o: display.c display.h
	gcc -c display.c

file.o: file.c file.h
	gcc -c file.c

clean:
	rm -f *.o Scheduler