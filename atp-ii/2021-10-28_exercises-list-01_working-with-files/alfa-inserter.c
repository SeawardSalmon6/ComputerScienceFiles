#include <stdio.h>
#include <stdlib.h>

int main() {
    char letra; // sets first letter to 'A'
    int num, i = 0; // var that gets the number read and writes in the new file

    FILE *fr, *fp; // creating files
    fr = fopen("numbers", "r"); // opens the 'numbers' for reading
    fp = fopen("alfanumber", "w"); // creates a writing file 'alfanumber'

    if(fr == NULL || fp == NULL) { // checks if files were created correctly
        puts("Files couldn't be created... exiting...");
        exit(-1);
    }

	puts("\nSituation: Processing your file...");
    while(!feof(fr)) { // runs the loop until End Of File (EOF)
		letra = 'A' + i % 26; // goes through every alphabet letter, starting from 'A'

        fscanf(fr, "%d ", &num); // reads the number followed by a space
        fprintf(fp, "%d%c", num, letra); // writes on 'alfanumber' the read number

		i++; // go to next alphabet letter
    }

	// inserts a blank line and close and save both files
    fprintf(fp, "%c", '\n');
    fclose(fr); fclose(fp);

    puts("\nSituation: the file 'alfanumber' has been created succesfully!\n");

    return 0;
}
