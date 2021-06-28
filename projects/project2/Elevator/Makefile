all:	
	@echo "Type 'make elevator32' to build on 32-bit systems and "
	@echo "'make elevator64' to build on 64-bit systems"
	@echo "If you encounter any error messages switching between "
	@echo "machines, try typing 'make clean' to remove old files"

elevator.o:	elevator.c
	gcc -c -o elevator.o elevator.c
   
elevator32: elevator.o
	g++ -o elevator elevator.o -lm libElevatorLib.a `wx-config --libs`

elevator64: elevator.o
	g++ -o elevator elevator.o -lm libElevatorLib64.a `wx-config --libs`

clean:
	rm elevator.o
