#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> // Para manejar los hilos

// Función que ejecutará el hilo
void* thread_function(void* arg) {
    printf("Thread created in process (PID: %d)\n", getpid());
    return NULL;
}

int main() {
    pid_t pid;

    // Primera bifurcación (fork)
    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) { // Proceso hijo
        printf("Child process (PID: %d) created by parent (PID: %d)\n", getpid(), getppid());
        
        // Segunda bifurcación (fork) dentro del hijo
        fork();

        // Crear un hilo en el proceso hijo
        pthread_t thread;
        if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
            perror("Thread creation failed");
            exit(1);
        }

        // Espera a que el hilo termine
        pthread_join(thread, NULL);
    }

    // Tercera bifurcación (fork)
    fork();

    // Poner un pequeño delay para evitar que los procesos terminen muy rápido
    sleep(1);
    
    return 0;
}
