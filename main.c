#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "arquivos.h"

typedef struct{
    char nome[30];
    int anoNascimento;
    double montante;
}c_cliente;

int opcao = 0, j = 0;

void limpar_entrada() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void inicializarPonteiros(c_cliente* c){ 
	for(j = 0; j < 10; j++)
	{
		strcpy((c + j)->nome, "");
		(c + j)->anoNascimento = 0;
		(c + j)->montante = 0.0;
	}
}

void incluirCliente(c_cliente* c)
{
	system("cls");
	static int i = 0;
	char cont;

	do
	{
		printf("Dados do %dº cliente \n", i + 1);
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
			printf("Atingido quantidade máxima de clientes");
			break;
		}
	}
	while(i < 10 || cont == 'n' || cont == 'N');
}

void listarCliente(c_cliente* c)
{
	for(j = 0; j < 10; j++)
	{
		if(((c + j)-> nome != "") || ((c + j)-> nome !="-"))
		{
			printf("===================================\n");
			printf("Dados do %d cliente \n", j + 1);
			printf("===================================\n");
			printf("Nome: %s \n", (c+j)-> nome) ;
			printf("Ano Nascimento: %d\n", (c + j)->anoNascimento);
			printf("Montante em R$%.2lf\n", (c + j)->montante);
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
	//int i; 
	for(j = 0; j < 10; j++)
	{
		if(!strcmp(procurar, (c + j)-> nome))
		{
			strcpy((c + j)->nome, "-");
			(c + j)->anoNascimento = 0;
			(c + j)->montante = 0;
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
		for(j = 0; j < 10; j++)
		{
			printf("Zerando montante do %d cliente que eh %s\n", j + 1, (c+j)->nome);
			(c + j)->montante = 0.0;
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
	//int i; 
	for(j = 1; j < 10; j++)
	{
		if((c + j)->montante > mon)
		{
			strcpy(n, (c + j)->nome);
			ano = (c + j)->anoNascimento;
			mon = (c + j)->montante;
		}
	}
	printf("Nome do Melhor comprador %s com ano de nascimento %d no valor de montante de R$%.2lf\n", n, ano, mon);
}

void montanteCliente(c_cliente* c){
	char n[30];
	double m;
	printf("Informe um nome para somar:  ");
	scanf("%s", n);
	//int i;
	for(j = 0; j < 10;j++){
		if(!strcmp(n,(c + j)-> nome))
		{
			m += (c + j)->montante;
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
	printf("| [ 6 ] - Exibir montante de um cliente específico \n");
	printf("| [ 7 ] - Operacoes de Arquivo\n");
	printf("| [ 8 ] - Sair \n");
	printf("+-------------------------------------------+\n");
	printf("|Opção ");
	scanf("%d", &opcao);

	/*- incluir um novo cliente
	- remover cliente - atualizar o montante de compras do cliente realizadas no mês corrente
	- zerar todos os montantes de compras por ocasião da virada de mês
	- listar o cliente melhor comprador
	- exibir um montante de compras de um cliente específico.*/
}

void operacoes_arquivo(){
    char op;
    system("cls");
    limpar_entrada();
    printf("===========================================\n");
    printf(" [ g ] -> Gravar em arquivo \n");
    printf(" [ r ] -> Ler em arquivo \n");
    printf(" [ v ] / [ x ]- Voltar para o Menu anterior\n");
    printf("===========================================\n");
    printf("Opcao: ");
    scanf("%c", &op);
    switch(op){
        case 'g':
            //gravarArquivo(&cliente[0]);
        break;
        case 'v': case 'x':
            menu();
        break;
    }
    system("cls");
}



int main()
{
    setlocale(LC_ALL, "Portuguese");

    int i = 0;
	char cont;

	c_cliente cliente[10];
	c_cliente* c;
	c = &cliente[0];
	 
	inicializarPonteiros(&cliente[0]); 

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
            /*case 7:
                operacoes_arquivo();
                break;*/
        }
    }while(opcao != 8);


    return 0;
}
