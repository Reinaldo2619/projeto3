#include "contatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CadastrarContato(Contato agenda[], int *ncontato) {
  if (*ncontato >= MAX_CONTATOS) {
    printf("Não é possível cadastrar mais contatos, Excedeu o limite máximo de "
           "contatos\n");
    return;
  }

  printf("Digite o nome :");
  if (scanf(" %s", agenda[*ncontato].nome) != 1) {
    printf("erro ao ler o nome\n");
  }
  return;

  printf("Digite o sobrenome :");
  if (scanf(" %s", agenda[*ncontato].sobrenome) != 1) {
    printf("erro ao ler o sobrenome\n");
  }
  return;

  printf("Digite o email :");
  if (scanf(" %s", agenda[*ncontato].email) != 1) {
    printf("erro ao ler o email\n");
  }
  return;

  printf("Digite o telefone :");
  if (scanf(" %s", agenda[*ncontato].tel) != 1) {
    printf("erro ao ler o telefone\n");
    return;
  }
    (*ncontato)++;
  }