#include "types.h"
#include "stat.h"
#include "user.h"

void nice(int pid, int prio){
    setprio(pid, prio);
    
}

int main(int argc, char *argv[]){
    int pid, prio;

    if(argc <= 2){
        printf(1,"Missing arguments!");
        exit();
    }

    pid = atoi(argv[1]);
    prio = atoi(argv[2]);

    nice(pid, prio);
    exit();

}