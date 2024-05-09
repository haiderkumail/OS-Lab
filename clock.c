#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    while (1) {
        // Getting current time
        time_t currentTime;
        struct tm *localTime;
        time(&currentTime);
        localTime = localtime(&currentTime);

        // Displaying current time
        printf("%02d:%02d:%02d\r", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
        fflush(stdout); // Flush the output buffer to display immediately
        sleep(1);

        // Check for exit condition
        int choice;
        printf("\nEnter 0 to go to the main menu: ");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }
    }
    return 0;
}

