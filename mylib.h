#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

/* Table of Contents
    0. Prototypes of all functions
    1. Macros
    2. Other Functions
    3. Arrays
    4. Matrix
 */

// 0. Prototypes of all functions
    void printHeader(const char *header);
    void printIntArray(const char *header, int *array, size_t length, bool reverse);
    void clearIntArray(int *array, size_t length);
    void printIntMatrix(const char *header, int **array, size_t rows, size_t columns, bool reverse);
    void clearIntMatrix(int **array, size_t rows, size_t columns);

// 1. Macros
    #define setLocale setlocale(LC_ALL, "Portuguese")
    #define errArrMsg puts("\n-------> AVISO: Insira um array válido, com pelo menos um elemento.")
    #define err2DArrMsg puts("\n-------> AVISO: Insira uma matriz válida, com pelo menos uma coluna e uma linha.")

// 2. Other Functions
    // Prints a header with "========== text =========" scheme
    void printHeader(const char *header) {
        printf("\n=============== %s ===============\n", header);
    }

// 3. Arrays
    /* Prints a full array in reverse or normal order. 

        <header> receives a string with description of For;
        <array> capture the array for printing;
        <elements> quantity of array elements;
        <reverse> if true, prints the array from the last to first element.
    */
    void printIntArray(const char *header, int *array, size_t length, bool reverse) {
        if(length > 0) {
            printHeader(header);
            if(!reverse)
                for(int i = 0; i < length; i++)
                    printf("\n\t- %dº Elemento:  %d", i + 1, array[i]);

            else
                for(int i = length; i >= 0; i--)
                    printf("\n\t- %dº Elemento:  %d", i + 1, array[i]);

        } else errArrMsg;
    }

    // Clears the array, populating it with 0's (zeros).
    void clearIntArray(int *array, size_t length) {
        if(length > 0)
            for (int i = 0; i < length; i++)
                array[i] = 0;
        else
            errArrMsg;
    }

// 4. Matrix
    /* Prints a full array in reverse or normal order. 

        <header> receives a string with description of For;
        <array> capture the array for printing;
        <elements> quantity of array elements;
        <reverse> if true, prints the array from the last to first element.
    */
    void printIntMatrix(const char *header, int **array, size_t rows, size_t columns, bool reverse) {
        if(rows > 0 && columns > 0) {
            printHeader(header);
            if(!reverse)
                for (int r = 0; r < rows; r++)
                    for (int c = 0; c < columns; c++)
                        if(c % columns == 0)
                            printf("\n\t%d", array[r][c]);
                        else
                            printf("\t%d", array[r][c]);

            else
                for (int r = rows; r >= 0; r--)
                    for (int c = columns; c >= 0; c--)
                        if(c % columns == 0)
                            printf("\n\t%d", array[r][c]);
                        else
                            printf("\t%d", array[r][c]);

        } else errArrMsg;
    }

    // Clears a bidimensional array, populating it with 0's (zeros).
    void clearIntMatrix(int **array, size_t rows, size_t columns) {
        if(rows > 0 && columns > 0)
            for (int r = 0; r < rows; r++)
                for (int c = 0; c < columns; c++)
                    array[r][c] = 0;
        else
            err2DArrMsg;
    }