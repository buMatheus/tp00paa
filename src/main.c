#include "includes/colors.h"

#define LINHAS 22
#define COLUNAS 82

void iniciaQuadro(char quadro[LINHAS][COLUNAS]);
void criaFiguras(int opcao, int qtd, char quadro[LINHAS][COLUNAS]);
void printQuadro(char quadro[LINHAS][COLUNAS]);
int escolhaFigura(int opcao, int x, int y, int cor, char quadro[LINHAS][COLUNAS]);
int verificaPX(char quadro[LINHAS][COLUNAS], int x, int y);
int verificaPM(char quadro[LINHAS][COLUNAS], int x, int y);
int verificaPA(char quadro[LINHAS][COLUNAS], int x, int y);
int verificaP7(char quadro[LINHAS][COLUNAS], int x, int y);
int verificaPosicao(char quadro[LINHAS][COLUNAS], int x, int y, int desenho);
int desenhaX(char quadro[LINHAS][COLUNAS], int x, int y, int cor);
int desenhaMais(char quadro[LINHAS][COLUNAS], int x, int y, int cor);
int desenhaA(char quadro[LINHAS][COLUNAS], int x, int y, int cor);
int desenha7(char quadro[LINHAS][COLUNAS], int x, int y, int cor);
void persisteA(char quadro[LINHAS][COLUNAS], int x, int y);
void persisteM(char quadro[LINHAS][COLUNAS], int x, int y);
void persisteX(char quadro[LINHAS][COLUNAS], int x, int y);
void persiste7(char quadro[LINHAS][COLUNAS], int x, int y);
void mudaCor(int cor);

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
					quadro[contL][contC] = ' ';
				}
			}
		}
	}
	//printQuadro(quadro);
}
void criaFiguras(int opcao, int qtd, char quadro[LINHAS][COLUNAS]){
	int cor, posicaoX, posicaoY, cont, resultado;
	for(cont = 0; cont < qtd; cont++){
		srand(time(NULL));
		//valor aleatório para escolher uma cor
		cor = ((rand()%6) +1);
		//coordenadas iniciais da minha figura
		posicaoX = (rand()%(LINHAS-7))+6;
		posicaoY = (rand()%(COLUNAS-12))+10;
		//printf("Cor: %d, X: %d, Y: %d,\n", cor, posicaoX, posicaoY);
		//verifica posição válida
		if((opcao == 4)||(opcao == 5)){
			//figuras sortidas
			resultado = escolhaFigura((rand()%4)+1,posicaoX,posicaoY, cor, quadro);
			if(resultado == 1){
				cont--;
			}
		}else{
			// Figuras simples
			resultado = escolhaFigura(opcao,posicaoX,posicaoY, cor, quadro);
			if(resultado == 1){
				cont--;
			}
		}
	}
	printQuadro(quadro);
}

void printQuadro(char quadro[LINHAS][COLUNAS]){
	int linha, coluna;
	for(linha = 0; linha < LINHAS; linha++){
		mudaCor(((rand()%6) +1));
		for(coluna = 0; coluna < COLUNAS; coluna++){
			printf("%c", quadro[linha][coluna]);
		}
		reset();
		printf("\n");
	}

}

int escolhaFigura(int opcao, int x, int y, int cor, char quadro[LINHAS][COLUNAS]){
	int resultado;
	switch (opcao){
		case 1:
			resultado = desenhaA(quadro,x,y,cor);
			if(resultado == 0){
				printf("VAZIO\n");
				return 0;
			}else{
				printf("Preenchido\n");
				return 1;
			}
		break;
		case 2:
			resultado = desenhaMais(quadro,x,y,cor);
			if(resultado == 0){
				printf("VAZIO\n");
				return 0;
			}else{
				printf("Preenchido\n");
				return 1;
			}
		break;
		case 3:
			resultado = desenhaX(quadro,x,y,cor);
			if(resultado == 0){
				printf("VAZIO\n");
				return 0;
			}else{
				printf("Preenchido\n");
				return 1;
			}
		break;
		case 4:
			resultado = desenha7(quadro,x,y,cor);
			if(resultado == 0){
				printf("VAZIO\n");
				return 0;
			}else{
				printf("Preenchido\n");
				return 1;
			}
		break;
		default:
			return 0;
	}
}

int desenhaA(char quadro[LINHAS][COLUNAS], int x, int y, int cor){
	int isValido;
	isValido = verificaPosicao(quadro, x, y, 1);
	if (isValido == 1){
		return isValido;
	}
	persisteA(quadro,x,y);
	return isValido;
}

