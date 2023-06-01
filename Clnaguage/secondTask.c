#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    char sentence[100];
    char ch;
    int lineCount = 0;

    f = fopen("a.txt", "a");

    if (f == NULL) {
        printf("unable to create or open the file.\n");
        return 1; 
    }

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    fprintf(f, "%s", sentence);

    fclose(f);

    f = fopen("a.txt", "r");
    if (f == NULL) {
        printf("unable to open the file\n");
        return 1;
    }
    printf("Content of the file:\n");

    while ((ch = fgetc(f)) != EOF) {
        printf("%c", ch);
        if (ch == '\n') {
            lineCount++;
        }
    }

    fclose(f);
    printf("Number of lines in the file: %d\n", lineCount);

    return 0;
}
