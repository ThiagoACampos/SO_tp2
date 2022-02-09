#include "types.h"
#include "user.h"
#include <stddef.h>

int main() {

    printf(1, "\n\n======= Caso de Teste 1 ========\n\n");

    char* longProg[1] = { "genprog" };

    int pid;

    // Primeiro processo
    pid = fork();
    if (pid == 0) {
        exec(longProg[0], longProg);
        exit();
    } else {
        setprio(5, pid);
        printf(1, "\nAlocando processo P%d com prioridade 5\n", pid);

        // Segundo processo
        int pid = fork();
        if (pid == 0) {
            exec(longProg[0], longProg);
            exit();

        } else {            
            setprio(5, pid);
            printf(1, "\nAlocando processo P%d com prioridade 5\n", pid);

            // Espera para adicionar na proxima janela
            int startTime = uptime();
            while(uptime() - startTime < 1000) {}

            // Terceiro processo
            int pid = fork();
            if (pid == 0) {
                exec(longProg[0], longProg);
                exit();
            }else {
                setprio(3, pid);
                printf(1, "\nAlocando processo P%d com prioridade 3\n", pid);

                // Espera para adicionar na proxima janela
                sleep(1000);
                
                // Quarto processo
                int pid = fork();
                if (pid == 0) {
                    exec(longProg[0], longProg);
                    exit();
                }else {
                    printf(1, "\nAlocando processo P%d com prioridade 1\n", pid);
                    wait();
                }
                wait();
            }
            wait();
        }
        wait();
    }

    exit();

    return 0;
}