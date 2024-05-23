#include "contatos.h"
#include <stdio.h> // Inclui a biblioteca padrão
#include <stdlib.h>

// Função para inicializar a agenda
int main() {
  // Declaração das agendas
  Agenda agenda_pessoais;
  Agenda agenda_trabalho;

  // Inicialização das agendas
  inicializarAgenda(&agenda_pessoais);
  inicializarAgenda(&agenda_trabalho);
  // Adiciona um contato na agenda
  int opcao;
  char nome[50], sobrenome[50], email[50], telefone[50];
  // Loop para exibir o menu e processar as opções
  do {
    printf("|---------------------------------|\n");
    printf("|--------------MENU---------------|\n");
    printf("|1 - Adicionar contato pessoal----|\n");
    printf("|2 - Adicionar contato de trabalho|\n");
    printf("|3 - Listar contatos pessoais-----|\n");
    printf("|4 - Listar contatos de trabalho--|\n");
    printf("|5 - Excluir contato pessoal------|\n");
    printf("|6 - Excluir contato de trabalho--|\n");
    printf("|7 - Alterar contato pessoal------|\n");
    printf("|8 - Alterar contato de trabalho--|\n");
    printf("|0 - Sair-------------------------|\n");
    printf("|---------------------------------|\n");
    printf("|--------Escolha uma opcao--------|\n");
    // Lê a opção escolhida pelo usuário
    if (scanf("%d", &opcao) != 1) {
      printf("Erro ao ler a opcao.\n");
      return 1;
    }
    // Processa a opção escolhida pelo usuário
    switch (opcao) {
    case 1:
      // Adiciona um contato pessoal
      printf("\nDigite o nome: ");
      if (scanf("%49s", nome) != 1) {
        printf("Erro\n");
        return 1;
      }
      // Lê o sobrenome do contato
      printf("\nDigite o sobrenome: ");
      if (scanf("%49s", sobrenome) != 1) {
        printf("Erro\n");
        return 1;
      }
      // Lê o email do contato
      printf("\nDigite o email: ");
      if (scanf("%49s", email) != 1) {
        printf("Erro\n");
        return 1;
      }
      // Lê o telefone do contato
      printf("\nDigite o telefone: ");
      if (scanf("%49s", telefone) != 1) {
        printf("Erro\n");
        return 1;
      }
      // Adiciona o contato na agenda pessoal
      adicionarContatoPessoal(&agenda_pessoais, nome, sobrenome, email,
                              telefone);
      break;
    // Adiciona um contato de trabalho
    case 2:
      printf("\nDigite o nome: ");
      if (scanf("%49s", nome) != 1) {
        printf("Erro\n");
        return 1;
      }
      // Lê o sobrenome do contato
      printf("\nDigite o sobrenome: ");
      if (scanf("%49s", sobrenome) != 1) {
        printf("Erro\n");
        return 1;
      }
      // Lê o email do contato
      printf("\nDigite o email: ");
      if (scanf("%49s", email) != 1) {
        printf("Erro\n");
        return 1;
      }
      // Lê o telefone do contato
      printf("\nDigite o telefone: ");
      if (scanf("%49s", telefone) != 1) {
        printf("Erro\n");
        return 1;
      }
      // Adiciona o contato na agenda de trabalho
      adicionarContatoTrabalho(&agenda_trabalho, nome, sobrenome, email,
                               telefone);
      break;
    // Lista os contatos pessoais
    case 3:
      listarContatosPessoais(&agenda_pessoais);
      break;
    // Lista os contatos de trabalho
    case 4:
      listarContatosTrabalho(&agenda_trabalho);
      break;
    // Exclui um contato pessoal
    case 5:
      printf("\nDigite o telefone do contato que deseja excluir: ");
      if (scanf("%49s", telefone) != 1) {
        printf("Erro\n");
        return 1;
      }

      deletarContatoPessoal(&agenda_pessoais, telefone);
      break;
    // Exclui um contato de trabalho
    case 6:
      printf("\nDigite o telefone do contato que deseja excluir: ");
      if (scanf("%49s", telefone) != 1) {
        printf("Erro\n");
        return 1;
      }

      deletarContatoTrabalho(&agenda_trabalho, telefone);
      break;
    // Altera um contato pessoal
    case 7:
      printf("\nDigite o telefone do contato que deseja alterar: ");
      if (scanf("%49s", telefone) != 1) {
        printf("Erro\n");
        return 1;
      }

      alterarContatoPessoal(&agenda_pessoais, telefone);
      break;
    // Altera um contato de trabalho
    case 8:
      printf("\nDigite o telefone do contato que deseja alterar: ");
      if (scanf("%49s", telefone) != 1) {
        printf("Erro\n");
        return 1;
      }

      alterarContatoTrabalho(&agenda_trabalho, telefone);
      break;
    // Sai do programa
    case 0:
      printf("Encerrando...\n");
      break;

    default:
      printf("Opção inválida\n");
    }
  } while (opcao != 0);

  return 0;
}
