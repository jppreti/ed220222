#include <stdio.h>
#include <stdlib.h>

int main() {
    int number = 10;
    int* numberP = &number;
    int** numberPP = &numberP;

    printf("Valor da variável number: %d\n",number);
    printf("Endereço da variável number: %p\n",&number);
    printf("Valor da variável numberP: %p\n",numberP);
    printf("Valor apontado por numberP: %d\n",*numberP);
    printf("Endereco de memoria da var numberP: %p\n",&numberP);
    printf("Endereco de memoria da var numberPP: %p\n",&numberPP);
    printf("Conteudo de numberPP: %p\n",numberPP);
    printf("Valor apontado no primeiro nivel por numberPP: %p\n",*numberPP);
    printf("Valor apontado no ultimo nivel por numberPP: %d\n\n",**numberPP);   
    //numberP++;
    //printf("Valor da variável numberP++: %p\n",numberP);
    float *pi = (float *) malloc(sizeof(float));
    printf("Endereco de pi: %p\n",pi);
    *pi = 3.1415;
    *pi = 0; //para garantir a limpeza do conteúdo caso free não o faça
    free(pi);
    printf("Valor de pi após free: %f\n",*pi);
    printf("Endereco de pi após free: %p\n",pi);
    pi = NULL; //para garantir que o endereço não possa ser usado por acidente
    printf("Endereco de pi após atribuir NULL: %p\n",pi);

    return EXIT_SUCCESS;
}