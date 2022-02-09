#include "types.h"
#include "user.h"
#include <stddef.h>


void exec_processo(int numero_execucoes, char *argv[]){
    if(argv[numero_execucoes] == NULL)
        return;

    int pid;
    pid = fork();
    if (pid == 0){
        exec(argv[numero_execucoes], argv);
        exit();
    }else{
        exec_processo(++numero_execucoes,argv);
        wait();
    }
}

int main (int argc, char *argv[]){
    exec_processo(1,argv);
	exit();
    
    return 0;
}

