#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 6) {
        printf("Incorrect number of arguments\n Expected: 5\n Actual: %i\n", argc);
    }
    pid_t pid = fork();

    if (pid < 0) {
        return 1;
    }
    else if (pid == 0) {
        char *args[] = {"./Checker", argv[1], argv[2], NULL};
        printf("child process beginning");
        execvp(args[0], args);
        perror("exec failed");
        return 1;
    }
    else {
        wait(NULL);
    }

    printf("Coordinator:\n");
}