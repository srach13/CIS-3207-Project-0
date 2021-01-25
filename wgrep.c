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
}