int desenhaMais(char quadro[LINHAS][COLUNAS], int x, int y, int cor){
	int isValido;
	isValido = verificaPosicao(quadro, x, y, 2);
	if (isValido == 1){
		return isValido;
	}
	persisteM(quadro,x,y);
	return isValido;
}

int desenhaX(char quadro[LINHAS][COLUNAS], int x, int y, int cor){
	int isValido;
	isValido = verificaPosicao(quadro, x, y, 3);
	if (isValido == 1){
		return isValido;
	}
	persisteX(quadro,x,y);
	return isValido;
}

int desenha7(char quadro[LINHAS][COLUNAS], int x, int y, int cor){
	int isValido;
	isValido = verificaPosicao(quadro, x, y, 4);
	if (isValido == 1){
		return isValido;
	}
	persiste7(quadro,x,y);
	return isValido;
}

void mudaCor(int cor){
	switch(cor){
		case 1:
			red();
		break;
		case 2:
			yellow();
		break;
		case 3:
			green();
		break;
		case 4:
			white();
		break;
		case 5:
			blue();
		break;
		case 6:
			purple();
		break;
		case 7:
			cyan();
		break;
		default:
		break;
	}
}

int verificaPosicao(char quadro[LINHAS][COLUNAS], int x, int y, int desenho){
	switch (desenho){
		case 1:
			return verificaPA(quadro,x,y);
		break;
		case 2:
			return verificaPM(quadro,x,y);
		break;
		case 3:
			return verificaPX(quadro,x,y);
		break;
		case 4:
			return verificaP7(quadro,x,y);
		break;
		default:
			return 0;
	}	
}

int verificaPA(char quadro[LINHAS][COLUNAS], int x, int y){
	int isCheio;
	//apenas 1 ou seja posição inicial
	if(quadro[x][y] != ' '){
		isCheio = 1;
	}
	return isCheio;
}

int verificaPM(char quadro[LINHAS][COLUNAS], int x, int y){ // retorna 0 é pq ta vazio
	int isCheio;
	isCheio = 0;
	//posição inicia o primeiro de cima
	if(quadro[x][y] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x][y-1] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x][y-2] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x-2][y-2] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x-1][y-2] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x+1][y-2] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x+2][y-2] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x][y-3] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x][y-4] != ' '){
		isCheio = 1;
		return isCheio;
	}
	return isCheio;
}

int verificaPX(char quadro[LINHAS][COLUNAS], int x, int y){
	int isCheio;
	isCheio = 0;
	if(quadro[x][y] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x+4][y] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x+1][y-1] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x+3][y-1] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x+2][y-2] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x+1][y-3] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x+3][y-3] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x][y-4] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x+4][y-4] != ' '){
		isCheio = 1;
		return isCheio;
	}
	return isCheio;
}

int verificaP7(char quadro[LINHAS][COLUNAS], int x, int y){
	int isCheio;
	isCheio = 0;
	if(quadro[x][y] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x][y+1] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x][y+2] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x+1][y+2] != ' '){
		isCheio = 1;
		return isCheio;
	}
	if(quadro[x+2][y+1] != ' '){
		isCheio = 1;
		return isCheio;
	}
	return isCheio;
}

void persisteA(char quadro[LINHAS][COLUNAS], int x, int y){
	quadro[x][y] = '*';
}
void persisteM(char quadro[LINHAS][COLUNAS], int x, int y){
	quadro[x][y] = '*';
	quadro[x][y-1] = '*';
	quadro[x][y-2] = '*';
	quadro[x-2][y-2] = '*';
	quadro[x-1][y-2] = '*';
	quadro[x+1][y-2] = '*';
	quadro[x+2][y-2] = '*';
	quadro[x][y-3] = '*';
	quadro[x][y-4] = '*';
}
void persisteX(char quadro[LINHAS][COLUNAS], int x, int y){
	quadro[x][y] = '*';
	quadro[x+4][y] = '*';
	quadro[x+1][y-1] = '*';
	quadro[x+3][y-1] = '*';
	quadro[x+2][y-2] = '*';
	quadro[x+1][y-3] = '*';
	quadro[x+3][y-3] = '*';
	quadro[x][y-4] = '*';
	quadro[x+4][y-4] = '*';
}
void persiste7(char quadro[LINHAS][COLUNAS], int x, int y){
	quadro[x][y] = '*';
	quadro[x][y+1] = '*';
	quadro[x][y+2] = '*';
	quadro[x+1][y+2] = '*';
	quadro[x+2][y+1] = '*';
}

