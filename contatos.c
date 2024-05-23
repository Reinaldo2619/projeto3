#include "contatos.h"
#include <regex.h>
#include <stdio.h>
#include <string.h>

void inicializarAgenda(Agenda *agenda) {
  agenda->quantidade_pessoais = 0;
  agenda->quantidade_trabalho = 0;
}

int adicionarContatoPessoal(Agenda *agenda, const char *nome,
                            const char *sobrenome, const char *email,
                            const char *telefone) {
  if (agenda->quantidade_pessoais >= MAX_CONTATOS) {
    printf("Erro, limite de contatos pessoais foi atingido.\n");
    return 0;
  }

  if (!validarEmail(email)) {
    printf("Email inválido. Por favor, insira um email válido.\n");
    return 0;
  }

  if (telefoneExiste(agenda, telefone)) {
    printf("Erro, telefone já existe.\n");
    return 0;
  }

  Contato novo_contato;
  strcpy(novo_contato.nome, nome);
  strcpy(novo_contato.sobrenome, sobrenome);
  strcpy(novo_contato.email, email);
  strcpy(novo_contato.telefone, telefone);

  agenda->contatos_pessoais[agenda->quantidade_pessoais++] = novo_contato;

  return 1;
}

int adicionarContatoTrabalho(Agenda *agenda, const char *nome,
                             const char *sobrenome, const char *email,
                             const char *telefone) {
  if (agenda->quantidade_trabalho >= MAX_CONTATOS) {
    printf("Erro, limite de contatos de trabalho foi atingido.\n");
    return 0;
  }

  if (!validarEmail(email)) {
    printf("Email inválido. Por favor, insira um email válido.\n");
    return 0;
  }

  if (telefoneExiste(agenda, telefone)) {
    printf("Erro, telefone já existe.\n");
    return 0;
  }

  Contato novo_contato;
  strcpy(novo_contato.nome, nome);
  strcpy(novo_contato.sobrenome, sobrenome);
  strcpy(novo_contato.email, email);
  strcpy(novo_contato.telefone, telefone);

  agenda->contatos_trabalho[agenda->quantidade_trabalho++] = novo_contato;

  return 1;
}

void listarContatosPessoais(const Agenda *agenda) {
  printf("Lista de Contatos Pessoais:\n");
  printf("---------------------------\n");
  for (int i = 0; i < agenda->quantidade_pessoais; i++) {
    printf("%d. Nome: %s %s\n   Email: %s\n   Telefone: %s\n", i + 1,
           agenda->contatos_pessoais[i].nome,
           agenda->contatos_pessoais[i].sobrenome,
           agenda->contatos_pessoais[i].email,
           agenda->contatos_pessoais[i].telefone);
  }
}

void listarContatosTrabalho(const Agenda *agenda) {
  printf("Lista de Contatos de Trabalho:\n");
  printf("------------------------------\n");
  for (int i = 0; i < agenda->quantidade_trabalho; i++) {
    printf("%d. Nome: %s %s\n   Email: %s\n   Telefone: %s\n", i + 1,
           agenda->contatos_trabalho[i].nome,
           agenda->contatos_trabalho[i].sobrenome,
           agenda->contatos_trabalho[i].email,
           agenda->contatos_trabalho[i].telefone);
  }
}

int deletarContatoPessoal(Agenda *agenda, const char *telefone) {
  int encontrado = 0;
  for (int i = 0; i < agenda->quantidade_pessoais; i++) {
    if (strcmp(agenda->contatos_pessoais[i].telefone, telefone) == 0) {
      encontrado = 1;
      for (int j = i; j < agenda->quantidade_pessoais - 1; j++) {
        agenda->contatos_pessoais[j] = agenda->contatos_pessoais[j + 1];
      }
      agenda->quantidade_pessoais--;
      break;
    }
  }
  return encontrado;
}

