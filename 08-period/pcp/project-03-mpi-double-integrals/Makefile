clear:
	rm ./main -f

compile_main:
	g++ -o main main.c -lm -fopenmp -O2 -O3 -Wall

main: compile_main
	./main > output.txt
