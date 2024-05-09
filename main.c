#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

void *clock_task(void *arg) {
    // Function to display current time
    printf("Clock task is running...\n");
    // Execute clock functionality
    execlp("./clock", "clock", NULL);
    // If execlp fails
    perror("exec");
    exit(EXIT_FAILURE);
}

void *background_music_task(void *arg) {
    // Function to play background music
    printf("Background music task is running...\n");
    // Execute background music functionality
    execlp("./background_music", "background_music", NULL);
    // If execlp fails
    perror("exec");
    exit(EXIT_FAILURE);
}

void *calculator_task(void *arg) {
    printf("Calculator is running...\n");
    execlp("./calculator", "calculator", NULL);
    
    // If execlp fails
    perror("exec");
    exit(EXIT_FAILURE);
}

void *notepad_task(void *arg) {
    printf("Notepad is running...\n");
    execlp("./notepad", "notepad", NULL);
    
    // If execlp fails
    perror("exec");
    exit(EXIT_FAILURE);
}

void *create_task(void *arg) {
    printf("Create file is running...\n");
    execlp("./create_file", "create_file", NULL);
    
    // If execlp fails
    perror("exec");
    exit(EXIT_FAILURE);
}

void *copy_task(void *arg) {
    printf("Copy file is running...\n");
    execlp("./copy_file", "copy_file", NULL);
    
    // If execlp fails
    perror("exec");
    exit(EXIT_FAILURE);
}

void *delete_task(void *arg) {
    printf("Delete file is running...\n");
    execlp("./delete_file", "delete_file", NULL);
    
    // If execlp fails
    perror("exec");
    exit(EXIT_FAILURE);
}

void *move_task(void *arg) {
    printf("Move File is running...\n");
    execlp("./move_file", "move_file", NULL);
    
    // If execlp fails
    perror("exec");
    exit(EXIT_FAILURE);
}

void *fileInfo_task(void *arg) {
    printf("File Info is running...\n");
    execlp("./file_info", "file_info", NULL);
    
    // If execlp fails
    perror("exec");
    exit(EXIT_FAILURE);
}

void *print_task(void *arg) {
    printf("Print File is running...\n");
    execlp("./print_file", "print_file", NULL);
    
    // If execlp fails
    perror("exec");
    exit(EXIT_FAILURE);
}

void *game_task(void *arg) {
    printf("Game is running...\n");
    execlp("./minigames", "minigames", NULL);
    
    // If execlp fails
    perror("exec");
    exit(EXIT_FAILURE);
}

void *shutdown_task(void *arg) {
    printf("Shutting Down...\n");
    execlp("./shutdown", "shutdown", NULL);
    
    // If execlp fails
    perror("exec");
    exit(EXIT_FAILURE);
}

// Define functions for other tasks similarly...

int main() {
    // Welcome message
    printf("Welcome to MyOS!\n");
    // Start system startup simulation
    printf("System is starting...\n");
    while(1){
      	    // Display list of tasks
	    printf("Available tasks:\n");
	    printf("1. Clock\n");
	    printf("2. Background Music\n");
	    printf("3. Calculator\n");
	    printf("4. Notepad\n");
	    printf("5. Creat File\n");
	    printf("6. Copy File\n");
	    printf("7. Delete File\n");
	    printf("8. Move File\n");
	    printf("9. File Info\n");
	    printf("10. Print File\n");
	    printf("11. Game\n");
	    printf("12. Shutdown\n");

	    // Get user input for task selection
	    int choice;
	    printf("Enter the number corresponding to the task you want to run: ");
	    scanf("%d", &choice);

	    

	    // Create processes for the selected task
	    pid_t task_pid;
	    pthread_t task_thread;

	    // Fork a process for the selected task
	    task_pid = fork();
	    if (task_pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	    } else if (task_pid == 0) {
		// Child process: Execute the selected task
		switch (choice) {
		    case 1:
		        pthread_create(&task_thread, NULL, clock_task, NULL);
		        pthread_join(task_thread, NULL);
		        break;
		    case 2:
		        pthread_create(&task_thread, NULL, background_music_task, NULL);
			pthread_join(task_thread, NULL);
			break;
		    case 3:
		        pthread_create(&task_thread, NULL, calculator_task, NULL);
			pthread_join(task_thread, NULL);
			break;
		    case 4:
		        pthread_create(&task_thread, NULL, notepad_task, NULL);
			pthread_join(task_thread, NULL);
			break;
		    case 5:
		        pthread_create(&task_thread, NULL, create_task, NULL);
			pthread_join(task_thread, NULL);
			break;
		    case 6:
		        pthread_create(&task_thread, NULL, copy_task, NULL);
			pthread_join(task_thread, NULL);
			break;
		    case 7:
		        pthread_create(&task_thread, NULL, delete_task, NULL);
			pthread_join(task_thread, NULL);
			break;
		    case 8:
		        pthread_create(&task_thread, NULL, move_task, NULL);
			pthread_join(task_thread, NULL);
			break;
		    case 9:
		        pthread_create(&task_thread, NULL, fileInfo_task, NULL);
			pthread_join(task_thread, NULL);
			break;
		    case 10:
		        pthread_create(&task_thread, NULL, print_task, NULL);
			pthread_join(task_thread, NULL);
			break;
	            case 11:
		        pthread_create(&task_thread, NULL, game_task, NULL);
			pthread_join(task_thread, NULL);
			break;
		    case 12:
		        pthread_create(&task_thread, NULL, shutdown_task, NULL);
			pthread_join(task_thread, NULL);
			break;
		    default:
		        printf("Invalid choice.\n");
		        exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	    }

	    // Wait for the selected task process to finish
	    waitpid(task_pid, NULL, 0);
    
    }
    

    // System shutdown
    printf("System shutdown...\n");

    return 0;
}
