#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  if (argc > 2) {
      int pid = atoi(argv[1]);
      int prio = atoi(argv[2]);
      if (pid == 0 && argv[1][0] != '0') {
        printf(1, "error: PID has to be a positive number\n");
        exit();
      } else if ((prio == 0 && argv[2][0] != '0') || (prio > 31 || prio < 0)) {
        printf(1, "error: priority has to be a number between 0 and 31\n");
        exit();
      }
    
      int previous = getpriority(pid);
      if (setpriority(pid, prio) == -1)
          printf(1, "error: there is no process with the specified PID\n");
      else
          printf(1, "%d\n", previous);

      exit();
  }

  exit();
}
