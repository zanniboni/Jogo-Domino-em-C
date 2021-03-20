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
peca jogador1[7];
peca jogador2[7];
peca jogador3[7];
peca jogador4[7];

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

int popularJogadores(int jogador){

	int i;
	int j = 0;
	int x = jogador;
	
	for(i = 0;i <= 6;i++)
	{	
		if(jogador == 2)
		{

			jogador1[j].lado1 = pecas[x].lado1;
			jogador1[j].lado2 = pecas[x].lado2;
			
			jogador2[j].lado1 = pecas[x + 7].lado1;
			jogador2[j].lado2 = pecas[x + 7].lado2;
		
			printf("\nJogador 1: (%d,%d)\n", jogador1[j].lado1, jogador1[j].lado2);
			desenharPecas(jogador1[j].lado1, jogador1[j].lado2);
			printf("\nJogador 2: (%d, %d)\n ",jogador2[j].lado1, jogador2[j].lado2);
			desenharPecas(jogador2[j].lado1, jogador2[j].lado2);
			x++;
			j++;

		} else if(jogador == 4){
			jogador1[j].lado1 = pecas[x].lado1;
			jogador1[j].lado2 = pecas[x].lado2;
			
			jogador2[j].lado1 = pecas[x + 7].lado1;
			jogador2[j].lado2 = pecas[x + 7].lado2;
			
			jogador3[j].lado1 = pecas[x + 14].lado1;
			jogador3[j].lado2 = pecas[x + 14].lado2;
			
			jogador4[j].lado1 = pecas[x + 21].lado1;
			jogador4[j].lado2 = pecas[x + 21].lado2;
			printf("Jogador 1: (%d,%d) - Jogador 2: (%d, %d) - Jogador 3: (%d, %d) - Jogador 4: (%d, %d)\n", jogador1[j].lado1, jogador1[j].lado2, jogador2[j].lado1, jogador2[j].lado2, jogador3[j].lado1, jogador3[j].lado2, jogador4[j].lado1, jogador4[j].lado2);
			x++;
			j++;
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

void embaralharVetor(peca *vet, int vetSize)
{
	int i;
	for (i = 0; i < vetSize; i++)
	{
		int r = rand() % vetSize;
	
		peca temp = vet[i];
		vet[i] = vet[r];
		vet[r] = temp;
	}
}

void selecaoJogadores()
{
	int i;
	printf("Digite o numero de jogadores 2-4\n");
	scanf("%i", &i);
	
	switch (i)
	{
		case 2:
			popularJogadores(i);
			break;	
			
		case 4:
			popularJogadores(i);
			break;
			
		default:
			printf("ERRO."); 
			break;			
	}
}
void desenhaMenu()
{
	int i = 0;
	printf("Menu - Jogo de Domino\n");
	printf("1- Comecar jogo.\n");
	printf("2- Imprimir pecas.\n");
	printf("9- Sair\n");
	scanf("%i", &i);
	
	switch (i)
	{
	   case 1:
		popularPecas();
		embaralharVetor(pecas, 28);
		selecaoJogadores();
		break;
	
	   case 2:
		imprimePecas();
		break;
		
		case 9:
			return 0;
			break;
	}
}
int main(int argc, char *argv[]) {
	

	desenhaMenu();
	return 0;
}
