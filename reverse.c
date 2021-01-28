#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse(char *line) {     //takes in a string and returns the string in reverse
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
