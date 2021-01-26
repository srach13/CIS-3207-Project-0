#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 64

int main(int argc, char* argv[]) {
    if (argc == 1) {    //no files specified error
        exit(0);
    }
    char buffer[MAX_SIZE];  //buffer string for reading from file
    int i;
    for (i=1; i<argc; i++) {                       //for loop to iterate
        FILE *fp = fopen(argv[i], "r");
        if (fp==NULL) {                            //error message for NULL file
            printf("Cannot open file\n");
            exit(0);
        }
        while (fgets(buffer, MAX_SIZE, fp) != NULL) { //reads from file in buffer
            printf("%s", buffer);                //prints content of file to standard output
        }
        fclose(fp);
    }
    return 0;
}


