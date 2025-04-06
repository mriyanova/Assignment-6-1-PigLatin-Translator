#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

int is_vowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void word_to_piglatin(char *word, char *result) {
    if (is_vowel(word[0])) {
        sprintf(result, "%syay", word);
    } else {
        int i = 0;
        while (word[i] && !is_vowel(word[i])) i++;
        sprintf(result, "%s%.*say", word + i, i, word);
    }
}

int main() {
    char input[MAX_LEN], word[100], result[100], output[MAX_LEN] = "";
    printf("Enter a sentence to translate: ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = '\0';  // remove newline

    char *token = strtok(input, " ");
    while (token) {
        word_to_piglatin(token, result);
        strcat(output, result);
        strcat(output, " ");
        token = strtok(NULL, " ");
    }

    printf("Pig Latin: %s\n", output);
    return 0;
}
