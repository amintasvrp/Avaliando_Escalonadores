#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int
main(int argc, char *argv[]) {
   char *x = argv[1];
   char *y = argv[2];


   if(*x >= '0' && *x <= '9' && *y >= '0' && *y <= '9') {
      printf(1, "%d\n", setpriority(atoi(argv[1]),atoi(argv[2])));
   } else {
      printf(1, "%d\n",-1);
   }
    exit();
}