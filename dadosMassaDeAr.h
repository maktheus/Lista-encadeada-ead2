#ifndef DADOS_MASSADEAR_H
#define DADOS_MASSADEAR_H

typedef struct dadosMassaDeAr{
    int seq;
    int dia;
    int hora;
    int minuto;
    double velocidade_media;
    double velocidade_instantanea;
    int direcao;
}DadosMassaDeAr;

void imprimir_dados(void* dados);
DadosMassaDeAr* dadosMassaDeAr_criar( int dia, int hora, int minuto, double velocidade_media, double velocidade_instantanea, int direcao);
int compararDadosMassaDeAr(DadosMassaDeAr* dadosMassaDeAr1, DadosMassaDeAr* dadosMassaDeAr2);

#endif
