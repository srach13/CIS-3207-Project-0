#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1024;

int main(int argc, char* argv[]) {
    char line[1024];
    if(argc == 1) {     //case where there's 1 argument
        exit(1);
    } else if(argc == 2) {  //case with 2 arguments makes argv[1] searchTerm
        char* searchTerm = argv[1];
        while(!feof(stdin)) {   //read input until terminated by user
            fgets(line,sizeof(line),stdin);
            line[strlen(line)-1]='\0';
            if(strstr(line,searchTerm)) {
                printf("%s\n",line);
            }
        }
    } else if(argc > 2) {
        char* searchTerm = argv[1];
        char buffer[MAX_SIZE];
        int i;
        for(i=2;i<argc;i++) {
            FILE *fp = fopen(argv[i],"r");
            if(fp==NULL) {
                printf("cannot open file\n");
                exit(1);
            }
        }
    }
}
