#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *targetFile;
    char sourceFileName[100], targetFileName[100];
    char ch;

    // Get the name of the file to be copied
    printf("Enter the name of the file to be copied: ");
    scanf("%s", sourceFileName);

    // Open the source file in read mode
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Error! Unable to open the file.\n");
        exit(EXIT_FAILURE);
    }

    // Get the target destination
    printf("Enter the target destination (including file name): ");
    scanf("%s", targetFileName);

    // Open the target file in write mode
    targetFile = fopen(targetFileName, "w");
    if (targetFile == NULL) {
        fclose(sourceFile);
        printf("Error! Unable to create the target file.\n");
        exit(EXIT_FAILURE);
    }

    // Copy contents of source file to target file
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, targetFile);
    }

    printf("File copied successfully.\n");

    // Close files
    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}
