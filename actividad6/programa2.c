#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Error al crear el proceso hijo
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Proceso hijo
        printf("Child process (PID: %d) is terminating.\n", getpid());
        _exit(0); // Termina el proceso hijo
    } else {
        // Proceso padre
        printf("Parent process (PID: %d) created a child process (PID: %d).\n", getpid(), pid);
        sleep(60); // Duerme durante 60 segundos
        printf("Parent process (PID: %d) is terminating.\n", getpid());
        wait(NULL); // Espera al proceso hijo para limpiarlo
    }

    return 0;
}