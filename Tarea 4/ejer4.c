#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t f1, f2, f11, f12, f13, f21, f22, f23;
    f1 = fork();
    f2 = fork();

    for (int i = 0; i < 2; i++) {
        if (f1 == 0){ // Hijo 1
            f11 = fork();
            f12 = fork();
            f13 = fork();
            if (f11 == 0) sleep(20); // Nieto 1-1
            else if (f12 == 0) sleep(20); // Nieto 1-2
            else if (f13 == 0) sleep(20); // Nieto 1-3
            else sleep(20); // Hijo 1 sleep
        }
        else if(f2 == 0){ // Hijo 2
            f21 = fork();
            f22 = fork();
            f23 = fork();
            if (f21 == 0) sleep(20); // Nieto 2-1
            else if (f22 == 0) sleep(20); // Nieto 2-2
            else if (f23 == 0) sleep(20); // Nieto 2-3
            else sleep(20); // Hijo 2 sleep
        } else {
            // Proceso padre
            sleep(5);
            kill(f11, -9); // Mata Nieto 1-1
            kill(f12, -9); // Mata Nieto 1-2
            kill(f13, -9); // Mata Nieto 1-3
            kill(f1, -9); // Mata Hijo 1
            kill(f21, -9); // Mata Nieto 2-1
            kill(f22, -9); // Mata Nieto 2-2
            kill(f23, -9); // Mata Nieto 2-3
            kill(f2, -9); // Mata Hijo 2
        }
    }

    return 0;
}