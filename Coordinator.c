#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 6) {
        printf("Incorrect number of arguments\n Expected: 5\n Actual: %i\n", argc);
    }
    int index = 1;
    for (int i = 0; i < 4; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            return 1;
        }
        else if (pid == 0) {
            index++;
            char *args[] = {"./Checker", argv[1], argv[index + 1], NULL};
            printf("Coordinator: child process [%i] returned %i", (int) getpid(), 1);
            printf("Coordinator: forked process with ID %i", (int) getpid());
            execvp(args[0], args);
            perror("exec failed");
            return 1;
        }
        else {
            int status;
            wait(&status);
        }
    }
    return 0;
}