#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista.h"
#include "dadosMassaDeAr.h"



int seq_counter = 1;

DadosMassaDeAr* dadosMassaDeAr_criar(int dia, int hora, int minuto, double velocidade_media, double velocidade_instantanea, int direcao)
{
    DadosMassaDeAr* dadosMassaDeAr = (DadosMassaDeAr*) malloc(sizeof(DadosMassaDeAr));
    dadosMassaDeAr->seq = seq_counter++;
    dadosMassaDeAr->dia = dia;
    dadosMassaDeAr->hora = hora;
    dadosMassaDeAr->minuto = minuto;
    dadosMassaDeAr->hora = hora;
    dadosMassaDeAr->minuto = minuto;
    dadosMassaDeAr->velocidade_media = velocidade_media;
    dadosMassaDeAr->velocidade_instantanea = velocidade_instantanea;
    dadosMassaDeAr->direcao = direcao;
    return dadosMassaDeAr;
}

void imprimirDadosMassaDeAr(DadosMassaDeAr* dadosMassaDeAr)
{
    printf("%d %d %d %d %d %d %lf %lf %d ", dadosMassaDeAr->seq, dadosMassaDeAr->dia, dadosMassaDeAr->hora, dadosMassaDeAr->minuto, dadosMassaDeAr->hora, dadosMassaDeAr->minuto, dadosMassaDeAr->velocidade_media, dadosMassaDeAr->velocidade_instantanea, dadosMassaDeAr->direcao);
}

int compararDadosMassaDeAr(DadosMassaDeAr* dadosMassaDeAr1, DadosMassaDeAr* dadosMassaDeAr2)
{
    if(dadosMassaDeAr1->seq == dadosMassaDeAr2->seq)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void imprimirDadosNoIntervaloTemperatura(int x, int y){
    

}



