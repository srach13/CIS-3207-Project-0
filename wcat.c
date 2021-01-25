#include <stdio.h>
#include <stdlib.h>
#define SIZE 64 //SIZE is the max size of buffer string used by fgets

//main function
int main(int argc, char* argv[]) {
    if (argc == 1) {
        exit(0);
    }
    char buffer[SIZE];          //buffer string for reading from file
    int i;
    for (i = 1; i < argc; i++) {                 //iterate
        FILE *fp = fopen(argv[i], "r");     //argv[i] is filename
        if (fp == NULL) {
            printf("cannot open file\n");
            exit(0);                        //error if file is NULL
        }
        while (fgets(buffer, SIZE, fp) !=
               NULL) {   //reads from file in buffer, if it returns NULL then there is no content to read from file
            printf("%s", buffer);                //prints content of file to standard output
        }
        printf("\n"); //new line to separate different files
        fclose(fp);
    }
    return 0;
}


