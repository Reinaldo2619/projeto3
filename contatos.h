#ifndef _CONTATOS_H
#define _CONTATOS_H
#define MAX_CONTATOS 255

typedef struct{
char nome [50];
char sobrenome [50];
char email [50];
char tel [20];

}Contato;

void CadastrarContato(Contato agenda[], int *ncontato);

#endif 