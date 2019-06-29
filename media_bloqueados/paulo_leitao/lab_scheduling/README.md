# Laboratório 3 - Escalonamento

O novo escalonador, baseado em prioridade, funcionará da seguinte forma: primeiro serão escolhidos para rodar apenas os processos de prioridade 0. Em seguida, serão escolhidos os processos de prioridades 0 e 1, e assim por diante. Após a iteração em que o escalonador escolherá processos de qualquer prioridade (de 0 a 31), ele voltará a escolher apenas processos de prioridade 0, depois os de prioridade 0 e 1, etc.

As alterações necessárias são: adicionar um contador ao escalonador atual, incrementando-o sempre que ele terminar de iterar sobre a tabela de processos; e realizar uma verificação dentro do laço que itera sobre a tabela de processos para garantir que serão escolhidos apenas processos de prioridade igual ou menor ao valor do contador.