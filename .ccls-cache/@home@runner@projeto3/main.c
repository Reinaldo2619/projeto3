// gcc *.c && ./a.out
// git add nome
// git commit -m "escreva"
// git push -u origin main

// Bibliotecas
#include "contatos.h"
#include <stdio.h>

int main() {
  Agenda agenda;              // Declara uma variável do tipo Agenda
  inicializarAgenda(&agenda); // Inicializa a agenda

  int opcao; // Variável para armazenar a opção do menu
  char nome[50], sobrenome[50], email[50],
      telefone[50]; // Variáveis para armazenar os dados do contato que será
                    // adicionado

  do {
    // Exibe o menu de opções
    printf("\nMenu:\n");
    printf("1 - Adicionar contato\n");
    printf("2 - Lista de contatos\n");
    printf("3 - Excluir contato\n");
    printf("4 - Salvar agenda\n");
    printf("5 - Carregar agenda\n");
    printf("6 - Alterar contato\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");

    // Lê a opção do usuário
    if (scanf("%d", &opcao) != 1) {
      printf("Erro ao ler a opção.\n");
      while (getchar() != '\n')
        ; // Limpa o buffer de entrada
      continue;
    }

    // Verifica a opção que foi escolhida
    switch (opcao) {
    case 1:
      // Adicionar contato
      printf("\nDigite o nome: ");
      if (scanf("%49s", nome) != 1) {
        printf("Erro ao ler o nome.\n");
        while (getchar() != '\n')
          ; // Limpa o buffer de entrada
        break;
      }

      printf("\nDigite o sobrenome: ");
      if (scanf("%49s", sobrenome) != 1) {
        printf("Erro ao ler o sobrenome.\n");
        while (getchar() != '\n')
          ; // Limpa o buffer de entrada
        break;
      }

      printf("\nDigite o email: ");
      if (scanf("%49s", email) != 1) {
        printf("Erro ao ler o email.\n");
        while (getchar() != '\n')
          ; // Limpa o buffer de entrada
        break;
      }

      printf("\nDigite o telefone: ");
      if (scanf("%49s", telefone) != 1) {
        printf("Erro ao ler o telefone.\n");
        while (getchar() != '\n')
          ; // Limpa o buffer de entrada
        break;
      }

      // Adiciona o contato e verifica se ele foi adicionado
      if (adicionarContato(&agenda, nome, sobrenome, email, telefone)) {
        printf("Contato adicionado.\n");
      } else {
        printf("Erro ao adicionar o contato.\n");
      }
      break;

    case 2:
      // Listar contatos
      listarContatos(&agenda);
      break;

    case 3:
      // Excluir contato
      printf("\nDigite o telefone do contato que deseja deletar: ");
      if (scanf("%49s", telefone) != 1) {
        printf("Erro ao ler o telefone.\n");
        while (getchar() != '\n')
          ; // Limpa o buffer de entrada
        break;
      }

      // Deleta o contato e verifica se foi deletado
      if (deletarContato(&agenda, telefone)) {
        printf("Contato deletado.\n");
      } else {
        printf("Contato não existe ou já foi deletado.\n");
      }
      break;

    case 4:
      // Salvar agenda em arquivo
      salvarAgenda(&agenda, "agenda.bin");
      printf("Agenda salva.\n");
      break;

    case 5:
      // Carregar agenda de arquivo
      carregarAgenda(&agenda, "agenda.bin");
      printf("Agenda carregada.\n");
      break;

    case 6:
      // Alterar dados do contato
      printf("\nDigite o telefone do contato que deseja alterar: ");
      if (scanf("%49s", telefone) != 1) {
        printf("Erro ao ler o telefone.\n");
        break;
      }
      getchar(); // Limpa o buffer
      if (alterarContato(&agenda, telefone)) {
        printf("Contato alterado com sucesso.\n");
      } else {
        printf("Erro ao alterar o contato.\n");
      }
      break;

    case 0:
      // Sair do programa
      printf("Encerrando...\n");
      break;

    default:
      // Opção inválida
      printf("Opção inválida.\n");
    }
  } while (opcao != 0); // Exibe o menu até o usuário escolher sair

  return 0; // Retorna 0 para indicar que o programa terminou
}
