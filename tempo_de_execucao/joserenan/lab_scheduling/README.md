## Estratégia de escalonamento

Implementar um escalonador de processos que a cada "tempo de CPU" decrementa o peso dos processos de menor prioridade, de modo a prover a todos os processos pelo menos um tempo de CPU. Após cada os processo executar (atingir a prioridade mínima), a prioridade é restaurada para a original definida inicialmente pelo usuário e um novo ciclo é iniciado.
