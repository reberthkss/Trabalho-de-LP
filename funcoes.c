
#pragma once

#include <stdio.h>
#include <math.h>
#include <stdlib.h>



extern int assentoC[23];
extern int assentoJ[23];
extern float valort=0;




// MENUS


int menuprincipal()
{

    int opt=0;

    system("COLOR 02");
    printf("\t\t\t\ MENU PRINCIPAL \n\n");
    printf("\t\t 1 - COMPRAR ASSENTO\n");
    printf("\t\t 2 - VERIFICAR ASSENTOS\n");
    printf("\t\t 3 - VER MAPA DO TRAJETO\n");
    printf("\t\t 4 - VER LUCRO\n");
    printf("\t\t 5 - SAIR\n");

    printf("\t\t Digite uma opcao: ");

    scanf("%i",&opt);

    return opt;

}

int voltarMenuP(int *menu)
{
    int menu2;
    printf("APERTE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL");

        menu2=getch();

        if(menu2!=0) *menu=1;

        return menu;
}

// -------- // // -------- // // -------- // // -------- // // -------- // // -------- // // -------- // // -------- //


//AÇÃO

int acao(int opt,int * gameover)
{
    int menu=0;

while(!menu){
    switch(opt){
    case 1:
        comprar();
        voltarMenuP(&menu);
        break;
        // VERIFICAR ASSENTOS
    case 2:

        verAss();

        voltarMenuP(&menu);

        break;
        // verMap()
    case 3:

        printf("\t\t\MAPA\n");
        printf("SJC\t->\t Sao Paulo\t->\t Curitiba\t->\t Florianopolis\n");

        voltarMenuP(&menu);

        break;
        // verLuc()
    case 4:

        printf("Valor total: %.2f\n",valort);

        voltarMenuP(&menu);

        break;
        // exit()
    case 5:
            *gameover=1;
            return;
        break;
    }
}
}


// -------- // // -------- // // -------- // // -------- // // -------- // // -------- // // -------- // // -------- //

//COMPRAR // VER ASSENTO // VER MAPA // SAIR

char* posicao(int pos)
{
    char*res;
    if(pos==1){
            return "JANELA";
    }else return "CORREDOR";
}


void efetCompra(int pos,int destino){

    int i,opt=0,qt=0,ass[23],confirma=0,cont=0,aux=1;;
    float valor1=28.0,valor2=159.0,valor3=188.0;


                    do{
                    printf("[%s] Quantos assentos?:",posicao(pos));

                    scanf("%i",&qt);

                    if(qt<1 || qt > 23)
                    {
                        printf("Por Favor! DIGITE A QUANTIDADE DE ASSENTOS ENTRE 1 E 23\n");
                    } else {
                    aux--;}
                    }while(aux==1);
                    printf("\n");

                    printf("[%s] Qual/Quais assento?: ",posicao(pos));

                    for(i=0;i<qt;i++){

                        cont=0;

                            while(cont<1){


                    printf("[%s] Bilhete: %i. Assento: ",posicao(pos),i+1);
                    scanf("%i",&ass[i]);
                    printf("\n");

                    if(!(strcmp(posicao(pos),"JANELA")))
                    {

                    if(assentoJ[(ass[i]-1)]!=0){
                        printf("Assento OCUPADO. Escolha outro assento! ");

                    } else cont++;

                    } else{

                    if(assentoC[ass[i]-1]!=0){
                        printf("Assento OCUPADO. Escolha outro assento! ");

                    } else cont++;
                    }
                    } //fim do while
                    } //fim do for

                    printf("\t\t     RESUMO\n");
                    printf("Posicao: %s \n",posicao(pos));

                    for(i=0;i<qt;i++){
                    printf("Bilhete: %i.\t Assento: %i\n",i+1,ass[i]);
                    }

                    printf("CONFIRMA?? ");
                    printf("[1] SIM [0] NAO:");
                    scanf("%i",&confirma);


                    if(confirma!=0){
                        for(i=0;i<qt;i++)
                        {
                            if(!(strcmp(posicao(pos),"JANELA"))){
                                assentoJ[ass[i]-1]=1;
                                } else assentoC[ass[i]-1]=1;

                            switch(destino)
                            {
                                case 1: valort=valort+(qt*valor1);
                                break;
                                case 2: valort=valort+(qt*valor2);
                                break;
                                case 3: valort=valort+(qt*valor3);
                                break;
                            }
                        }

                        printf("\nVENDA REALIZADA COM SUCESSO!!!!\n");
                    }else
                    {
                        printf("VENDA NAO EFETUADA! VOLTANDO AO MENU PRINCIPAL...");

                    }
                    }

void comprar()
{
    int i,opt=0,qt=0,ass[23],confirma=0,menu=0,contDJ=1,contDC=1,destino=0,cont=0;
    float valor1=28.0,valor2=159.0,valor3=188.0;

    printf("\t\t MENU\n");

    printf("Destino: [1] Sao Paulo [2] Curitiba [3] Florianopolis: ");

    scanf("%i",&destino);

    printf("\n");


    printf("Voce quer comprar assentos em/ou: \n\n");


    for(i=0;i<23;i++){
        if(assentoC[i]==0){contDC=0;}
    }

    for(i=0;i<23;i++){
        if(assentoJ[i]==0){contDJ=0;}
    }

    printf("ASSENTO DISPONIVEIS EM\n");

    if(contDJ==0) printf("\n1 - Janela\n\n");


    if(contDC==0) printf("2 - Corredor\n");
    printf("\n\n\n3 - Voltar para menu principal\n");

    scanf("%i",&opt);

        switch(opt){
            case 1:
                efetCompra(opt,destino);
            break;
            case 2:
                efetCompra(opt,destino);
            break;
            default:
            break;
    }
    }





char* verStatusAss(int *assento)
{if(*assento>0) return "OCUPADO";
    else return "DISPONIVEL";
}



void verAss()
{
    int i;
    int opt=0;

    printf("\t\t MENU\n");
    printf("Voce quer ver assentos em/ou: \n");
    printf("1 - Janela\n");
    printf("2 - Corredor\n");
    printf("3 - Todos\n");
    printf("Digite uma opcao: ");
    scanf("%i",&opt);

    printf("\n");

    for(i=0;i<23;i++)
    {
        switch(opt){
            case 1: printf("[JANELA] Assento %i. STATUS: %s \n",i+1, verStatusAss(&assentoJ[i]));
            break;
            case 2: printf("[CORREDOR] Assento %i. STATUS: %s \n",i+1,verStatusAss(&assentoC[i]));
            break;
            case 3: printf("[JANELA] Assento %i. STATUS: %s \t [CORREDOR] Assento %i. STATUS: %s\n",i+1,verStatusAss(&assentoJ[i]),i+1,verStatusAss(&assentoC[i]));
            break;
    }
    }
}



// -------- // // -------- // // -------- // // -------- // // -------- // // -------- // // -------- // // -------- //
//UTILITARIOS

void limparvetor(int *v1,int *v2){

int i;

for(i=0;i<23;i++){
    *(v1+i)=0;
    *(v2+i)=0;
}
}









