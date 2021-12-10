#include "includes/colors.h"

void iniciaQuadro();
void criaFiguras(int opcao, int qtd);
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
	printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n=================================\nEscolha o tipo de figura basica a ser usada para criar a obra:\n1 - asterisco simples.\n2 - simbolo de soma com asteriscos.\n3 - letra X com asteriscos.\n4 - figuras aleatorias\n5 ou qualquer outro numero – opcao de obra de arte criada pelo aluno\n");
	green();
	printf("Digite o tipo de figura basica desejada: ");
	reset();
	scanf("%d", &opcao);
	cyan();
	printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio): ");
    reset();
    scanf("%d", &qtd);
    iniciaQuadro();
    criaFiguras(opcao, qtd);
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

void iniciaQuadro(){
	red();
	printf("\nAinda nao fui feito!\n");
}
void criaFiguras(int opcao, int qtd){
	red();
	printf("\nAinda nao fui feito!\n");
}