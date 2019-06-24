#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  if(argc < 2 || argc > 3){
    printf(2, "usage: setpriority pid priority\n");
    exit();
  }
  int pid = atoi(argv[1]);
  int priority = atoi(argv[2]);

  if(priority < 0 || priority > 31){
    printf(2, "usage: setpriority pid priority (priority must be between 0 and 1)\n");
  }

  setpriority(pid, priority);
  exit();
}
