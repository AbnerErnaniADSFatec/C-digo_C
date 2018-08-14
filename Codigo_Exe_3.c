#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

struct produto{
    char nome[15];
    char setor;
    int quantidade;
    float preco;
};

struct produto estoque[100];

void cadastrar_produtos( int quant ){
    int i;
    for( i = 0; i < quant; i++ ){
        printf("Cadastro de Produtos:\n");
        printf("  -Nome: ");
        scanf("%s", &estoque[i].nome);
        printf("  -Setor: ");
        scanf("%c", &estoque[i].setor);
        getchar();
        printf("  -Quantidade: ");
        scanf("%d", &estoque[i].quantidade);
        printf("  -Preço: R$ ");
        scanf("%f", &estoque[i].preco);
        Sleep(3000);
        system("cls");
    }
    printf("\nProdutos Cadastrados com Sucesso!!! :) \n");
    Sleep(2000);
    system("cls");
}

void pesquisar_por_setor( char setor, int quant){
    int i;
    for( i = 0; i < quant; i++ ){
        if( setor == estoque[i].setor ){
            printf("Nome: %s\n", estoque[i].nome);
            printf("Setor: %s\n", estoque[i].setor);
            printf("Quantidade: %d\n", estoque[i].quantidade);
            printf("Preço: %5.2f\n", estoque[i].preco);
        }
        printf("\n");
    }
    int j;
    printf("Digite 0 para retornar ao menu: ");
    scanf("%d", &j);
}

float calcular_capital( int quant ){
    int i;
    float capital = 0;
    for( i = 0; i < quant; i++ ){
        float total_produto = estoque[i].preco * estoque[i].quantidade;
        capital = capital + total_produto;
    }
    return capital;        printf("\nDigite as características do carro:\n");

}

int quant = 0;

void main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    char setor;
    do{
        printf("  Opções:\n");
        printf("         (0)...Sair\n");
        printf("         (1)...Cadastrar Produtos\n");
        printf("         (2)...Pesquisar Produtos por setor\n");
        printf("         (3)...Calcular o Capital\n");
        printf("\nDigite uma opção: ");
        scanf("%d", &opcao);
        system("cls");
        switch(opcao){
        case 1:
            printf("Digite a quantidade de produtos: ");
            scanf("%d", &quant);
            cadastrar_produtos(quant);
            break;
        case 2:
            if( quant == 0 ){
                printf("\nNão há nada no estoque para exibir!!! :( \n");
            }else{
                printf("Digite o setor: ");
                scanf("%c", &setor);
                getchar();
                printf("\nQuant = %d Setor = %s\n", quant, setor);
                pesquisar_por_setor(setor, quant);
                Sleep(1000);
                system("cls");
            }
            break;
        case 3:
            if( quant == 0 ){
                printf("\nNão há nada no estoque para exibir!!! :( \n");
            }else{
                printf("O Capital Total de Produto Investido: \n");
                printf("R$ 20.2f", calcular_capital( quant ));
                Sleep(1000);
                system("cls");
            }
            break;
        default:
            if( opcao == 0 ){
                printf("\nVocê escolheu sair!!!");
                Sleep(2000);
                system("cls");
            }else{
                printf("\n\aDigite uma opção válida!!! :( ");
                Sleep(2000);
                system("cls");
            }
        }
    }while( opcao != 0 );
}
