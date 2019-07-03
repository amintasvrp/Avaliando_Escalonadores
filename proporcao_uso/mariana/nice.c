#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

// 1 - getpriority( pid )
// 2 - setpriority( pid, priority )
// 3 - getusage( pid )

int
main(int argc, char *argv[])
{
    int pid, prio;
    if (argc > 2) {
        if (atoi(argv[1]) == 1) {
            pid = atoi(argv[2]);
            getpriority(pid);
        } else if (argc > 3 && atoi(argv[1]) == 2) {
            pid = atoi(argv[2]);
            prio = atoi(argv[3]);
            setpriority(pid, prio);
        } else if (atoi(argv[1]) == 3){
            pid = atoi(argv[2]);
            getusage(pid);
        }
    }
    exit();
} 