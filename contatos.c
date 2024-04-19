//     gcc *.c && ./a.out
//     git add nome
//     git commit -m "escreva"
//     git push -u origin main

#include <stdio.h>
#include <string.h>
#include "contatos.h"

void inicializarAgenda(Agenda *agenda) {
    agenda->quantidade = 0;
}

int adicionarContato(Agenda *agenda, const char *nome, const char *sobrenome, const char *email, const char *telefone) {
    if (agenda->quantidade >= MAX_CONTATOS) {
        printf("Erro: Limite de contatos atingido.\n");
        return 0;
    }

    strcpy(agenda->contatos[agenda->quantidade].nome, nome);
    strcpy(agenda->contatos[agenda->quantidade].sobrenome, sobrenome);
    strcpy(agenda->contatos[agenda->quantidade].email, email);
    strcpy(agenda->contatos[agenda->quantidade].telefone, telefone);

    agenda->quantidade++;
    return 1;

  }

  void listarContatos(const Agenda *agenda) {
      printf("Lista de Contatos:\n");
      printf("------------------\n");
      for (int i = 0; i < agenda->quantidade; i++) {
          printf("%d. Nome: %s %s\n   Email: %s\n   Telefone: %s\n", i + 1, agenda->contatos[i].nome,
                 agenda->contatos[i].sobrenome, agenda->contatos[i].email, agenda->contatos[i].telefone);
      }
  }

  int deletarContato(Agenda *agenda, const char *telefone) {
      int encontrado = 0;
      for (int i = 0; i < agenda->quantidade; i++) {
          if (strcmp(agenda->contatos[i].telefone, telefone) == 0) {
              encontrado = 1;
              for (int j = i; j < agenda->quantidade - 1; j++) {
                  agenda->contatos[j] = agenda->contatos[j + 1];
              }
              agenda->quantidade--;
              break;
          }
      }
      return encontrado;
  }

  void salvarAgenda(const Agenda *agenda, const char *nomeArquivo) {
      FILE *arquivo = fopen(nomeArquivo, "wb");
      if (arquivo == NULL) {
          printf("Erro ao abrir o arquivo.\n");
          return;
      }
      fwrite(agenda, sizeof(Agenda), 1, arquivo);
      fclose(arquivo);
  }

  void carregarAgenda(Agenda *agenda, const char *nomeArquivo) {
      FILE *arquivo = fopen(nomeArquivo, "rb");
      if (arquivo == NULL) {
          printf("Erro ao abrir o arquivo.\n");
          return;
      }
      fread(agenda, sizeof(Agenda), 1, arquivo);
      fclose(arquivo);
  }

