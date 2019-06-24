
#include "types.h"
#include "stat.h"
#include "user.h"

 //From proc.h Proc structure
// Per-process state
enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };
struct proc {
  enum procstate state;        // Process state
  int pid;            // Process ID
  int ppid ;          // Parent process ID
	int priority;
	int usage;
  char name[16];               // Process name 
};

 #define MAX_PROC 50

 int
main(int argc, char *argv[]){  
  struct proc ptable[MAX_PROC];
  struct proc *p;
  int err;

  err = getptable(MAX_PROC*sizeof(struct proc),&ptable);
  if(err !=0)
    printf(1,"Error getting ptable");

  p = &ptable[0];
  printf(1, " PID  PPID   STATE    PRIORITY USAGE     CMD\n");
  while(p != &ptable[MAX_PROC-1] && p->state != UNUSED){
		if(p->pid == 1)printf(1,"  %d   USER   ", p->pid);
    else printf(1,"  %d   %d   ", p->pid, p->ppid);
  	switch(p->state){
  	case UNUSED:
  		printf(1," %s ", "UNUSED");
  		break;
  	case EMBRYO:
  		printf(1," %s ", "EMBRYO");
  		break;
  	case SLEEPING:
  		printf(1," %s ", "SLEEPING");
  		break;
  	case RUNNABLE:
  		printf(1," %s ", "RUNNABLE");
  		break;
  	case RUNNING:
  		printf(1," %s ", "RUNNING");
  		break;
  	case ZOMBIE:
  		printf(1," %s ", "ZOMBIE");
  		break;
  	} 
		printf(1,"    %d    ", p->priority);
		printf(1,"    %d ", p->usage);
  	printf(1,"      %s \n", p->name);
  	p++;
  }

   exit();
}