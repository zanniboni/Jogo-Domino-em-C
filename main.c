#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 128

struct structPeca
{
	int lado1;
	int lado2;
};	
typedef struct structPeca peca;
peca pecas[28];

int popularPecas(){

	int i;
	int j;
	int x = 0;
	
	for(i = 0;i <= 6;i++){
		for(j = i;j <= 6;j++){
			pecas[x].lado1 = i;
			pecas[x].lado2 = j;
			x++;
		}
	}
	
	return 0;
}

int imprimePecas(){
	
	int i;
	int j;
	int x = 0;
	
	for(i = 0;i <= 6;i++){
		for(j = i;j <= 6;j++){
			printf("\nPeca: (%d %d)\n", pecas[x].lado1, pecas[x].lado2);
			desenharPecas(i, j);
			x++;
		}
	}
 
	return 0;
	
}

int desenharPecas(int i, int j){
	
	char str1[12];
	char str2[12];
	sprintf(str1, "Pecas/(%d,", i);
	sprintf(str2, "%d).txt", j);

	strcat(str1, str2);
	
    char *filename = str1;
    FILE *fptr = NULL;

    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }

    print_image(fptr);

    fclose(fptr);

    return 0;
	
}

void print_image(FILE *fptr)
{
    char read_string[MAX_LEN];

    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}

int main(int argc, char *argv[]) {
	
	
	popularPecas();
	imprimePecas();
	return 0;
}
