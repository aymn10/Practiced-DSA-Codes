// Problem: Write a C program to count the occurrences of each word in a given text
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LEN 50

int main() {
    char text[1000];
    char words[MAX_WORDS][MAX_LEN];
    int count[MAX_WORDS] = {0};
    int wordCount = 0;

    printf("Enter a line of text:\n");
    fgets(text, sizeof(text), stdin);

    int i = 0;
    while (text[i] != '\0') {
        while (text[i] && !isalnum(text[i])) i++;
        if (text[i] == '\0') break;

        char word[MAX_LEN];
        int j = 0;
        while (text[i] && isalnum(text[i])) {
            word[j++] = tolower(text[i]);
            i++;
        }
        word[j] = '\0';

        int found = 0;
        for (int k = 0; k < wordCount; k++) {
            if (strcmp(words[k], word) == 0) {
                count[k]++;
                found = 1;
                break;
            }
        }
        if (!found && wordCount < MAX_WORDS) {
            strcpy(words[wordCount], word);
            count[wordCount] = 1;
            wordCount++;
        }
    }

    printf("\nWord occurrences:\n");
    for (int k = 0; k < wordCount; k++) {
        printf("%s : %d\n", words[k], count[k]);
    }

    return 0;
}