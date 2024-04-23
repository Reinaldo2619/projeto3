#include <stdio.h>
#include "contatos.h"
#include <string.h>
#include <stdlib.h>

void CadastrarContato(Contato agenda[], int *ncontato){
  if(*ncontato >= MAX_CONTATOS){
    printf("Não é possível cadastrar mais contatos, Excedeu o limite máximo de contatos\n");
    return;
  }
  printf("Digite o nome :");
  scanf("%s", agenda[ncontato].nome);
  printf("Digite o sobrenome :");
  scanf("%s", agenda[*ncontato].sobrenome);
  printf("Digite o email :");
  scanf("%s", agenda[*ncontato].email);
  printf("Digite o telefone :");
  scanf("%s", agenda[*ncontato].tel);
  (*ncontato)++;
  
}