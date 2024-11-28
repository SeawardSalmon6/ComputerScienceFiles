clear:
	rm ./main -f

compile_main:
	mpicc -o main main.c -lm -O2 -O3 -Wall

main: compile_main
	mpirun -n 8 ./main
