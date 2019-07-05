#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "date.h"

unsigned long randstate = 1;

unsigned int rand() {
 randstate = randstate * 1664525 + 1013904223 + randstate/132345;
 return randstate;
}

void process(int process_PID) {
 long long n = 1e9;

 int start_time = uptime();

 printf(1,"Process PID: %d \t Priority: %d\n", process_PID,getprio(getpid()));

 long long  count = 0;
 while (n) {
   count = count + rand();
   n -= 1;
 }

 int end_time = uptime();
 int total_time = end_time - start_time; // Calculating time of process

 printf(1,"Processing time:  %d (ms) \t Process PID: \n", total_time,process_PID);
 exit();
}

int main() {

 if (fork()) { // Parent process PID 1
   setprio(getpid(),31);
   process(1);
 }

 if (fork()){ // Parent process PID 2
   process(2);
 }

 // Parent process PID 3
 setprio(getpid(),0);
 process(3);

 exit();
}