#ifndef DADOS_TEMPERATURA_H
#define DADOS_TEMPERATURA_H

typedef struct dados_sensor{
    int seq;
    int dia;
    int hora;
    int minuto;
    int radiacao_solar;
    double temperatura;
    double umidade;
} dados_sensor_temperatura;

void imprimir_dados(void* dado);
int comparar_dados(void* dado1, void* dado2);
dados_sensor_temperatura* criarDados( int dia, int hora, int minuto, int radiacao_solar, double temperatura, double umidade);

#endif
