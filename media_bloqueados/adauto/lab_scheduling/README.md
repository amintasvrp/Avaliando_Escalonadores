
Para realizar a atividade propomos o algoritmo para o escalonador, baseado nos seguintes passos:

**Passos:**

  0) O escalonador escolhe o processo de maior prioridade temporária (menor valor);
  1) Ao largar a CPU, o escalanador verifica se ele já rodou a quantidade de vezes da fatia de tempo (baseado no getusage), caso positivo, a prioridade temporária é incrementada segundo a lógica abaixo:
 ```c
"pusage % (33 - pprio) >= 32 - pprio";
// pusage - Varivel resposanvel para contar quantas vezes o processo já rodou
// pprio - Prioridade do processo
```
        

    
    
  2) Processo que não pegaram a CPU tem sua prioridade decrementada por 1, também no evento de largar a CPU;
  
  Obs.: 
        * Novos processos são adicionados na fila de acordo com a política do xv6;
