# Implementação da função MPI_Reduce usando a biblioteca <sockets.h>

- Alunos:
  - Jean Rayhan Vieira Achour (211043486)
  - Paola Guedes Bacca (211042587)

## Considerações

O programa reproduz o funcionamento esperado da função de redução MPI_Reduce da biblioteca <mpi.h>. Para a geração dos processos é utilizada a biblioteca <mpi.h>. Cada processo recebe um ID de 0 a 9 (para 8 Workers e 1 Manager). Para instalar a biblioteca, basta rodar o seguinte comando: `sudo apt-get install libopenmpi-dev`.

Para rodar o programa, utilize o comando `make run`, que irá compilar o programa, remover arquivos executáveis e de output, se existentes no diretório. Por padrão, o comando `make run` irá printar todos os logs de cada um dos processos diretamente no terminal.

Caso queira salvar os logs em um arquivo separado para conferência posterior, você pode utilizar o comando `make run_and_export` que irá salvar os logs em dois arquivos: `output.txt` (log puro dos programas) e um arquivo `sorted.txt` que ordena os logs dos processos em `output.txt` por ordem cronológica.

## Avisos

Caso o programa tente ser executado mais de uma vez num curto período de tempo, é possível que ocorra um erro com o seguinte conteúdo:

```txt
Error when binding socket: Address already in use
make: *** [Makefile:12: run] Error 1
```

Caso isso ocorra, aguarde por um tempo para que as sockets utilizadas pelo programa finalizem seu TIME_WAIT. Após o TIME_WAIT finalizado, é possível rodar novamente a aplicação, sem maiores problemas.

OBS: Se você tenha o comando `netstat` instalado em sua máquina, rodando o comando `netstat -t -o | grep 'TIME_WAIT'`, é possível visualizar todas as portas em estado de espera, juntamente com um cronômetro indicando qual o tempo de espera para re-disponibilidade das portas para uso.
