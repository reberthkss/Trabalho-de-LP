#include<stdio.h>
#include<math.h>
#include <string.h>

int assentoC[23];
int assentoJ[23];
float valort=0;

void limparvetor(int *v1,int *v2){

int i;

for(i=0;i<23;i++){
    *(v1+i)=0;
    *(v2+i)=0;
}
}

char* verStatusAss(int *assento)
{if(*assento>0) return "OCUPADO";
    else return "DISPONIVEL";
}


void comprar()
{
    int i;
    int opt=0;
    int qt=0;
    int ass[23];
    int confirma=0;
    int menu=0;
    int contDJ=1;
    int contDC=1;
    int destino=0;
    int cont=0;
    float valor1=28.0,valor2=159.0,valor3=188.0;



    printf("\t\t MENU\n");

    printf("Destino: [1] Sao Paulo [2] Curitiba [3] Florianopolis: ");

    scanf("%i",&destino);

    printf("\n");


    printf("Voce quer comprar assentos em/ou: \n\n");

    for(i=0;i<23;i++){

    if(assentoC[i]==0){
        contDC=0;
    }

    }

    for(i=0;i<23;i++){

    if(assentoJ[i]==0){
        contDJ=0;
    }

    }

    printf("ASSENTO DISPONIVEIS EM\n");

    if(contDJ==0) printf("\n1 - Janela\n\n");


    if(contDC==0) printf("2 - Corredor\n");
    printf("\n\n\n3 - Voltar para menu principal\n");

    scanf("%i",&opt);

        switch(opt){
            case 1: printf("[JANELA] Quantos assentos?:");

                    scanf("%i",&qt);

                    printf("\n");

                    printf("[JANELA] Qual/Quais assento?: ");

                    for(i=0;i<qt;i++){
                        cont=0;
                            while(cont<1){

                    printf("[JANELA] Bilhete: %i. Assento: ",i+1);
                    scanf("%i",&ass[i]);
                    printf("\n");

                    if(assentoJ[ass[i]]!=0){
                        printf("Assento OCUPADO. Escolha outro assento! ");

                    }else
                    {
                        cont++;
                    }

                    }

                    }

                    printf("\t\t     RESUMO\n");
                    printf("Posicao: JANELA \n");
                    for(i=0;i<qt;i++){
                    printf("Bilhete: %i.\t Assento: %i\n",i+1,ass[i]);
                    }

                    printf("CONFIRMA?? ");
                    printf("[1] SIM [0] NAO:");
                    scanf("%i",&confirma);


                    if(confirma!=0){
                        for(i=0;i<qt;i++)
                        {

                            assentoJ[ass[i]]=1;

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
                    }
                    else
                    {
                        printf("VENDA NAO EFETUADA! VOLTANDO AO MENU PRINCIPAL...");

                    }
            break;
            case 2: printf("[CORREDOR] Quantos assentos?:");
                    scanf("%i",&qt);
                    printf("\n");
                    printf("[CORREDOR] Qual/Quais assento?: ");
                    for(i=0;i<qt;i++){
                    printf("[CORREDOR] Bilhete: %i. Assento: ",i+1);
                    scanf("%i",&ass[i]);
                    printf("\n");
                    }

                    printf("\t\t     RESUMO\n");
                    printf("Posicao: CORREDOR \n");
                    for(i=0;i<qt;i++){
                    printf("Bilhete: %i.\t Assento: %i\n",i+1,ass[i]);
                    }

                    printf("CONFIRMA?? ");
                    printf("[1] SIM [0] NAO:");
                    scanf("%i",&confirma);


                    if(confirma!=0){
                        for(i=0;i<qt;i++)
                        {
                            assentoJ[ass[i]]=1;
                        }
                    }
                    else
                    {
                        printf("VENDA NAO EFETUADA! VOLTANDO AO MENU PRINCIPAL...");

                    }
            break;
            case 3:


            break;
    }
    }


int menuprincipal()
{

    int opt=0;
    printf("\t\t     MENU PRINCIPAL\n\n");
    printf("\t\t 1 - COMPRAR ASSENTO\n");
    printf("\t\t 2 - VERIFICAR ASSENTOS\n");
    printf("\t\t 3 - VER MAPA DO TRAJETO\n");
    printf("\t\t 4 - VER LUCRO\n");
    printf("\t\t 5 - SAIR\n");

    printf("\t\t Digite uma opcao: ");
    scanf("%i",&opt);

    return opt;

}


int menusecundario()
{

    int opt=0;

    printf("1 - COMPRAR ASSENTO // ");
    printf("2 - VERIFICAR ASSENTOS \n");
    printf("3 - VER MAPA DO TRAJETO // ");
    printf("4 - VER LUCRO // ");
    printf("5 - VOLTAR PARA MENU PRINCIPAL\n");
    printf("6 - SAIR \n");

    printf("Digite uma opcao: ");
    scanf("%i",&opt);

    return opt;

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
            case 1: printf("[JANELA] Assento %i. STATUS: %s \n",i, verStatusAss(&assentoJ[i]));
            break;
            case 2: printf("[CORREDOR] Assento %i. STATUS: %s \n",i,verStatusAss(&assentoC[i]));
            break;
            case 3: printf("[JANELA] Assento %i. STATUS: %s \t [CORREDOR] Assento %i. STATUS: %s\n",i,verStatusAss(&assentoJ[i]),i,verStatusAss(&assentoC[i]));
            break;
    }
    }
}

int voltarMenuP(int *menu)
{
    int menu2;
    printf("APERTE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL");

        scanf("%i",&menu2);

        if(menu2!=0) *menu=1;

        return menu;
}

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
            return *gameover;
        break;
    }
}
}



int main(){

int gameover=0;
int opt;
int i=0;

    limparvetor(&assentoC,&assentoJ);

while(!gameover){
// MENU PRINCIPAL
// -- func menuprincipal()
acao(opt=menuprincipal(),&gameover);
}

return 0;

}

