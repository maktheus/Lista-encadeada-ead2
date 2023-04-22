#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "lista.h"
#include "dadosTemperatura.h"
#include "dadosMassaDeAr.h"

 
int main(char *argv[], int argc){
    char entrada;
    // int tipo = atoi(argv[1]);
    
    // char nome_arquivo = argv[2];   
    
    // FILE *arq = fopen(nome_arquivo, "r");

    t_lse* lista = criar_lse(imprimir_dados, comparar_dados);
    t_lse* lista2 = criar_lse(imprimir_dados, comparar_dados);

    int dia, mes, ano, hora, min, x, y;
    do {
        printf("Digite a opção desejada:\n");
        printf("R - Remover o evento que ocorreu em uma data especificada.\n");
        printf("I - Imprimir os elementos no intervalo [x,y].\n");
        printf("A - Acessar o elemento x.\n");
        printf("B - Buscar um evento que ocorreu em uma data especificada.\n");
        printf("P - Podar (remover) todos os elementos no intervalo [x,y].\n");
        printf("F - Finalizar.\n");

        scanf(" %c", &entrada);

        switch (entrada) {
            case 'R':
                printf("Digite a data (DD/MM/AAAA) e hora (HH:MM) do evento a ser removido:\n");
                scanf("%d/%d/%d %d:%d", &dia, &mes, &ano, &hora, &min);
                //removerEvento(l, dia, mes, ano, hora, min);
                break;

            case 'I':
                printf("Digite o intervalo [x,y]:\n");
                scanf("%d,%d", &x, &y);
                //imprimirIntervalo(l, x, y);
                break;

            case 'A':
                printf("Digite o elemento x:\n");
                scanf("%d", &x);
                //acessarElemento(l, x);
                break;

            case 'B':
                printf("Digite a data (DD/MM/AAAA) e hora (HH:MM) do evento a ser buscado:\n");
                scanf("%d/%d/%d %d:%d", &dia, &mes, &ano, &hora, &min);
                //buscarEvento(l, dia, mes, ano, hora, min);
                break;

            case 'P':
                printf("Digite o intervalo [x,y]:\n");
                scanf("%d,%d", &x, &y);
                //podarIntervalo(l, x, y);
                break;

            case 'F':
                printf("Finalizando programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (entrada != 'F');

   

    
    dados_sensor_temperatura* d1 = criarDados( 1, 1, 1, 1, 1, 1);
    dados_sensor_temperatura* d2 = criarDados( 2, 2, 2, 2, 2, 2);
    dados_sensor_temperatura* d3 = criarDados( 3, 3, 3, 3, 3, 3);
    dados_sensor_temperatura* d4 = criarDados( 4, 4, 4, 4, 4, 4);
    dados_sensor_temperatura* d5 = criarDados( 5, 5, 5, 5, 5, 5);

    inserir_inicio_lse(lista, d1);
    inserir_inicio_lse(lista, d2);
    inserir_inicio_lse(lista, d3);
    inserir_inicio_lse(lista, d4);
    inserir_inicio_lse(lista, d5);

    remover_dado(lista, 1, 1, 1);
    imprimir_lse(lista);
    printf("\n\n");



    DadosMassaDeAr* d6 = dadosMassaDeAr_criar( 1, 1, 1, 1, 1, 1);
    DadosMassaDeAr* d7 = dadosMassaDeAr_criar( 2, 2, 2, 2, 2, 2);
    DadosMassaDeAr* d8 = dadosMassaDeAr_criar( 3, 3, 3, 3, 3, 3);
    DadosMassaDeAr* d9 = dadosMassaDeAr_criar( 4, 4, 4, 4, 4, 4);
    DadosMassaDeAr* d10 = dadosMassaDeAr_criar( 5, 5, 5, 5, 5, 5);
    
    inserir_inicio_lse(lista2, d6);
    inserir_inicio_lse(lista2, d7);
    inserir_inicio_lse(lista2, d8);
    inserir_inicio_lse(lista2, d9);

    inserir_inicio_lse(lista2, d10);
    //void remover_dado_massa_de_ar(t_lse* lse, int dia, int hora, int minuto);
    printf("\n\n");

    imprimir_lse(lista2);

    //limpar listas
    destruir_lse(lista);
    destruir_lse(lista2);
    
    return 0;
}