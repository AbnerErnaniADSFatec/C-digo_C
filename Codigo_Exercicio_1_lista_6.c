#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>

struct carro{
    char marca[15];
    int ano;
    char cor[10];
    float preco;
};

struct carro vet_carros[20];

void cadastrar_carros(int quant){
        int i;
        for( i = 0; i < quant; i++ ){
            printf("\nDigite as características do carro:\n");
            printf("\nMarca: ");
            scanf("%s", &vet_carros[i].marca);
            printf("Ano: ");
            scanf("%i", &vet_carros[i].ano);
            printf("Cor: ");
            scanf("%s", &vet_carros[i].cor);
            printf("Preço: R$ ");
            scanf("%f", &vet_carros[i].preco);
            Sleep(2000);
            system("cls");
        }
}

void exibe_por_preco( float preco, int quant ){
    int i;
    printf("\nCarros com o preco menor ou igual ao preco digitado:\n");
    for( i = 0; i < quant; i++ ){
        if( vet_carros[i].preco <= preco ){
            printf("\nMarca: %s\n", vet_carros[i].marca);
            printf("Ano: %d\n", vet_carros[i].ano);
            printf("Cor: %s\n", vet_carros[i].cor);
            printf("Preço: R$ %10.2f \n", vet_carros[i].preco);
        }
    }
    int j;
    printf("\nDigite 0 para retornar ao menu: ");
    scanf("%d", &j);
}

void exibe_por_marca( char *p_marca, int quant ){
    int i;
    printf("\nCarros com a marca digitada:\n");
    for( i = 0; i < quant; i++ ){
        if( strcmp(vet_carros[i].marca, p_marca) == 0 ){
            printf("\nMarca: %s\n", vet_carros[i].marca);
            printf("Ano: %d\n", vet_carros[i].ano);
            printf("Cor: %s\n", vet_carros[i].cor);
            printf("Preço: R$ %10.2f \n", vet_carros[i].preco);
        }
    }
    int j;
    printf("\nDigite 0 para retornar ao menu: ");
    scanf("%d", &j);
}

void exibe_por_caracteristica( char *p_marca, int ano, char *p_cor, float preco, int quant){
    int i, p;
    printf("\nCarros com as caracteísticas digitadas: \n");
    for( i = 0; i < quant; i++){
            if( strcmp(p_marca, vet_carros[i].marca) == 0 && ano == vet_carros[i].ano && strcmp(p_cor, vet_carros[i].cor) == 0 && preco == vet_carros[i].preco ){
                printf("\nMarca: %s\n", vet_carros[i].marca);
                printf("Ano: %d\n", vet_carros[i].ano);
                printf("Cor: %s", vet_carros[i].cor);
                printf("Preço: R$ %10.2f \n", vet_carros[i].preco);
                p++;
            }
    }
    if( p == 0 ) printf("\nNão há nenhum carro com essas características!!! :( \n");
    int j;
    printf("\nDigite 0 para retornar ao menu: ");
    scanf("%d", &j);
}

int quant = 0;

void main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    do{
            printf("  Opções:\n\n");
            printf("       (0)...Sair\n");
            printf("       (1)...Cadastrar Carros\n");
            printf("       (2)...Exibir Carros por preço\n");
            printf("       (3)...Exibir Carros por marca\n");
            printf("       (4)...Buscar carro por características\n");
            printf("\nDigite uma opção: ");
            scanf("%d", &opcao);
            system("cls");

            char marca[15], cor[10];
            float preco;
            int i, j, ano;

            switch(opcao){
            case 1:
                printf("Digite a quantidade de carros que deseja cadastrar: ");
                scanf("%d", &quant);
                system("cls");
                cadastrar_carros(quant);
                break;
            case 2:
                if( quant == 0 ){
                   printf("\aNão há nenhum carro cadastrado para pesquisar por preço!!! :(\n");
                   Sleep(2000);
                   system("cls");
                }else{
                    printf("\nDigite o preço: R$ ");
                    scanf("%f", &preco);
                    exibe_por_preco( preco, quant);
                    system("cls");
                }
                break;
            case 3:
                if( quant == 0 ){
                    printf("\aNão há nenhum carro cadastrado para pesquisar por marca!!! :(\n");
                    Sleep(2000);
                    system("cls");
                }else{
                    printf("Digite a marca: ");
                    scanf("%s", &marca);
                    exibe_por_marca( &marca, quant);
                    system("cls");
                }
                break;
            case 4:
                if( quant == 0 ){
                    printf("\aNão há nenhum carro cadastrado para pesquisar por características!!! :(\n");
                    Sleep(2000);
                    system("cls");
                }else{
                    printf("Digite as características do carro; \n");
                    printf("\nMarca: ");
                    scanf("%s", &marca);
                    printf("Ano: ");
                    scanf("%d", &ano);
                    printf("Cor: ");
                    scanf("%s", &cor);
                    printf("Preço: R$ ");
                    scanf("%f", &preco);
                    exibe_por_caracteristica( &marca, ano, &cor, preco, quant);
                    system("cls");
                }
                break;
            default:
                if( opcao == 0 ){
                    printf("\nVocê escolheu sair!!! :)\n");
                    Sleep(2000);
                    system("cls");
                }
                else{
                    printf("\nDigite uma opção válida!!! :)\n");
                    Sleep(2000);
                    system("cls");
                }
                break;
            }
    }while( opcao != 0 );
}
