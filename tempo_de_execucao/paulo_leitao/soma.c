#include "types.h"
#include "user.h"
#include "stat.h"

int main (int argc, char* argv[]) {
    if (argc > 1) {
        int priority = atoi(argv[1]);
        int pid = getpid();
        setpriority(pid, priority);
        while (1) {}
    } else {
        printf(1, "error: missing priority");
        exit();
    }
}
