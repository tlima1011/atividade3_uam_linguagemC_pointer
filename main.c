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
	system("cls");
	static int i = 0;
	char cont;

	do
	{
		printf("Dados do %d� cliente \n", i + 1);
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
		system("cls");
		if( i >= 10)
		{
			printf("Atingido quantidade m�xima de clientes");
			break;
		}
	}
	while(i < 10 || cont == 'n' || cont == 'N');
}

void listarCliente(c_cliente* c)
{
	for(int i = 0; i < 10; i++)
	{
		if(((c + i)-> nome != "") || ((c + i)-> nome !="-"))
		{
			printf("===================================\n");
			printf("Dados do %d cliente \n", i + 1);
			printf("===================================\n");
			printf("Nome: %s \n", (c+i)-> nome) ;
			printf("Ano Nascimento: %d\n", (c + i)->anoNascimento);
			printf("Montante em R$%.2lf\n", (c + i)->montante);
        }
	}
}

void removerCliente(c_cliente* c)
{
	char procurar[30];
	//char procurar[30];
	limpar_entrada();
	printf("Informe um nome para remover: " );
	scanf("%s", &procurar);
	for(int i = 0; i < 10; i++)
	{
		if(!strcmp(procurar, (c + i)-> nome))
		{
			strcpy((c + i)->nome, "-");
			(c + i)->anoNascimento = 0;
			(c + i)->montante = 0;
		}
	}
}

void zerarMontantes(c_cliente* c)
{
	char zerar;
	limpar_entrada();
	printf("Deseja zerar montantes? [s][n] -> ");
	scanf("%c", &zerar);
	if(zerar == 'S' || zerar == 's')
	{
		for(int i = 0; i < 10; i++)
		{
			printf("Zerando montante do %d cliente que eh %s\n", i + i, (c+i)->nome);
			(c + i)->montante = 0.0;
		}
		printf("Montantes zerados com sucesso\n");
	}
}

void melhorComprador(c_cliente* c)
{
	printf("...Melhor Comprador...\n");
	char n[30];
	int ano = 0;
	double mon = 0;
	strcpy(n, (c + 0)->nome);
	ano = (c + 0)->anoNascimento;
	mon = (c + 0)->montante;
	for(int i = 1; i < 10; i++)
	{
		if((c + i)->montante > mon)
		{
			strcpy(n, (c + i)->nome);
			ano = (c + i)->anoNascimento;
			mon = (c + i)->montante;
		}
	}
	printf("Nome do Melhor comprador %s com ano de nascimento %d no valor de montante de R$%.2lf\n", n, ano, mon);
}

void montanteCliente(c_cliente* c){
	char n[30];
	double m;
	printf("Informe um nome para somar:  ");
	scanf("%s", n);
	for(int i = 0; i < 10;i++){
		if(!strcmp(n,(c + i)-> nome))
		{
			m += (c + i)->montante;
		}
	}
	printf("Montante do Cliente %.2lf\n", m);
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
        //system("cls");
        menu();
        switch(opcao){
            case 1:
                incluirCliente(&cliente[0]);
                break;
            case 2:
                listarCliente(&cliente[0]);
                break;
            case 3:
                removerCliente(&cliente[0]);
                break;
            case 4:
                zerarMontantes(&cliente[0]);
                break;
            case 5:
                melhorComprador(&cliente[0]);
                break;
            case 6:
                montanteCliente(&cliente[0]);
                break;
        }
    }while(opcao != 7);


    return 0;
}
