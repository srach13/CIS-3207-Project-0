#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse(char *line) {     //passes in a string and returns the string in reverse
    char *reverse_string = (char *)malloc(sizeof(char *));  //make a new string and get length using malloc
    if (reverse_string == NULL) { // malloc fails error
        fprintf(stderr, "malloc failed \n");
        exit(1);
    }
    int ending = strlen(line) - 1;    //starting from the end of the last word
    int reverse_string_index = 0;
    for (int i = strlen(line) - 1; i >= 0; i--) {   //for loop that iterates through the input string
        if (line[i] == ' ') {
            for (int j = i + 1; j <= ending; j++) {     //start from the current index +1 to end
                reverse_string[reverse_string_index] = line[j];     //copy the word to the reverse string
                reverse_string_index++;
            }
            reverse_string[reverse_string_index++] = ' ';
            ending = i - 1;    //update ending point
        }
    }
    for (int i = 0; i <= ending; i++) {     //add the last word
        reverse_string[reverse_string_index] = line[i];
        reverse_string_index++;
    }
    reverse_string[reverse_string_index] = '\0';
    return reverse_string;
}

int main(int argv, char **argc) {
    if (argv > 3) {     //error: more than 3 arguments
        fprintf(stdout, "usage: reverse <input> <output>");
        exit(1);
    }
    else if (argv == 3) {
        if (strcmp(argc[1], argc[2]) == 0) {    //check if input file and output file are same
            fprintf(stderr, "%s", "Input and output file must differ\n");
            exit(1);
        }

        FILE *inputFile;
        inputFile = fopen(argc[1], "r");
        FILE *outputFile;
        outputFile = fopen(argc[2], "w");
        if (inputFile == NULL) {    //error opening file
            fprintf(stderr, "error: cannot open file \'%s\' \n", argc[1]);
            exit(1);
        }
        if (outputFile == NULL) {  //error opening file
            fprintf(stderr, "error: cannot open file \'%s\' \n", argc[2]);
            exit(1);
        }

        char *line = NULL;  //reads from input file
        size_t len = 0;
        ssize_t line_size = 0;
        while ((line_size = getline(&line, &len, inputFile)) != -1) {
            line[line_size - 1] = '\0';     //removes the newline character
            char *reverse_str = reverse(line);   //calls reverse string function
            fprintf(outputFile, "%s\n", reverse_str);   //writes the reversed line to output file
        }
    }

    else if (argv == 2) {    //2 arguments are passed
        FILE *inputFile;
        inputFile = fopen(argc[1], "r");
        if (inputFile == NULL) {    //error opening file
            fprintf(stderr, "error: cannot open file \'%s\' \n", argc[1]);
            exit(1);
        }

        char *line = NULL;
        size_t len = 0;
        ssize_t line_size = 0;
        while ((line_size = getline(&line, &len, inputFile)) != -1) {     //reading input file
            line[line_size - 1] = '\0';     //remove newline character from line
            fprintf(stdout, "%s\n", reverse(line));  //print to standard output the reverse of the line read
        }
    }

    else if (argv == 1) {    //1 argument is passed
        fprintf(stdout, "Enter a string:");     //gets input string from standard input
        char *str = (char *)malloc(sizeof(char *)); //declares string to store user input using malloc to allocate space
        if (str == NULL) {    //error: malloc failed
            fprintf(stderr, "malloc failed \n");
            exit(1);
        }
        gets(str);
        fprintf(stdout, "%s\n", reverse(str));
    }
    return 0;
}