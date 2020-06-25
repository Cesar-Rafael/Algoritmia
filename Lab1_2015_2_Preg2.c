#include <stdio.h>
#include <math.h>

void imprimirCaracterPos(int pos, int cant, int c){
	for(int i=0; i<pos; i++) putchar(' ');
	for(int i = 0; i < cant; i++) putchar(c);
	putchar('\n');
}

void patron(int n, int i){
	if (n==2){
		imprimirCaracterPos(i, 1, '*');
		imprimirCaracterPos(i, n, '*');
		imprimirCaracterPos(i+1, 1, '*');
	}else{
		patron(n/2, i);

		imprimirCaracterPos(i, n, '*');

		patron(n/2, n/2+i);
	}
}



int main(){
	int n,i;

	scanf("%d %d",&n,&i);

	patron(n,i);
	return 0;
}