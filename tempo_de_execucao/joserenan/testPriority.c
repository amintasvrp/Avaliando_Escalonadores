#include "types.h"
#include "stat.h"
#include "user.h"
int
main(int argc, char **argv){
    int soma = 0;
    if(fork() == 0){
        setpriority(getpid(), 31);
        for(int i = 0; i < 1000000000; i++) {
            soma += i;
        }
        printf(1, "processo %d terminou com a soma: %d\n", getpid(), soma);
        getallpids();
        exit();
    }

    if(fork() == 0){
        setpriority(getpid(), 21);
        for(int i = 0; i < 1000000000; i++) {
            soma += i;
        }
        printf(1, "processo %d terminou com a soma: %d\n", getpid(), soma);
        getallpids();
        exit();
    }

    if(fork() == 0){
        setpriority(getpid(), 0);
        for(int i = 0; i < 1000000000; i++) {
            soma += i;
        }
        printf(1, "processo %d terminou com a soma: %d\n", getpid(), soma);
        getallpids();
        exit();
    }
    wait();
    wait();
    wait();
    exit();
}
