#include "types.h"
#include "user.h"
#include <stddef.h>


void exec_processo(int numero_execucoes, char *argv[]){
    if(argv[numero_execucoes] == NULL)
        return;

    printf(1,"numero_execucoes -> %d, argv[numero_execucoes] -> %s", numero_execucoes,argv[numero_execucoes]);
    //char* params[1] = { argv[numero_execucoes] };
    argv[2] = argv[numero_execucoes];
    int pid;
    pid = fork();
    if (pid == 0){
        exec(argv[1], argv);
        exit();
    }else{
        exec_processo(++numero_execucoes,argv);
        wait();
    }
}

int main (int argc, char *argv[]){
    printf(1,"Chegou aqui.");

    int count = 2; 
    //char *param_exec[];
    
    exec_processo(count,argv);

    /*while(argv[++count] != NULL){
        //char* params[3] = { argv[0], argv[1], argv[count] };
        pid = fork();
        if (pid == 0){
            exec(argv[1], argv);
            exit();
        }else{

            wait();
        }
    }*/
	exit();
}

