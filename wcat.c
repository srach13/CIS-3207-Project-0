#include <stdio.h>
#include <stdlib.h>

int i;
for(i=1; i<argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if(fp==NULL) {
        printf("cannot open file\n");
        exit(1);
    }
}

