#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{

  if(argc < 1){
    printf(2, "usage: getpriority pid...\n");
    exit();
  }
 
  int pid = atoi(argv[1]);

  printf(2, "Priority of #%d is %d\n", pid, getpriority(pid)) ;
  exit();
}
