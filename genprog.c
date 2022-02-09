#include "types.h"
#include "user.h"
#include <stddef.h>

#define MAX_DURATION 12000

int main (int argc, char *argv[]){

    int startTime = uptime();

    int duration;

    if (argv[1] != NULL) {
        duration = atoi(argv[1]);
    } else {
        duration = MAX_DURATION;
    }

    while(1) {
        if (uptime() - startTime > duration) {
            exit();
            return 0;
        }
    }
}