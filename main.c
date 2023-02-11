#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    char nome[30];
    int anoNascimento;
    double montante;
}c_cliente;

int opcao = 0;

void menu()
{
	printf("+-------------------------------------------+\n");
	printf("|\t\tSISTEMA			\n");
	printf("+-------------------------------------------+\n");
	printf("| [ 1 ] - Incluir um novo cliente \n");
	printf("| [ 2 ] - Listar clientes \n");
	printf("| [ 3 ] - Remover cliente \n");
	printf("| [ 4 ] - Zerar todos montantes \n");
	printf("| [ 5 ] - Listar o melhor comprador \n");
	printf("| [ 6 ] - Exibir montante de um cliente específico \n");
	printf("| [ 7 ] - Sair \n");
	printf("+-------------------------------------------+\n");
	printf("|Opção ");
	scanf("%d", &opcao);

	/*- incluir um novo cliente
	- remover cliente - atualizar o montante de compras do cliente realizadas no mês corrente
	- zerar todos os montantes de compras por ocasião da virada de mês
	- listar o cliente melhor comprador
	- exibir um montante de compras de um cliente específico.*/
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int i = 0;
	char cont;

	c_cliente cliente[10];
	c_cliente* c;
	c = &cliente[0];

	for(int i = 0; i < 10; i++)
	{
		//cout << "Zerando montante do " << i + 1 << " cliente: " << endl;
		strcpy((c + i)->nome, "");
		(c + i)->anoNascimento = 0;
		(c + i)->montante = 0.0;
	}


    do{
        system("cls");
        menu();
    }while(opcao != 7);


    return 0;
}
