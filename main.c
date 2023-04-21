#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "lista.h"

int main(){
    t_lse* lse = criar_lse(imprimir, comparar);
    char* nome = "Joao";
    inserir_inicio_lse(lse, nome);
    char* nome2 = "Maria";
    inserir_inicio_lse(lse, nome2);
    char* nome3 = "Jose";
    inserir_inicio_lse(lse, nome3);
    imprimir_lse(lse);
    printf(" %s ", (char*)remover_inicio_lse(lse));
    printf(" %s ", (char*)remover_inicio_lse(lse));
    printf(" %s ", (char*)remover_inicio_lse(lse));
    printf(" %s ", (char*)remover_inicio_lse(lse));
    destruir_lse(lse);
    return 0;
}