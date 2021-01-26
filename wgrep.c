#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1024;

int main(int argc, char* argv[]) {
    char line[MAX_SIZE];
    if(argc < 2) {     //no arguments
        printf("wgrep:searchterm [file...]\n");
        exit(1);
    } else if(argc == 2) {  //case where there's 2 arguments
        char* searchTerm = argv[1];
        while(!feof(stdin)) {   //reads input until terminated by user
            fgets(line,sizeof(line),stdin);
            line[strlen(line)-1]='\0';
            if(strstr(line,searchTerm)) {
                printf("%s\n",line);
            }
        }
    } else if(argc > 2) {   //case where there's more than 2 arguments
        char* searchTerm = argv[1];
        char buffer[MAX_SIZE];  //input buffer to read from file
        int i;
        for(i=2;i<argc;i++) {
            FILE *fp = fopen(argv[i],"r");  //iterate over arguments
            if(fp==NULL) {      //error message
                printf("Cannot open file\n");
                exit(0);
            }
            while(fgets(buffer,MAX_SIZE,fp)!=NULL) {    //reads file into buffer string
                char *found = strstr(buffer,searchTerm);
                if(found != NULL) {     //if it comes to this line, that means there is a match in searching
                    printf("%s",buffer);    //prints line from file
                }
            }
            printf("\n");
            fclose(fp);
        }
    }
    return 0;
}
