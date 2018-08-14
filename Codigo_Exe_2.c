#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#define TOTAL_CABECAS 2

struct data_nascimento{
    int mes, ano;
};

struct cabeca_de_gado{
    char code[6];
    int abate;
    float leite, alimento;
    struct data_nascimento data;
};

struct cabeca_de_gado vet_gado[TOTAL_CABECAS];

void main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao, dia, mes, ano, codigo, abate;
    char code[6];
    float leite, alimento, total_leite = 0, total_alimento = 0;
    float total_abate_leite = 0, total_abate_alimento = 0;
    int num_abate = 0;
    int i;
    for( i = 0; i < TOTAL_CABECAS; i++ ){
        printf("Cadastrar Cabe�as de Gado:\n");
        printf("   -Data de nascimento:\n");
        printf("       ->M�s: ");
        scanf("%d", &vet_gado[i].data.mes);
        printf("       ->Ano: ");
        scanf("%d", &vet_gado[i].data.ano);
        printf("   -Codigo: ");
        scanf("%s", &vet_gado[i].code);
        printf("   -Produ��o de Leite/semana (litros): ");
        scanf("%f", &vet_gado[i].leite);
        printf("   -Consumo de Alimento/semana (kg): ");
        scanf("%f", &vet_gado[i].alimento);
        int ano = 2018 - vet_gado[i].data.ano;
        float litros = vet_gado[i].leite;
        float alimento = vet_gado[i].alimento;
        if( ano >= 5 || leite < 40 || (alimento > 50 && leite >= 50 && leite <= 70) ){
            printf("   -Abate: Sim\n");
            printf("   Esse animal ser� considerado para o abate!");
            vet_gado[i].abate = 1;
        }else{
            printf("   -Abate: N�o\n");
            printf("   Esse animal n�o ser� considerado para o abate!");
            vet_gado[i].abate = 0;
        }
        Sleep(3000);
        system("cls");
    }
    do{
        printf("\n  Op��es:\n");
        printf("         (0)...Sair\n");
        printf("         (1)...Quantidade Total de Leite Produzido\n");
        printf("         (2)...Quantidade Total de Alimento Consumido\n");
        printf("         (3)...Quantidade de Leite a ser produzido ap�s o abate\n");
        printf("         (4)...Quantidade de Almento a ser consumido ap�s o abate\n");
        printf("         (5)...N�mero de Cabe�as de Gado que ir�o para o abate\n");
        printf("\nDigite uma op��o: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            for( i = 0; i < TOTAL_CABECAS; i++ ){
                total_leite = total_leite + vet_gado[i].leite;
            }
            printf("\nQantidade total de leite produzido esta semana: %5.2f L\n", total_leite);
            break;
        case 2:
            for( i = 0; i < TOTAL_CABECAS; i++ ){
                total_alimento = total_alimento + vet_gado[i].alimento;
            }
            printf("\nQuantidade total de alimento consumido esta semana: %5.2f kg", total_alimento);
            break;
        case 3:
            for( i = 0; i < TOTAL_CABECAS; i++ ){
                if( vet_gado[i].abate == 0 ){
                    total_abate_leite = total_abate_leite + vet_gado[i].leite;
                }
            }
            printf("\nQuantidade de leite a ser produzida por semana ap�s o abate: %5.2f L\n", total_abate_leite);
            break;
        case 4:
            for( i = 0; i < TOTAL_CABECAS; i++ ){
                if( vet_gado[i].abate == 0 ){
                    total_abate_alimento = total_abate_alimento + vet_gado[i].alimento;
                }
            }
            printf("\nQuantidade de alimento a ser consumido por semana ap�s o abate: %5.2f kg", total_abate_alimento);
            break;
        case 5:
            for( i = 0; i < TOTAL_CABECAS; i++ ){
                if( vet_gado[i].abate == 1 ){
                    num_abate++;
                }
            }
            printf("\nN�mero de cabe�as de gado para o abate: %d", num_abate);
            break;
        default:
            if( opcao == 0 ) printf("\nVoc� escolheu sair!!!");
            else printf("\n\aDigite uma op��o v�lida!!! :( \n");
            break;
        }
        Sleep(2000);
        system("cls");
    }while( opcao != 0 );
}
