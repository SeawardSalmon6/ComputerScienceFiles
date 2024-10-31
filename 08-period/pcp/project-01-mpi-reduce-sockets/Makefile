clear:
	rm ./main ./output.txt ./sorted.txt -f

compile: clear
	mpicc -o main *.c -lm

run_and_export: compile
	mpirun -np 9 ./main > output.txt
	cat output.txt | sort -n > sorted.txt

run: compile
	mpirun -np 9 ./main
