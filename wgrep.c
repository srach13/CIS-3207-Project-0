#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char *filename=NULL, *searchTerm;
    FILE *fp;
    char line[1024];
    int isFile=0;

    if(argc<2){     //case where it is passed no arguments
        printf("grep:searchterm filename\n");
        return 1;
    }
    else if(argc<3) {
        searchTerm=(char*)malloc(strlen(argv[argc-1])+1);
        strcpy(searchTerm,argv[argc-1]);
    }

}



