all:devrand.o
	gcc devrand.o

devrand.o:devrand.c
	gcc -c devrand.c

run:
	./a.out

clean:
	rm *.o *.txt
