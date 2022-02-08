#include "types.h"
#include "user.h"

int main (int argc, char *argv[]){
    
    int sys_a = 0; 
    int real_a = uptime();

    int pid;

    
    //printf(1,"argv[k] -> %s \n", argv[k]);
    pid = fork();
    if (pid == 0){
        exec(argv[1], argv);
        exit();
    }else{
        pid = fork();
        if (pid == 0){
            exec(argv[1], argv);
            exit();
        }else{
            printf(1,"pid -> %d",pid);
            setprio(2,pid);
            waitAux(&sys_a);
        }
        waitAux(&sys_a);
    }
    
    
    
    int real_b = uptime();

    int real = (real_b - real_a)*10;
    int sys = (sys_a)*10;
    int user = real - sys;
    printf(1, "real: %dm%d.%ds\n", (real/60000),(real/1000),real);
    printf(1, "sys: %dm%d.%ds \n", (sys/60000),(sys/1000),sys);
    printf(1, "user: %dm%d.%ds \n", (user/60000),(user/1000),user);
	exit();
}