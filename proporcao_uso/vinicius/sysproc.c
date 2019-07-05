#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "spinlock.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}


struct {
  struct spinlock lock;
  struct proc proc[NPROC];
} ptable;


void killRandomProc(void){
  //int n = rand() % 64;
  int n = 6; //sem tempo pra ver o random
  int act = 0;
  struct proc *p;
  for(p = ptable.proc; p < &ptable.proc[NPROC]; p++, act++){
    if(act == n) kill(p->pid);
  }
}



// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  int MAX_INTERRUPT = 32;
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  if(xticks > MAX_INTERRUPT){
    killRandomProc();
  }
  return xticks;
}

int sys_getprio(void){
  int pid;
  if(argint(0, &pid) < 0)
    return -1;
  return getprio(pid);
}

int sys_setprio(void){
  int pid;
  int prio;
  if(argint(0, &pid) < 0 || argint(1, &prio) < 0)
    return -1;
  return setprio(pid,prio);
}

int sys_getusage(void){
  int pid;
  if(argint(0, &pid) < 0)
    return -1;
  return getusage(pid);
}

