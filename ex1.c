#include <stdio.h>


int main()
{

    int x1,anos,anosdia,meses,mesesdia,dias;


    scanf("%i",&x1);
        anos=x1/365;
        anosdia=anos*365;
        meses=(x1-anosdia)/30;
        mesesdia=meses*30;
        dias=(x1-anosdia-mesesdia);


    printf("%i\n",anos);

    printf("%i\n",meses);

    printf("%i",dias);

//    printf("%i",);


    return 0;
}
