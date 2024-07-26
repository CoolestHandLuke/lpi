

main: main.o error_functions.o
	gcc main.c -c

main.o: main.c 
	gcc main.c -c

error_functions.o: error_functions.c error_functions.h
	gcc error_functions.c -c 

clean:
	rm main main.o error_functions.o 
