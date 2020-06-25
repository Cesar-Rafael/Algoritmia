#include <stdio.h>

int  triangulo(int a, int b){	
	int puntos = 0;
	if(a<=b){
		for(int i=0;i<a;i++)  //3
			printf(" * ");  
		printf("\n");
		puntos = a;
		puntos += triangulo(a+1,b);	//4
		for(int i=0;i<a;i++)  //  3
			printf(" * ");  
		printf("\n");
		puntos += a;
	}
	return puntos;
}

int main(){	
	int punt = triangulo(3,5);
	printf("%d\n", punt);
}