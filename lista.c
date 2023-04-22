#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "dadosMassaDeAr.h"
#include "dadosTemperatura.h"

typedef struct ElementoDaListaEncadeada {
    void* dado;
    struct ElementoDaListaEncadeada *prox;
}elemento;

elemento* criar_elemento(void* dado){
    elemento* novo = malloc(sizeof(elemento));
    novo->dado = dado;
    novo->prox = NULL;
    return novo;
}

typedef struct listaEncadeada {
    elemento *inicio;
    int tamanho;
    void (*imprimir)(void*);
    int (*comparar)(void*, void*);
} lista;

t_lse* criar_lse(void (*imprimir)(void*), int (*comparar)(void*, void*)){
    lista* l = malloc(sizeof(lista));
    l->inicio = NULL;
    l->tamanho = 0;
    l->imprimir = imprimir;
    l->comparar = comparar;
    return (t_lse*)l;
}


void inserir_inicio_lse(t_lse* lse, void* carga){
    lista* l = (lista*)lse;
    elemento* novo = criar_elemento(carga);
    if(l->inicio == NULL){
        l->inicio = novo;
    }else{
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    l->tamanho++;
}

void* remover_inicio_lse(t_lse* lse){
    lista* l = (lista*)lse;
    if(l->inicio == NULL){
        return NULL;
    }else{
        elemento* aux = l->inicio;
        l->inicio = l->inicio->prox;
        l->tamanho--;
        void* elemento = aux->dado;
        free(aux);
        return elemento;
    }
}

void* acessar_lse(t_lse* lse, int pos){
    lista* l = (lista*)lse;
    if(pos < 0 || pos >= l->tamanho){
        return NULL;
    }else{
        elemento* aux = l->inicio;
        int i;
        for(i = 0; i < pos; i++){
            aux = aux->prox;
        }
        return aux->dado;
    }
}

void inserir_final_lse(t_lse* lse, void* carga){
    lista* l = (lista*)lse;
    elemento* novo = criar_elemento(carga);
    if(l->inicio == NULL){
        l->inicio = novo;
    }else{
        elemento* aux = l->inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    l->tamanho++;
}

void* remover_final_lse(t_lse* lse){
    lista* l = (lista*)lse;
    if(l->inicio == NULL){
        return NULL;
    }else{
        elemento* aux = l->inicio;
        elemento* ant = NULL;
        while(aux->prox != NULL){
            ant = aux;
            aux = aux->prox;
        }
        if(ant == NULL){
            l->inicio = NULL;
        }else{
            ant->prox = NULL;
        }
        l->tamanho--;
        void* elemento = aux->dado;
        free(aux);
        return elemento;
    }
}

void imprimir_lse(t_lse* lse){
    lista* l = (lista*)lse;
    elemento* aux = l->inicio;
    while(aux != NULL){
        l->imprimir(aux->dado);
        aux = aux->prox;
    }
}

void* remover_lse(t_lse* lse, void* chave){
    lista* l = (lista*)lse;
    if(l->inicio == NULL){
        return NULL;
    }else{
        elemento* aux = l->inicio;
        elemento* ant = NULL;
        while(aux != NULL && l->comparar(aux->dado, chave) != 0){
            ant = aux;
            aux = aux->prox;
        }
        if(aux == NULL){
            return NULL;
        }else{
            if(ant == NULL){
                l->inicio = aux->prox;
            }else{
                ant->prox = aux->prox;
            }
            l->tamanho--;
            void* elemento = aux->dado;
            free(aux);
            return elemento;
        }
    }
}

void* buscar_lse(t_lse* lse, void* chave){
    lista* l = (lista*)lse;
    if(l->inicio == NULL){
        return NULL;
    }else{
        elemento* aux = l->inicio;
        while(aux != NULL && l->comparar(aux->dado, chave) != 0){
            aux = aux->prox;
        }
        if(aux == NULL){
            return NULL;
        }else{
            return aux->dado;
        }
    }
}

void inserir_lse(t_lse* lse, void* carga){
    lista* l = (lista*)lse;
    elemento* novo = criar_elemento(carga);
    if(l->inicio == NULL){
        l->inicio = novo;
    }else{
        elemento* aux = l->inicio;
        elemento* ant = NULL;
        while(aux != NULL && l->comparar(aux->dado, carga) < 0){
            ant = aux;
            aux = aux->prox;
        }
        if(ant == NULL){
            novo->prox = l->inicio;
            l->inicio = novo;
        }else{
            ant->prox = novo;
            novo->prox = aux;
        }
    }
    l->tamanho++;
}

int tamanho_lse(t_lse* lse){
    lista* l = (lista*)lse;
    return l->tamanho;
}

void destruir_lse(t_lse* lse){
    lista* l = (lista*)lse;
    elemento* aux = l->inicio;
    while(aux != NULL){
        elemento* aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(l);
}


void deletar_elemento(t_lse* lse, void* chave){
    lista* l = (lista*)lse;
    if(l->inicio == NULL){
        return;
    }else{
        elemento* aux = l->inicio;
        elemento* ant = NULL;
        while(aux != NULL && l->comparar(aux->dado, chave) != 0){
            ant = aux;
            aux = aux->prox;
        }
        if(aux == NULL){
            return;
        }else{
            if(ant == NULL){
                l->inicio = aux->prox;
            }else{
                ant->prox = aux->prox;
            }
            l->tamanho--;
            free(aux);
        }
    }
}


//Rdia/mes/anohora:min-Removeroeventoqueocorreunadataespecificada.

void remover_dado_temperatura(t_lse* lse, int dia, int hora, int minuto){
    lista* l = (lista*)lse;
    if(l->inicio == NULL){
        return;
    }else{
        elemento* aux = l->inicio;
        elemento* ant = NULL;
        while(aux != NULL && ((dados_sensor_temperatura*)aux->dado)->dia != dia && ((dados_sensor_temperatura*)aux->dado)->hora != hora && ((dados_sensor_temperatura*)aux->dado)->minuto != minuto){
            ant = aux;
            aux = aux->prox;
        }
        if(aux == NULL){
            return;
        }else{
            if(ant == NULL){
                l->inicio = aux->prox;
            }else{
                ant->prox = aux->prox;
            }
            l->tamanho--;
            free(aux);
        }
    }
}

void remover_dado_massa_de_ar(t_lse* lse, int dia, int hora, int minuto){
    lista* l = (lista*)lse;
    if(l->inicio == NULL){
        return;
    }else{
        elemento* aux = l->inicio;
        elemento* ant = NULL;
        while(aux != NULL && ((DadosMassaDeAr*)aux->dado)->dia != dia && ((DadosMassaDeAr*)aux->dado)->hora != hora && ((DadosMassaDeAr*)aux->dado)->minuto != minuto){
            ant = aux;
            aux = aux->prox;
        }
        if(aux == NULL){
            return;
        }else{
            if(ant == NULL){
                l->inicio = aux->prox;
            }else{
                ant->prox = aux->prox;
            }
            l->tamanho--;
            free(aux);
        }
    }
}
