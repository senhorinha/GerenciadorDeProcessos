
# Atividade Prática 2 - Sistemas Operacionais I

## Envolvidos

### Autor

* [Thiago Senhorinha Rose](https://github.com/thisenrose)
* [Décio Moritz Júnior](https://github.com/deciomoritz)

### Orientador

* [Rafael Luiz Cancian](http://www.inf.ufsc.br/~cancian)

## O que fazer ##

### Descrição Geral ###

A atividade prática A2 visa avaliar as habilidades de projeto e implementação de de aplicativos que implementam as funções de Sistemas Operacionais modernos. A atividade prática A2 corresponde à implementação de um programa de computador que simule o gerenciamento de processos de um Sistema Operacional, com foco no escalonamento. Ele deve iniciar solicitando ao usuário para inserir a "carga de trabalho", ou seja, o conjunto de tarefas a serem escalonadas, o que inclui seu nome, instante de chegada, tempo de execução e demais informações necessárias ao escalonamento. Após essa inserção ser finalizada (com uma linha vazia), o sistema passa a simular seu escalonamento. Para isso, ele deve criar uma lista de PCBs, lista de processos 'Executando', lista de processos no estado 'Pronto', lista de processos no estado 'Bloqueado' e lista de processos no estado 'Terminado'. Uma iteração no programa principal pode representar a passagem de tempo e a ocorrência de uma interrupção do timer ou do término de um quantum de tempo, o que dispara a ação do escalonador. O escalonador deve ordenar a lista de processos no estado 'Pronto' conforme seu critério de escalonamento e possivelmente outras ações necessárias. Escalonar então geralmente significa mover o ponteiro para o primeiro PCB da lista 'Prontos' para 'Executando', ajustando o estado do processo. Executar significa apenas decrementar o tempo de execução restante no PCB adequado. A cada iteração o programa deve mostrar na tela o nome do programa que está executando naquele instante. Preemptar significa mover o PCB de 'Executando' para 'Pronto', e ajustar os ponteiros das listas. O bloqueio ocorrerá com probabilidade de cerca de 5%, e corresponde a mudar o PCB de 'Executando' para 'Bloqueado' e ajustar os ponteiros nas listas. O desbloqueio ocorre de forma análoga. Quando o tempo de execução restante chegar a zero, o PCB passa de 'Executando' para 'Terminado', e deve-se ajustar os ponteiros das listas. A simulação termina quando o tamanho da lista 'Terminados' for igual ao tamanho da tabela de processos (lista de PCBs), ou seja, todos os processos carregados na memória estão 'Terminados'. Nesse momento o programa deve apresentar estatísticas sobre o escalonamento e terminar.

### Detalhamento ###

A inserção da carga de trabalho deve ser de um processo por linha, com as informações separadas por espaço. O programa deve informar ao usuário quais são as informações que ele aguarda. O tempo avança de 1 em 1, a partir do tempo 0. A cada instante de tempo, deve-se apresentar na tela o instante atual e os processos que estão na lista 'Executando'. Deve-se coletar as seguintes informações sobre o escalonamento e execução dos processos: (i) instante em que o processo é escalonado pela primeira vez, o que permite calcular o tempo de resposta, (ii) instante em que o processo é terminado, o que permite calcular o turnaround e a fração de tempo de CPU utilizada pelo processo e o tempo de espera. Esses valores, para cada processo, e uma média de todos os processos, devem ser apresentados quando a simulação terminar.

Alguns algoritmos de escalonamento, em especial os de tempo-real, aceitam processos periódicos, ou seja, processos que são executados em intervalos regulares. Nesses casos, o período de cada processo deve ser inserido pelo usuário, juntamente com as demais informações do processo (o que inclui a deadline relativa, em processos de tempo-real). Além disso, mudam os seguintes aspectos em relação ao que foi descrito anteriormente: (1) A cada iteração, varre-se a lista de 'Terminados' verificando se o tempo atual é um múltiplo do 'Período' daquele processo. Se for, então ele deve ser reativado, ou seja, o PCB passa de 'Terminado' para 'Pronto', e ajustam-se os ponteiros das listas, e (2)  como os processos 'Terminados' podem ser reexecutados, a simulação não pára quando todos os processos estão terminados. O critério de parada passa a ser quando o tempo atual do sistema for igual a dez vezes o maior período de ativação dos processos. Nos casos de escalonamento de tempo-real, deve-se também calcular a seguinte estatística para cada processo, sempre que ele é terminado: a maior diferença entre o tempo atual e a deadline absoluta do processo (que deveria ser menor ou igual a zero se ele executou dentro do prazo, ou positiva, se ele atrasou).

# O que são processos

Resumidamente um processo é um programa em execução. Ele contém o código do programa e seu estado atual.Processos são módulos separados e carregáveis, ao contrário de threads, que não podem ser carregadas. Múltiplas threads de execução podem ocorrer dentro de um mesmo processo. Além das threads, o processo também inclui certos recursos, como arquivos e alocações dinâmicas de memória e espaços de endereçamento.

## Estados

Simplificadamente os estados de um processo são:

* **Ready (pronto):** Processo já carregado em memória e aguarda a troca de contexto para inciar a execução
* **Running (executando):** Um processo entrará nesse estado quando for escolhido pelo gerenciador de processos para ocupar a CPU (lembrando que apenas um processo pode estar nesse estado por CPU ou 'núcleos' do sistema) 
* **Blocked (bloqueado):** Quando um processo aguarda algum evento (por exemplo: término de alguma operação de I/O). Além disso, o gerenciador pode bloquear o processo quando seu tempo de CPU esgotar.

![imagem_dos_estados](http://www.cs.rpi.edu/academics/courses/os/c04/ProcessStates_edited.jpg)

## Prioridades

Em alguns sistemas operacionais é utilizado um número, no linux de -20 a +19, em que o processo com o menor número terá maior prioridade, ou seja, terá vantagem para execução.

## Comandos linux

Alguns comandos linux envolvendo processos. 
Retirado de [vivaolinux](http://www.vivaolinux.com.br/dica/Gerenciamento-de-processos-no-GNULinux).

```bash
ps                   # Visualiza os processos em execução
ps -a                # Exibe processos de outros usuários também
ps -u                # Exibe os processos detalhadamente inclusive com uso de memória
ps -x                # Exibe os processos que não estão vinculados a terminais
ps -ef               # Exibe todos os processos e mostra o PPID
top                  # Exibe os processos que utilizam CPU em tempo real
top -d               # Exibe os processos que utilizam CPU em tempo real com atualização de 1 seg
kill -9 (processo)   # Mata um processo
nice -n (-20 a +19) programa  # Roda o programa com a prioridade desejada
renice (-20 a +19) processo   # Permite alterar a prioridade do programa estando em execução 
```

# Gerenciador de Processos

Presente em qualquer sistema operacional moderno, o gerenciador de processos tem como função alocar recursos para os processos, permitir a troca de informação entre processos e sincronizar processos. Para realização dessas tarefas o S.O possui uma estrutura de dados (Process Control Block) para cada processo.

## Process Control Block

Os PCBS são fundamentais para gestão de processos. Eles são acessados ​​e/ou modificados pela maioria dos componentes do sistema que envolvam programação, memória, acesso a recursos de I/O e monitoramento de desempenho. Pode-se dizer que o conjunto dos PCB define o estado atual do sistema operacional.

### Estrutura

A estrutura do PCB está dividido em três categorias:

* **Process identification data (identificação):** Geralmente contem as identificações do processo (único no sistema), processo pai, usuário e grupo. Esses identificadores são importantes para referência cruzada.
* **Processor state data (estado):** Definem o estado do processo. Aqui é armazenado o contexto da aplicação (registradores da CPU, incluindo o contador de programa). Quando um processo é parado o kernel copia os valores dos registradores (contexto) no PCB.
* **Process control data:** É utilizado pelo sistema operacional para controlar os processos. Aqui encontramos informações como valor da prioridade, tempo com o controle da CPU, tempo acumulado de uso da CPU, entre outras. 

![process_control_block_structure](http://s14.postimg.org/67hz67zxt/pcb.png)

## Algoritmos de Escalonamento

### Round-Robin
```
TODO: EXPLICAR
```
### Shortest Remaining Time Next
```
TODO: EXPLICAR
```
### Outros
```
TODO: LISTAR
```

# Algoritmo escolhido: Filas múltiplas com quantum diferenciado #
```
TODO: Explicar
```
