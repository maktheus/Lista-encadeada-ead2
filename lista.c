#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct ElementoDaListaEncadeada {
    void* elemento;
    struct ElementoDaListaEncadeada *prox;
}elemento;

elemento* criar_elemento(void* elemento){
    elemento* novo = (elemento*)malloc(sizeof(elemento));
    novo->elemento = elemento;
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
    lista* lse = (lista*)malloc(sizeof(lista));
    lse->inicio = NULL;
    lse->tamanho = 0;
    lse->imprimir = imprimir;
    lse->comparar = comparar;
    return lse;
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
        void* elemento = aux->elemento;
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
        return aux->elemento;
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
        void* elemento = aux->elemento;
        free(aux);
        return elemento;
    }
}

void imprimir_lse(t_lse* lse){
    lista* l = (lista*)lse;
    elemento* aux = l->inicio;
    while(aux != NULL){
        l->imprimir(aux->elemento);
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
        while(aux != NULL && l->comparar(aux->elemento, chave) != 0){
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
            void* elemento = aux->elemento;
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
        while(aux != NULL && l->comparar(aux->elemento, chave) != 0){
            aux = aux->prox;
        }
        if(aux == NULL){
            return NULL;
        }else{
            return aux->elemento;
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
        while(aux != NULL && l->comparar(aux->elemento, carga) < 0){
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
