//typedef struct c_cliente *c;
#include "main.h"

typedef struct c_cliente *c;

void gravarArquivo(c_cliente *c){
    FILE *arq;
    int pos = 0;
    arq = fopen("C:\\Users\\thiag\\Desktop\\TesteArquivo\\cliente.txt","wb");
    if(arq == NULL){
        printf("Erro na abertura do arquivo\n");
        return 0;
    }
    for(pos = 0; pos < 10;pos++){
         fprintf(arq, "%s;%d;%.2lf\n", (c+pos)->nome, (c+pos)->anoNascimento, (c+pos)->montante);
    }
    fclose(arq);

    return 0;

}
