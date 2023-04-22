#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dadosTemperatura.h"
#include "lista.h"


int seq_counter_temp = 1;

dados_sensor_temperatura* criarDados( int dia, int hora, int minuto, int radiacao_solar, double temperatura, double umidade){
    dados_sensor_temperatura* d = (dados_sensor_temperatura*)malloc(sizeof(dados_sensor_temperatura));
    d->seq = seq_counter_temp++;
    d->dia = dia;
    d->hora = hora;
    d->minuto = minuto;
    d->radiacao_solar = radiacao_solar;
    d->temperatura = temperatura;
    d->umidade = umidade;
    return d;
}

void imprimir_dados(void* dado){
    struct dados_sensor* d = (struct dados_sensor*)dado;
    printf("Seq: %d\n", d->seq);
    printf("Dia: %d\n", d->dia);
    printf("Hora: %d\n", d->hora);
    printf("Minuto: %d\n", d->minuto);
    printf("Radiacao solar: %d\n", d->radiacao_solar);
    printf("Temperatura: %lf\n", d->temperatura);
    printf("Umidade: %lf\n", d->umidade);
}

void imprimir_apenas_data(void* dado){
    struct dados_sensor* d = (struct dados_sensor*)dado;
    printf("Dia: %d\n", d->dia);
    printf("Hora: %d\n", d->hora);
    printf("Minuto: %d\n", d->minuto);
}

int comparar_dados(void* dado1, void* dado2){
    struct dados_sensor* d1 = (struct dados_sensor*)dado1;
    struct dados_sensor* d2 = (struct dados_sensor*)dado2;
    if(d1->seq == d2->seq){
        return 0;
    }else if(d1->seq > d2->seq){
        return 1;
    }else{
        return -1;
    }
}

