#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *f;
    char sentence[100];
    char ch;
    int lineCount = 0;
     // open the file in append mode;
    f = fopen("a.txt", "a");
    // 

    if(f == NULL)
    {
        printf("unable to create or open the file.\n");
        return 1; // exit the program with an error;
    }

    printf("enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // append the sentence to the file
    fprintf(f, "%s", sentence);

    // close the file 
    fclose(f);

    f = fopen("a.txt", "r");
    if(f == NULL){
        printf("unable to open the file\n");
        return 1;
    }
    printf("contetn opf teh file: \n");

    // read and priint each character untill end of the file
    while((ch = fgetc(f)) != EOF){
        printf("%c", ch);
    }
    
    // Read and count the number of lines
    while ((ch = fgetc(f)) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }
    }


    fclose(f);
    printf("Number of lines in the file: %d\n", lineCount);

    return 0;
}
