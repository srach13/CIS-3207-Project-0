#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1024   //max size of input string when argc==2 or buffer when argc>2

int main(int argc, char*argv[]) {
    if(argc==1) {
        exit(1);
    }
    else if(argc==2) {  //number of arguments is 2 -> use argv[1] as search
        char *search = argv[1];
        while (1) {
            char str[MAX_SIZE]; //input string of defined size MAX_SIZE
            scanf("%s", str);   //read string from standard input
            char *found = strstr(str, search);      //search given search variable in standard input
            if (found != NULL) {                     //returns NULL if it doesn't find string
                printf("%s\n", str);                //if it finds string then it prints the input string
            }
        }
    }
    else if(argc>2) {       //number of command line arguments is greater than 2
        char* search = argv[1]; //search word is argv[1]
        char buffer[MAXSIZE];     //input buffer to be used by fgets to read from file
        int i;
        for(i=2; i<argc; i++){
            FILE *fp = fopen(argv[i], "r");
            if(fp == NULL) {     //fopen returns NULL if it can't open file
                printf("cannot open file\n");
                exit(1);
            }

        }
    }
    return 0;
}

    }
}