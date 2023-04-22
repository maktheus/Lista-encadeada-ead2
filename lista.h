#ifndef _LISTA_H
#define _LISTA_H

typedef struct lista t_lse;
typedef void(*t_imprimir_lse)(void*);

typedef int (*t_comparar_lse)(void* carga_na_lista, void* nova_carga);

t_lse* criar_lse(void (*imprimir)(void*), int (*comparar)(void*, void*));

void inserir_inicio_lse(t_lse* lse, void* carga);
void* remover_inicio_lse(t_lse* lse);
void* acessar_lse(t_lse* lse, int pos);
void inserir_final_lse(t_lse* lse, void* carga);
void* remover_final_lse(t_lse* lse);
void imprimir_lse(t_lse* lse);
void* remover_lse(t_lse* lse, void* chave);
void* buscar_lse(t_lse* lse, void* chave);
void inserir_lse(t_lse* lse, void* carga);
void destruir_lse(t_lse* lse);
int tamanho_lse(t_lse* lse);
void remover_dado_temperatura(t_lse* lse, int dia, int hora, int minuto);
void remover_dado_massa_de_ar(t_lse* lse, int dia, int hora, int minuto);

#endif 