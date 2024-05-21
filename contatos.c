#include "contatos.h"
#include <stdio.h>
#include <string.h>
#include <regex.h>

void inicializarAgenda(Agenda *agenda) {
  agenda->quantidade = 0;
}

int adicionarContato(Agenda *agenda, const char *nome, const char *sobrenome, const char *email, const char *telefone) {
  if (agenda->quantidade >= MAX_CONTATOS) {
    printf("Erro, limite de contatos atingido.\n");
    return 0;
  }

  if (!validarEmail(email)) {
    printf("Email inválido. Por favor, insira um email válido.\n");
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
    printf("%d. Nome: %s %s\n   Email: %s\n   Telefone: %s\n", i + 1,
           agenda->contatos[i].nome, agenda->contatos[i].sobrenome,
           agenda->contatos[i].email,
           agenda->contatos[i].telefone);
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
    printf("Erro ao abrir o arquivo\n");
    return;
  }
  fwrite(agenda, sizeof(Agenda), 1, arquivo);
  fclose(arquivo);
}

void carregarAgenda(Agenda *agenda, const char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo\n");
    return;
  }

  int lidos = fread(agenda, sizeof(Agenda), 1, arquivo);
  fclose(arquivo);
}

int validarEmail(const char *email) {
    const char *regex = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";

    regex_t reg;
    if (regcomp(&reg, regex, REG_EXTENDED) != 0) {
        printf("Erro ao compilar a expressão regular\n");
        return 0;
    }

    int result = regexec(&reg, email, 0, NULL, 0);
    regfree(&reg);

    if (result == 0) {
        return 1;
    } else {
        return 0;
    }
}
