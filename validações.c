#include "validações.h"

int validLetra(char var)
{
    if((var>='a'&&var<='z')||(var>='A'&&var<='Z'))
    {
        return 1;
    }

        printf("APENAS LETRAS\n");
        return 0;
}

int validaUmNum(char num)
{
    if(num>='0'&&num<='9')
    {
        return 1;
    }
    else
    {
        printf("APENAS NUMEROS\n");
        return 0;
    }

}
int validaNumeros(char num[12])
{
    int i=0;
    while(num[i]!='\0')
    {
        if(validaUmNum(num[i])==0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int validaString(char var[50])
{
    int i=0;
    while(var[i]!='\0')
    {
        if(validLetra(var[i])==0)
        {
            return 0;
        }
        else
        {
            i++;
        }
    }
    return 1;
}


