// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

// TO COMPILE THIS PROGRAM >>> `gcc [NAME OF FILE].c -o [NAME OF EXECUTABLE]`

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here    
    printf("Parent process here\n");
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child process here\n");

        // THESE ARE ALL DIFFERENT 'EXEC' METHODS AND DO THE SAME THING

        // execl("/bin/ls", "ls", "-l" (char *) NULL);

        // char *args[] = {"ls", "-l" (char *) NULL};
        // execv("/bin/ls", args);

        // execlp("ls", "ls", "-l", (char *) NULL);

        char *args[] = {"ls", "-l", NULL};
        execvp("ls", args);
    } else {
        wait(NULL);
    }
    return 0;
}
