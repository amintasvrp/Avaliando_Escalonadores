#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "date.h"

int main(int argc, char *argv[]) {
    int k, n, id;

    if(argc < 2 || argc > 32)
        n = 5;  // quant filhos default 
    else 
        n = atoi(argv[1]); // quant filhos linha comando

    int i;
    for ( i = 0; i < 50; i++)
    {
        long startTicks = uptime();  // quant ticks no início
        id = 0;
        for(k = 0; k < n; k++){
            id = fork();
            if(id == 0){ // filho

                int count = 0;
                int i = 0;
                for(i = 1; i <= 999999999;i++){
                    count = (count * 238741225925952989 + 9823444724) % 3768232368993;
                }

                exit();
            } else { // pai
                setpriority(id, k);
            }       
        }

        while (wait() != -1);


        long endTicks = uptime();  // quant ticks no final

        printf(2, "%d,", endTicks - startTicks);
    }
    
    

    exit(); 

}
