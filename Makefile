all: Sum.o D.o multiply.o calc.o raiz.o subt.o
	gcc Sum.o D.o multiply.o calc.o raiz.o subt.o -lm -o calc

Sum.o: Sum.c
	gcc -c Sum.c

D.o: D.c
	gcc -c D.c

multiply.o: multiply.c	
	    gcc -c multiply.c

calc.o: calc.c
	gcc -c calc.c

raiz.o: raiz.c
	gcc -c raiz.c

subt.o: subt.c
	gcc -c subt.c

clear:
	rm *.o
	rm calc
