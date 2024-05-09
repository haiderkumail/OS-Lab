#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[50];
    FILE *fp;
    char ch;

    printf("Enter the name of the file to create or open: ");
    scanf("%s", filename);

    // Opening the file in read mode
    fp = fopen(filename, "r");

    // If the file does not exist, create a new one
    if (fp == NULL) {
        printf("File does not exist. Creating a new one.\n");
        fp = fopen(filename, "w");
        fclose(fp);
        fp = fopen(filename, "r");
    }

    printf("File contents:\n");
    ch = fgetc(fp);
    while (ch != EOF) {
        printf("%c", ch);
        ch = fgetc(fp);
    }

    fclose(fp);

    printf("\n\nEnter the text to append to the file: ");
    getchar(); // Clearing the input buffer
    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error in opening the file.");
        exit(1);
    }

    // Writing text to the file
    while ((ch = getchar()) != EOF) {
        fputc(ch, fp);
    }

    fclose(fp);

    printf("Text appended successfully.\n");

    return 0;
}

