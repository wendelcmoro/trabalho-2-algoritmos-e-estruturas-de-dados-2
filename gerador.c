#include <stdio.h>

int main(){
	FILE *a;
	int b;
	a = fopen("teste.txt", "w");
	for (int i=0;; i++){
		b = i;//* (-1);
		printf ("%d", i);
		//fprintf(a,"%d ", b);
	}
	return 0;
}
