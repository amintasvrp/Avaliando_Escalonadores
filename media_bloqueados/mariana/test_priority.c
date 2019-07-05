#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


//Programa criado para testar o escalonador implementado

int poww(int x, int y) {
    int i;

    for (i = 0; i < y; i++) {
        x = x * y; 
    }

    return x;
}


int
main(int argc, char *argv[])
{
    long long aux = 100000000;
    int i;
    int a;

    if (fork() == 0) {
        int prio = 1;
        int pid = getpid();
        
        setpriority(getpid(), prio);
        printf(1, "%s %d %s %d\n", "processo", pid, " prioridade ", prio);

        for(i = 0; i < aux; i++) {
            a = poww(2, 10);
        }
        printf(1, "%s %d %s %d\n", "processo", pid, " uso ", getusage(pid));
        printf(1, "%d\n", a);
        exit();
    }
    if (fork() == 0) {
        int prio = 15;
        int pid = getpid();
        
        setpriority(getpid(), prio);
        printf(1, "%s %d %s %d\n", "processo", pid, " prioridade ", prio);

        for(i = 0; i < aux; i++) {
            a = poww(2, 10);
        }
        printf(1, "%s %d %s %d\n", "processo", pid, " uso ", getusage(pid));
        printf(1, "%d\n", a);
        exit();
    }
    if (fork() == 0) {
        int prio = 31;
        int pid = getpid();
        
        setpriority(getpid(), prio);
        printf(1, "%s %d %s %d\n", "processo", pid, " prioridade ", prio);

        for(i = 0; i < aux; i++) {
            a = poww(2, 10);
        }
        printf(1, "%s %d %s %d\n", "processo", pid, " uso ", getusage(pid));
        printf(1, "%d\n", a);
        exit();
    }
    if (fork() == 0) {
        int prio = 20;
        int pid = getpid();
        
        setpriority(getpid(), prio);
        printf(1, "%s %d %s %d\n", "processo", pid, " prioridade ", prio);

        for(i = 0; i < aux; i++) {
            a = poww(2, 10);
        }
        printf(1, "%s %d %s %d\n", "processo", pid, " uso ", getusage(pid));
        printf(1, "%d\n", a);
        exit();
    }
    if (fork() == 0) {
        int prio = 12;
        int pid = getpid();
        
        setpriority(getpid(), prio);
        printf(1, "%s %d %s %d\n", "processo", pid, " prioridade ", prio);

        for(i = 0; i < aux; i++) {
            a = poww(2, 10);
        }
        printf(1, "%s %d %s %d\n", "processo", pid, " uso ", getusage(pid));
        printf(1, "%d\n", a);
        exit();
    }
    if (fork() == 0) {
        int prio = 15;
        int pid = getpid();
        
        setpriority(getpid(), prio);
        printf(1, "%s %d %s %d\n", "processo", pid, " prioridade ", prio);

        for(i = 0; i < aux; i++) {
            a = poww(2, 10);
        }
        printf(1, "%s %d %s %d\n", "processo", pid, " uso ", getusage(pid));
        printf(1, "%d\n", a);
        exit();
    }

    exit();
}