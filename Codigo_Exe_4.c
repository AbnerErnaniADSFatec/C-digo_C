#include <stdio.h>
#include <locale.h>
#include <math.h>

struct ponto{
    int x;
    int y;
};

struct ponto vet_ponto[2];

float calcula_distancia( int x1, int y1, int x2, int y2 ){
    float distancia = sqrt( pow(( x2 - x1 ), 2) + pow(( y2 - y1 ), 2) );
    return distancia;
}

void main(){
    setlocale(LC_ALL, "Portuguese");
    int i;
    for( i = 0; i < 2; i++ ){
        printf("Ponto %d:\n", (i + 1));
        printf("X%d = ", (i + 1));
        scanf("%d", &vet_ponto[i]);
        printf("Y%d = ", (i + 1));
        scanf("%d", &vet_ponto[i]);
        system("cls");
    }
    printf("Distância = %5.2f", calcula_distancia( vet_ponto[0].x, vet_ponto[0].y, vet_ponto[1].x, vet_ponto[1].y ));
}
