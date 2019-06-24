#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{

  if(argc < 1){
    printf(2, "usage: getusage pid...\n");
    exit();
  }
 
  int pid = atoi(argv[1]);

  printf(2, "Usage of #%d is %d\n", pid, getusage(pid)) ;
  exit();
}
