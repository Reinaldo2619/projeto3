#include "contatos.h" // Inclui o arquivo de cabeçalho contatos.h
#include <regex.h>    // Inclui a biblioteca para trabalhar com expressões regulares
#include <stdio.h>    // Inclui a biblioteca padrão de entrada e saída
#include <string.h>   // Inclui a biblioteca para manipulação de strings

// Função para inicializar a agenda, configurando as quantidades de contatos pessoais e de trabalho para zero
void inicializarAgenda(Agenda *agenda) {
  agenda->quantidade_pessoais = 0;
  agenda->quantidade_trabalho = 0;
}

// Função para adicionar um contato pessoal à agenda
int adicionarContatoPessoal(Agenda *agenda, const char *nome,
                            const char *sobrenome, const char *email,
                            const char *telefone) {
  // Verifica se o limite de contatos pessoais foi atingido
  if (agenda->quantidade_pessoais >= MAX_CONTATOS) {
    printf("Erro, limite de contatos pessoais foi atingido.\n");
    return 0;
  }

  // Valida o formato do email usando uma expressão regular
  if (!validarEmail(email)) {
    printf("Email inválido. Por favor, insira um email válido.\n");
    return 0;
  }

  // Verifica se o telefone já existe na agenda
  if (telefoneExiste(agenda, telefone)) {
    printf("Erro, telefone já existe.\n");
    return 0;
  }

  // Cria um novo contato e o adiciona à lista de contatos pessoais
  Contato novo_contato;
  strcpy(novo_contato.nome, nome);
  strcpy(novo_contato.sobrenome, sobrenome);
  strcpy(novo_contato.email, email);
  strcpy(novo_contato.telefone, telefone);

  agenda->contatos_pessoais[agenda->quantidade_pessoais++] = novo_contato;

  return 1; // Retorna 1 se o contato foi adicionado com sucesso
  printf("Contato adicionado com sucesso.\n");
}

// Função para adicionar um contato de trabalho à agenda (semelhante à função adicionarContatoPessoal)
int adicionarContatoTrabalho(Agenda *agenda, const char *nome,
                             const char *sobrenome, const char *email,
                             const char *telefone) {
  // Verifica se o limite de contatos de trabalho foi atingido
  if (agenda->quantidade_trabalho >= MAX_CONTATOS) {
    printf("Erro, limite de contatos de trabalho foi atingido.\n");
    return 0;
  }

  // Valida o formato do email
  if (!validarEmail(email)) {
    printf("Email inválido. Por favor, insira um email válido.\n");
    return 0;
  }

  // Verifica se o telefone já existe na agenda
  if (telefoneExiste(agenda, telefone)) {
    printf("Erro, telefone já existe.\n");
    return 0;
  }

  // Cria um novo contato e o adiciona à lista de contatos de trabalho
  Contato novo_contato;
  strcpy(novo_contato.nome, nome);
  strcpy(novo_contato.sobrenome, sobrenome);
  strcpy(novo_contato.email, email);
  strcpy(novo_contato.telefone, telefone);

  agenda->contatos_trabalho[agenda->quantidade_trabalho++] = novo_contato;

  return 1;
  printf("Contato adicionado com sucesso.\n");
}

// Função para listar os contatos pessoais na agenda
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

// Função para listar os contatos de trabalho na agenda (semelhante à função listarContatosPessoais)
void listarContatosTrabalho(const Agenda *agenda) {
  printf("-----------------------------\n");
  printf("Lista de Contatos de Trabalho:\n");
  printf("------------------------------\n");
  for (int i = 0; i < agenda->quantidade_trabalho; i++) {
    printf("I-------------------------------------I\n");
    printf("%d. Nome: %s %s\n   Email: %s\n   Telefone: %s\n", i + 1,
           agenda->contatos_trabalho[i].nome,
           agenda->contatos_trabalho[i].sobrenome,
           agenda->contatos_trabalho[i].email,
           agenda->contatos_trabalho[i].telefone);
  }
  printf("I-------------------------------------I\n");
}

// Função para excluir um contato pessoal da agenda
int deletarContatoPessoal(Agenda *agenda, const char *telefone) {
  int encontrado = 0;
  for (int i = 0; i < agenda->quantidade_pessoais; i++) {
    if (strcmp(agenda->contatos_pessoais[i].telefone, telefone) == 0) {
      encontrado = 1;
      // Remove o contato da lista movendo os contatos subsequentes uma posição para trás
      for (int j = i; j < agenda->quantidade_pessoais - 1; j++) {
        agenda->contatos_pessoais[j] = agenda->contatos_pessoais[j + 1];
      }
      // Decrementa a quantidade de contatos pessoais na agenda
      agenda->quantidade_pessoais--;
      break;
    }
  }
  return encontrado; // Retorna 1 se o contato foi encontrado e excluído, 0 caso contrário
  printf("Contato deletado com sucesso.\n");
}

// Função para excluir um contato de trabalho da agenda (semelhante à função deletarContatoPessoal)
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
      printf("Contato de trabalho excluído com sucesso.\n");
    }
  }
  return encontrado;
  printf("Contato de trabalho excluído com sucesso.\n");
}

// Função para alterar um contato pessoal na agenda
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
      printf("Contato pessoal alterado com sucesso.\n");
    }
  }
  // Se o contato não for encontrado, retorna 0
  return 0;
}

// Função para alterar um contato de trabalho na agenda (semelhante à função alterarContatoPessoal)
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
      printf("Contato de trabalho alterado com sucesso.\n");
    }
  }
  // Se o contato não for encontrado, retorna 0
  return 0;
}

// Função para validar o formato do email usando uma expressão regular
int validarEmail(const char *email) {
  const char *regex = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
  regex_t reg;
  if (regcomp(&reg, regex, REG_EXTENDED) != 0) {
    return 0;
  }

  int result = regexec(&reg, email, 0, NULL, 0);
  regfree(&reg);

  return result == 0; // Retorna 1 se o email for válido, 0 caso contrário
}

// Função para verificar se um telefone já existe na agenda
int telefoneExiste(const Agenda *agenda, const char *telefone) {
  // Verifica se o telefone existe na lista de contatos pessoais
  for (int i = 0; i < agenda->quantidade_pessoais; i++) {
    if (strcmp(agenda->contatos_pessoais[i].telefone, telefone) == 0) {
      return 1; // Retorna 1 se o telefone existir na lista de contatos pessoais
    }
  }

  // Verifica se o telefone existe na lista de contatos de trabalho
  for (int i = 0; i < agenda->quantidade_trabalho; i++) {
    if (strcmp(agenda->contatos_trabalho[i].telefone, telefone) == 0) {
      return 1; // Retorna 1 se o telefone existir na lista de contatos de trabalho
    }
  }

  return 0; // Retorna 0 se o telefone não existir em nenhuma lista
}
