#include "includes/colors.h"

#define LINHAS 22
#define COLUNAS 82

void iniciaQuadro(char quadro[LINHAS][COLUNAS]);
void criaFiguras(int opcao, int qtd, char quadro[LINHAS][COLUNAS]);
void printQuadro(char quadro[LINHAS][COLUNAS]);
int escolhaFigura(int opcao);
//Numero aleatorio 1 - 7
//numero aleatorio de posição

int menu();

void main(int argc, char *argv[]) {
	int eFinal;
	eFinal = 0;
	while (eFinal == 0){
		eFinal = menu(); //função que faz tudo e retorna quando o usuário não quer mais criar quadros
	}
}

int menu(){
	int opcao, qtd, repetir;
	int cor, posicaoX, posicaoY;
	char quadro[LINHAS][COLUNAS];
	srand(time(NULL));
	printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n=================================\nEscolha o tipo de figura basica a ser usada para criar a obra:\n1 - asterisco simples.\n2 - simbolo de soma com asteriscos.\n3 - letra X com asteriscos.\n4 - figuras aleatorias\n5 ou qualquer outro numero – opcao de obra de arte criada pelo aluno\n");
	green();
	printf("Digite o tipo de figura basica desejada: ");
	reset();
	scanf("%d", &opcao);
	cyan();
	printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio): ");
    reset();
    scanf("%d", &qtd);
    iniciaQuadro(quadro);
    //Lógicas de escolhas
	//printf("Opção: %d, Quantidade: %d\n", opcao, qtd);
	//valor aleatório para escolher uma cor
	cor = (rand()%6) +1;
	//coordenadas iniciais da minha figura
	posicaoX = (rand()%(LINHAS-3))+1;
	posicaoY = (rand()%(COLUNAS-3))+1;
    criaFiguras(opcao, qtd, quadro);
    yellow();
    printf("\n\n\n          Sim = 0; Nao = 1\n");
    printf("Deseja fazer uma nova obra de arte?: ");
    reset();
    scanf("%d", &repetir);
    if(repetir != 1){
    	repetir = 0;
    }
    return repetir;
}
// 20 linhas por 80 colunas
void iniciaQuadro(char quadro[LINHAS][COLUNAS]){
	for(int contL = 0; contL < LINHAS; contL++){
		for(int contC = 0; contC < COLUNAS; contC++){
			if(contL == 0){
				quadro[contL][contC] = '-';
			}else if(contL == (LINHAS-1)){
				quadro[contL][contC] = '-';
			}else{
				if((contC == 0)||(contC == (COLUNAS-1))){
					quadro[contL][contC] = '|';
				}else{
					quadro[contL][contC] = '*';
				}
			}
		}
	}
	//printQuadro(quadro);
}
void criaFiguras(int opcao, int qtd, char quadro[LINHAS][COLUNAS]){

	//printf("Cor: %d, X: %d, Y: %d,\n", cor, posicaoX, posicaoY);
	//verifica posição válida


}

void printQuadro(char quadro[LINHAS][COLUNAS]){
	int linha, coluna;
	for(linha = 0; linha < LINHAS; linha++){
		for(coluna = 0; coluna < COLUNAS; coluna++){
			printf("%c", quadro[linha][coluna]);
		}
		printf("\n");
	}

}

int escolhaFigura(int opcao){
	switch (opcao){
		case 1:
			return 1;
		break;
		case 2:
			return 2
		break;
		case 3:
			return 3;
		break;
		case 4:
			return 4;
		break;
		case 5:
			return 5;
		break;
		default:
			return 0;
	}
}

