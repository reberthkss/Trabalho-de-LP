
#include<stdio.h>
#include<math.h>
#include <string.h>
#include "funcoes.h"


int assentoC[23];
int assentoJ[23];
float valort=0;



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



