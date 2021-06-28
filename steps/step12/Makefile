hanoi: hanoi.o display.o autosolve.o
	gcc -o hanoi hanoi.o display.o autosolve.o

hanoi.o: hanoi.c hanoi.h autosolve.h
	gcc -c hanoi.c

autosolve.o: autosolve.c autosolve.h
	gcc -c autosolve.c

display.o: display.c hanoi.h
	gcc -c display.c

clean:
	rm -f *.o hanoi
