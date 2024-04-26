#include "contatos.h" // Include do arquivo de cabeçalho
#include <stdio.h>    // Inclui a biblioteca padrão de entrada e saída
#include <stdlib.h>   // Inclui a biblioteca padrão de alocação de memória
#include <string.h>   // Inclui a biblioteca padrão de manipulação de strings

// Função para limpar o buffer de entrada
void limparBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
  printf("\n");
}

// função para cadastrar um contato, salvando os dados em um arquivo
void CadastrarContato(Contato agenda[], int *ncontato) {
  if (*ncontato >= MAX_CONTATOS) {
    printf("Não é possível cadastrar mais contatos, Excedeu o limite máximo de "
           "contatos\n");
    return;
  }

  printf("Digite o nome: "); // Pede o nome do contato
  if (scanf("%s", agenda[*ncontato].nome) !=
      1) { // Verifica se a entrada foi válida
    printf("Erro ao ler o nome\n");
    limparBuffer(); // Limpar o buffer de entrada
    return;
  }

  printf("Digite o sobrenome: "); // Pede o sobrenome do contato
  if (scanf("%s", agenda[*ncontato].sobrenome) !=
      1) { // Verifica se a entrada foi válida
    printf("Erro ao ler o sobrenome\n");
    limparBuffer(); // Limpar o buffer de entrada
    return;
  }

  printf("Digite o email: "); // Pede o email do contato
  if (scanf("%s", agenda[*ncontato].email) !=
      1) { // Verifica se a entrada foi válida
    printf("Erro ao ler o email\n");
    limparBuffer(); // Limpar o buffer de entrada
    return;
  }

  printf("Digite o telefone: "); // Pede o telefone do contato
  if (scanf("%s", agenda[*ncontato].tel) !=
      1) { // Verifica se a entrada foi válida
    printf("Erro ao ler o telefone\n");
    limparBuffer(); // Limpar o buffer de entrada
    return;
  }

  (*ncontato)++;
}

// Função para listar os contatos, exibindo os dados em um arquivo
void ListarContatos(
    Contato agenda[],
    int ncontato) { // Recebe um vetor de contatos e o número de contatos
  printf("--LISTA DE CONTATOS--\n\t");
  for (int i = 0; i < ncontato; i++) {
    printf("Nome: %s\n", agenda[i].nome);
    printf("Sobrenome: %s\n", agenda[i].sobrenome);
    printf("Email: %s\n", agenda[i].email);
    printf("Telefone: %s\n", agenda[i].tel);
    printf("\n\t");
  }
}
// Função para salvar os contatos em um arquivo binario
void SalvarContatos(Contato agenda[], int ncontato) {
  FILE *arquivo =
      fopen("arquivo.bin", "wb"); // Abre o arquivo em modo de escrita binária
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo\n");
    return;
  }
  fwrite(&ncontato, sizeof(int), 1,
         arquivo); // Escreve o número de contatos no arquivo
  fwrite(agenda, sizeof(Contato), ncontato,
         arquivo); // Escreve os contatos no arquivo
  printf("-----------------------------\n");
  printf("Contatos salvos com sucesso\n");
  fclose(arquivo); // Fecha o arquivo
}
// Função para carregar os contatos de um arquivo binario
void CarregarContatos(Contato agenda[], int *ncontato) {
  FILE *arquivo =
      fopen("arquivo.bin", "rb"); // Abre o arquivo em modo de leitura binária
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo\n");
    return;
  }

  size_t num_elements_read;

  num_elements_read = fread(ncontato, sizeof(int), 1,
                            arquivo); // Lê o número de contatos do arquivo
  if (num_elements_read != 1) {
    printf("Erro ao ler o número de contatos\n");
    fclose(arquivo); // Fecha o arquivo
    return;
  }

  num_elements_read = fread(agenda, sizeof(Contato), *ncontato, arquivo); //
  if (num_elements_read != *ncontato) {                                   //
    printf("Erro ao ler os contatos\n");
    fclose(arquivo);
    return;
  }

  fclose(arquivo);
}
// Função para deletar um contato pelo telefone
void DeletarContatos(Contato agenda[], int *ncontato, char *tel) {

  for (int i = 0; i < *ncontato; i++) { // Percorre o vetor de contatos
    if (strcmp(agenda[i].tel, tel) ==
        0) { // Compara o telefone do contato com o telefone fornecido
      for (int j = i; j < *ncontato - 1;
           j++) { // Desloca os contatos para preencher o espaço vazio
        agenda[j] = agenda[j + 1];
      }
      (*ncontato)--;
      printf("Contato deletado com sucesso\n");
      return;
    }
  }
  printf("Contato com telefone %s não encontrado\n", tel);
}