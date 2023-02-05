#include <stdio.h>
#include <stdlib.h>
#include "includes/utils.h"
#include "includes/transacao.h"
#include "includes/grafo.h"

#define MAX_TRANSACOES 1000

int main(int argc, char ** argv)
{
    Transacao *transacoes = malloc(MAX_TRANSACOES * sizeof(Transacao));
    Grafo *g = malloc(MAX_TRANSACOES*sizeof(Grafo));
    int num_transacoes = 0;
    
    cria_grafo(g);
    num_transacoes = le_salva_entrada(transacoes, g);    
    adiciona_dependencia_transacoes(transacoes, num_transacoes, g);

    int tem_ciclo = verifica_existencia_ciclo(g);

    tem_ciclo ? printf("NS "): printf("SS ");

    return 0;
}