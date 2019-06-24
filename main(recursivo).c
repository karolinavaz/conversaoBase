#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    unsigned long long binario;
    int opcao,decimal;
    printf("\n      Conversão de Decimal em Binário     \n");
    printf("\n Digite o valor na base decimal: ");
    scanf("%d", &decimal);
    conversao(decimal);
    binario=conversao(decimal);
    printf ("\nO valor equivalente na Base Binária é: %11d\n\n", binario);
    printf("\n\nO que você deseja agora?\n\n");
    printf("1 - Converter outro número\n");
    printf("2 - Sair\n");
    scanf("%d", &opcao);
    if(opcao==1)
    {
        system("cls");
        return main();
    }
    if(opcao==2)
    {
        return 0;
    }

}

int conversao (int decimal)

{
    unsigned long long binario,serie_resto, quociente, resto, inversao, algarismo;


    serie_resto=1;
    binario=0;

    quociente=(decimal/2);
    resto=(decimal%2);
    serie_resto=(serie_resto*10)+ resto;


    while (quociente!=0) /* Divisões Sucessivas.*/
    {
        resto=(quociente%2);
        serie_resto=(serie_resto*10)+ resto;
        quociente=(quociente/2);

    }

    /* Primeira inversão:*/

    inversao=(serie_resto/10);
    algarismo=(serie_resto%10);
    binario=(binario*10)+algarismo;

    while (inversao!=0) /* Divisões sucessivas para inverter o número.*/
    {
        algarismo=(inversao%10);
        binario=(binario*10)+algarismo;
        inversao=(inversao/10);
    }

    binario=binario/10; /* Retirar o algarismo excedente.*/


    return binario;
}

