typedef struct c_cliente *c;

void gravarArquivo(c_cliente* c){
    FILE *arq;
    int pos = 0;
    arq = fopen("C:\\Users\\thiag\\Desktop\\TesteArquivo\\cliente.txt","wb");
    if(arq == NULL){
        printf("Erro na abertura do arquivo\n");
        return 0;
    }
    for(int i = 0; i < 10;i++){
         fprintf(arq, "%s;%d;%.2lf", (c+pos)->nome, (c+pos)->anoNascimento, (c+pos)->montante);
    }
    fclose(arq);

    return 0;

}
