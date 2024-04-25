#include "contatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para limpar o buffer de entrada
void limparBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

void CadastrarContato(Contato agenda[], int *ncontato) {
  if (*ncontato >= MAX_CONTATOS) {
    printf("Não é possível cadastrar mais contatos, Excedeu o limite máximo de "
           "contatos\n");
    return;
  }

  printf("Digite o nome: ");
  if (scanf("%s", agenda[*ncontato].nome) != 1) {
    printf("Erro ao ler o nome\n");
    limparBuffer(); // Limpar o buffer de entrada
    return;
  }

  printf("Digite o sobrenome: ");
  if (scanf("%s", agenda[*ncontato].sobrenome) != 1) {
    printf("Erro ao ler o sobrenome\n");
    limparBuffer(); // Limpar o buffer de entrada
    return;
  }

  printf("Digite o email: ");
  if (scanf("%s", agenda[*ncontato].email) != 1) {
    printf("Erro ao ler o email\n");
    limparBuffer(); // Limpar o buffer de entrada
    return;
  }

  printf("Digite o telefone: ");
  if (scanf("%s", agenda[*ncontato].tel) != 1) {
    printf("Erro ao ler o telefone\n");
    limparBuffer(); // Limpar o buffer de entrada
    return;
  }

  (*ncontato)++;
}

void ListarContatos(Contato agenda[], int ncontato) {
  printf("--LISTA DE CONTATOS--\n\t");
  for (int i = 0; i < ncontato; i++) {
    printf("Nome: %s\n", agenda[i].nome);
    printf("Sobrenome: %s\n", agenda[i].sobrenome);
    printf("Email: %s\n", agenda[i].email);
    printf("Telefone: %s\n", agenda[i].tel);
    printf("\n\t");
  }
}
void SalvarContatos(Contato agenda[], int ncontato) {
  FILE *arquivo = fopen("arquivo.bin", "wb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo\n");
    return;
  }
  fwrite(&ncontato, sizeof(int), 1, arquivo);
  fwrite(agenda, sizeof(Contato), ncontato, arquivo);

  fclose(arquivo);
}
void CarregarContatos(Contato agenda[], int *ncontato) {
  FILE *arquivo = fopen("arquivo.bin", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo\n");
    return;
  }

  size_t num_elements_read;

  num_elements_read = fread(ncontato, sizeof(int), 1, arquivo);
  if (num_elements_read != 1) {
    printf("Erro ao ler o número de contatos\n");
    fclose(arquivo);
    return;
  }

  num_elements_read = fread(agenda, sizeof(Contato), *ncontato, arquivo);
  if (num_elements_read != *ncontato) {
    printf("Erro ao ler os contatos\n");
    fclose(arquivo);
    return;
  }

  fclose(arquivo);
}
void DeletarContatos(Contato agenda[], int *ncontato, char *tel) {

  for (int i = 0; i < *ncontato; i++) {
    if (strcmp(agenda[i].tel, tel) == 0) {
      for (int j = i; j < *ncontato - 1; j++) {
        agenda[j] = agenda[j + 1];
      }
      (*ncontato)--;
      printf("Contato deletado com sucesso\n");
      return;
    }
  }
  printf("Contato com telefone %s não encontrado\n", tel);
}