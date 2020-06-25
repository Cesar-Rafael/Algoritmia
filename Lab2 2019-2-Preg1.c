#include <stdio.h>
#include <limits.h>
#define MAX_1 20
#define MAX_2 50


int BuscarNumero(int almacen[MAX_1][MAX_1][2], int ini_fil, int ini_col, int fin_fil, int fin_col, int num){
    int med_fil, med_col, cont=0;

    if(ini_fil == fin_fil && ini_col == fin_col){
        if(almacen[ini_fil][ini_col][0] == num){
            printf(" (%d,%d) ", ini_fil, ini_col);
            cont += almacen[ini_fil][ini_col][1];
            return cont;
        }
    }

    if(ini_col+1 == fin_col){
        for(int i=ini_fil; i<=fin_fil; i++)
            for(int j=ini_col; j<=fin_col; j++)
                if(almacen[i][j][0] == num){
                    printf(" (%d,%d) ", i, j);
                    cont += almacen[i][j][1];
                    return cont;
                }
    }

    med_fil = (ini_fil + fin_fil)/2;
    med_col = (ini_col + fin_col)/2;

    if(almacen[med_fil][med_col][0] <= num){
        cont += BuscarNumero(almacen, med_fil, med_col, fin_fil, fin_col, num);
        cont += BuscarNumero(almacen, med_fil+1, ini_col, fin_fil, med_col-1, num);
    }
    if(almacen[med_fil][med_col][0] >= num){
        cont += BuscarNumero(almacen, ini_fil, ini_col, med_fil, med_col,num);
        cont += BuscarNumero(almacen, ini_fil, med_col+1, med_fil-1, fin_col, num);
    }

    return cont;
}

void merge(int palets[], int cant[], int ini, int med, int fin) {
    int l1, l2, i;
    int p = 0, q = 0;

    l1 = med - ini + 1;
    l2 = fin - med;

    int leftArray1[l1 + 1];
    int leftArray2[l1 + 1];
    int rightArray1[l2 + 1];
    int rightArray2[l2 + 1];

    for (i = ini; i <= med; i++) {
        leftArray1[i - ini] = palets[i];
        leftArray2[i - ini] = cant[i];
    }
    leftArray1[l1] = INT_MAX;

    for (i = med + 1; i <= fin; i++) {
        rightArray1[i - med - 1] = palets[i];
        rightArray2[i - med - 1] = cant[i];
    }
    rightArray1[l2] = INT_MAX;

    for (i = ini; i <= fin; i++) {
        if (leftArray1[p] < rightArray1[q]) {
            palets[i] = leftArray1[p];
            cant[i] = leftArray2[p++];
        } else {
            palets[i] = rightArray1[q];
            cant[i] = rightArray2[q++];
        }
    }
}

void MergeSort(int palets[], int cant[], int ini, int fin) {
    int med;
    if (ini == fin) return;
    med = (ini + fin) / 2;
    MergeSort(palets, cant, ini, med);
    MergeSort(palets, cant, med + 1, fin);
    merge(palets, cant, ini, med, fin);
}

int main() {
    FILE *datos = fopen("datos1.txt", "r");
    int num, fil, col, cant_palets, almacen[MAX_1][MAX_1][2], k = 0;
    printf("Ingrese filas, columnas, palets:\n");
    scanf("%d %d %d", &fil, &col, &cant_palets);
    int palets[cant_palets], cant[cant_palets];

    for (int i = 0; i < MAX_1; i++)
        for (int j = 0; j < MAX_1; j++)
            almacen[i][j][0] = 9999;

    for (int i = 0; i < cant_palets; i++)
        fscanf(datos, "%d %d", &palets[i], &cant[i]);

    putchar('\n');

    for (int i = 0; i < cant_palets; i++)
        printf("%d %d\n", palets[i], cant[i]);

    MergeSort(palets, cant, 0, cant_palets - 1);

    putchar('\n');

    for (int i = 0; i < fil; i++){
        for (int j = 0; j < col; j++){
            if(k<cant_palets){
                almacen[i][j][0] = palets[k];
                almacen[i][j][1] = cant[k++];
            }
        }
    }

    for (int i = 0; i < fil; i++){
        for (int j = 0; j < col; j++){
            if( almacen[i][j][0] != 9999)
                printf("%04d ", almacen[i][j][0]);
        }
        printf("\n");
    }

    printf("Ingrese producto a buscar: ");
    scanf("%d", &num);
    printf("Coordenadas: ");

    int cant_veces;
    cant_veces = BuscarNumero(almacen, 0, 0, fil-1, col-1, num);
    printf("\nCantidad en almacen: %d unidades\n", cant_veces);
    return 0;
}