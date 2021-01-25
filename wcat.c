#include <stdio.h>
#include <stdlib.h>
#define SIZE 64 //SIZE is the max size of buffer string used by fgets

//main function
int main(int argc, char* argv[]) {
    if(argc==1) {
        exit(0);
    }
    char buffer[SIZE];          //buffer string for reading from file
}
int i;
for(i=1; i<argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if(fp==NULL) {
        printf("cannot open file\n");
        exit(0);
    }
    while(fgets(buffer, SIZE, fp)!=NULL) {
        printf("%s",buffer);
    }
    fclose(fp);
}
return 0;


