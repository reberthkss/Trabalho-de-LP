
#pragma once

#include <stdio.h>
#include <math.h>
#include <stdlib.h>



extern int assentoC[23];
extern int assentoJ[23];
extern float valort;




// MENUS


int menuprincipal();

int voltarMenuP(int *menu);


// -------- // // -------- // // -------- // // -------- // // -------- // // -------- // // -------- // // -------- //


//AÇÃO

int acao(int opt,int * gameover);

// -------- // // -------- // // -------- // // -------- // // -------- // // -------- // // -------- // // -------- //

//COMPRAR // VER ASSENTO // VER MAPA // SAIR

char* posicao(int pos);


void efetCompra(int pos,int destino);

void comprar();




char* verStatusAss(int *assento);



void verAss();


// -------- // // -------- // // -------- // // -------- // // -------- // // -------- // // -------- // // -------- //
//UTILITARIOS

void limparvetor(int *v1,int *v2);









