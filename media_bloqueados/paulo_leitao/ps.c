#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char* argv[]) {
    int pid, usage, priority;
    printf(1, "NAME\tPID\tUSAGE\tPRIORITY\n");
    for (int i = 0; i < 64; i++) {
        pid = i;
        usage = getusage(i);
        priority = getpriority(i);
        getname(i);
        if (usage > 0) {
            printf(1, "\t%d\t%d\t%d\n", pid, usage, priority);
        }
    }
    exit();
}
