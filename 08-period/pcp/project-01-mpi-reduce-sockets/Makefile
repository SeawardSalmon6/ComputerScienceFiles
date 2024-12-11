clear:
	rm ./main ./output.txt ./sorted.txt -f

compile: clear
	gcc -o main *.c -lm

run_and_export: compile
	./main 0 & ./main 1 & ./main 2 & ./main 3 & ./main 4 & ./main 5 & ./main 6 & ./main 7 ./main 8
	cat output.txt | sort -n > sorted.txt

run: compile
	./main 0 & ./main 1 & ./main 2 & ./main 3 & ./main 4 & ./main 5 & ./main 6 & ./main 7 ./main 8