int deletarContatoTrabalho(Agenda *agenda, const char *telefone) {
  int encontrado = 0;
  for (int i = 0; i < agenda->quantidade_trabalho; i++) {
    if (strcmp(agenda->contatos_trabalho[i].telefone, telefone) == 0) {
      encontrado = 1;
      for (int j = i; j < agenda->quantidade_trabalho - 1; j++) {
        agenda->contatos_trabalho[j] = agenda->contatos_trabalho[j + 1];
      }
      agenda->quantidade_trabalho--;
      break;
    }
  }
  return encontrado;
}

int alterarContatoPessoal(Agenda *agenda, const char *telefone) {
  for (int i = 0; i < agenda->quantidade_pessoais; i++) {
    if (strcmp(agenda->contatos_pessoais[i].telefone, telefone) == 0) {
      // Encontrou o contato
      char novo_nome[50], novo_sobrenome[50], novo_email[50], novo_telefone[50];

      // Solicita os novos dados
      printf("Digite o novo nome: ");
      if (scanf("%s", novo_nome) != 1) {
        printf("ERRO");
        return 1;
      }
      printf("Digite o novo sobrenome: ");
      if (scanf("%s", novo_sobrenome) != 1) {
        printf("ERRO");
        return 1;
      }
      printf("Digite o novo email: ");
      if (scanf("%s", novo_email) != 1) {
        printf("ERRO");
        return 1;
      }
      printf("Digite o novo telefone: ");
      if (scanf("%s", novo_telefone) != 1) {
        printf("ERRO");
        return 1;
      }

      // Atualiza os dados do contato
      strcpy(agenda->contatos_pessoais[i].nome, novo_nome);
      strcpy(agenda->contatos_pessoais[i].sobrenome, novo_sobrenome);
      strcpy(agenda->contatos_pessoais[i].email, novo_email);
      strcpy(agenda->contatos_pessoais[i].telefone, novo_telefone);

      return 1; // Retorna 1 indicando que o contato foi alterado
    }
  }
  // Se o contato não for encontrado, retorna 0
  return 0;
}
int alterarContatoTrabalho(Agenda *agenda, const char *telefone) {
  for (int i = 0; i < agenda->quantidade_trabalho; i++) {
    if (strcmp(agenda->contatos_trabalho[i].telefone, telefone) == 0) {
      // Encontrou o contato
      char novo_nome[50], novo_sobrenome[50], novo_email[50], novo_telefone[50];

      // Solicita os novos dados
      printf("Digite o novo nome: ");
      if (scanf("%s", novo_nome) != 1) {
        printf("ERRO");
        return 1;
      }
      printf("Digite o novo sobrenome: ");
      if (scanf("%s", novo_sobrenome) != 1) {
        printf("ERRO");
        return 1;
      }
      printf("Digite o novo email: ");
      if (scanf("%s", novo_email) != 1) {
        printf("ERRO");
        return 1;
      }
      printf("Digite o novo telefone: ");
      if (scanf("%s", novo_telefone) != 1) {
        printf("ERRO");
        return 1;
      }

      // Atualiza os dados do contato
      strcpy(agenda->contatos_trabalho[i].nome, novo_nome);
      strcpy(agenda->contatos_trabalho[i].sobrenome, novo_sobrenome);
      strcpy(agenda->contatos_trabalho[i].email, novo_email);
      strcpy(agenda->contatos_trabalho[i].telefone, novo_telefone);

      return 1; // Retorna 1 indicando que o contato foi alterado
    }
  }
  // Se o contato não for encontrado, retorna 0
  return 0;
}

int validarEmail(const char *email) {
  const char *regex = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
  regex_t reg;
  if (regcomp(&reg, regex, REG_EXTENDED) != 0) {
    return 0;
  }

  int result = regexec(&reg, email, 0, NULL, 0);
  regfree(&reg);

  return result == 0;
}

int telefoneExiste(const Agenda *agenda, const char *telefone) {
  for (int i = 0; i < agenda->quantidade_pessoais; i++) {
    if (strcmp(agenda->contatos_pessoais[i].telefone, telefone) == 0) {
      return 1;
    }
  }
  for (int i = 0; i < agenda->quantidade_trabalho; i++) {
    if (strcmp(agenda->contatos_trabalho[i].telefone, telefone) == 0) {
      return 1;
    }
  }
  return 0;
}
