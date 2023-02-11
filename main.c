#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    char nome[30];
    int anoNascimento;
    double montante;
}c_cliente;

int opcao = 0;

void limpar_entrada() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void incluirCliente(c_cliente* c)
{
	//system("cls");
	int i = 0;
	char cont;

	do
	{
		printf("Dados do %d� cliente \n");
		printf("Nome: " );
		scanf("%s",  &(c + i)->nome);
		printf("Ano Nascimento: ");
		scanf("%d",&(c + i)-> anoNascimento);
		printf("Montante em Gastos  R$");
		scanf("%lf",&(c + i)->montante);
		i++;
		limpar_entrada();
		printf("Deseja continuar [S/N] " ) ;
		scanf("%c", &cont);
		if((cont == 'n') || (cont == 'N'))
		{
			break;
		}
		if( i >= 10)
		{
			printf("Atingido quantidade m�xima de clientes");
			break;
		}
	}
	while(i < 10 || cont == 'n' || cont == 'N');
}


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
	printf("| [ 6 ] - Exibir montante de um cliente espec�fico \n");
	printf("| [ 7 ] - Sair \n");
	printf("+-------------------------------------------+\n");
	printf("|Op��o ");
	scanf("%d", &opcao);

	/*- incluir um novo cliente
	- remover cliente - atualizar o montante de compras do cliente realizadas no m�s corrente
	- zerar todos os montantes de compras por ocasi�o da virada de m�s
	- listar o cliente melhor comprador
	- exibir um montante de compras de um cliente espec�fico.*/
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
        switch(opcao){
            case 1:
            incluirCliente(&cliente[0]);
            break;
        }
    }while(opcao != 7);


    return 0;
}
