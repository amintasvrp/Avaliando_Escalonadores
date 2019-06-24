#include "types.h"
#include "stat.h"
#include "user.h"

typedef int bool;
#define TRUE  1
#define FALSE 0

void error_handler(bool condition, char *msg) {
  if(condition) {
    printf(2, "%s", msg);
    exit();
  }
}

int main(int argc, char *argv[]) {
    int pid = atoi(argv[1]);
    int new_priority = atoi(argv[2]);

    error_handler(argc < 3, "USAGE: nice pid new_priority\n");

    int previous_priority = getpriority(pid);

    error_handler(previous_priority < 0, "no process found for the passed pid\n");

    printf(2, "previous priority %d\n", previous_priority);
    setpriority(pid, new_priority);

    printf(2, "current priority %d\n", getpriority(pid));
    return exit();
}