//        gcc *.c && ./a.out
//        git add nome
//        git commit -m "escreva"
//        git push -u origin main

//Bibliotecas
#include "contatos.h" 
#include <stdio.h>
#include <string.h> 
#include <regex.h> 

// Inicializa a agenda
void inicializarAgenda(Agenda *agenda) {
  agenda->quantidade = 0; // Define a quantidade de contatos como 0
}

// Funçao para validar o email 
int validarEmail(const char *email) {
    const char *regex = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
    regex_t reg; 
    if (regcomp(&reg, regex, REG_EXTENDED) != 0) { // Compilar
        return 0; // Retornarr 0 se houver erro na compilação
    }

    // Validar o email
    int result = regexec(&reg, email, 0, NULL, 0);
    regfree(&reg); // Libera a memória

    return result == 0; // Retorna 1 se o email for valido, caso nao seja retorna 0
}

// Função para verificar se o telefone ja existe
int telefoneExiste(const Agenda *agenda, const char *telefone) {
    // Loop para verificar cada contato 
    for (int i = 0; i < agenda->quantidade; i++) {
        if (strcmp(agenda->contatos[i].telefone, telefone) == 0) {
            return 1; // Retorna 1 se o telefone ja existe
        }
    }
    return 0; // Retorna 0 se o telefone nao existe
}
// Funçao para adicionar um contato na agenda
int adicionarContato(Agenda *agenda, const char *nome, const char *sobrenome, const char *email, const char *telefone) {
  // Verifica se a agenda esta cheia
  if (agenda->quantidade >= MAX_CONTATOS) {
    printf("Erro, limite de contatos foi atingido.\n");
    return 0; // Retorna 0 caso a agenda ja tenha atingido o limite
  }

  // Verifica se o email e valido
  if (!validarEmail(email)) {
    printf("Email inválido. Por favor, insira um email válido.\n");
    return 0; // Retorna 0 se o email for invalido
  }

  // Verifica se o telefone ja existe 
  if (telefoneExiste(agenda, telefone)) {
    printf("Erro, telefone já existe.\n");
    return 0; // Retorna 0 se o telefone ja existe
  }

  // Copia os dados do contato para a proxima posiçao na agenda
  strcpy(agenda->contatos[agenda->quantidade].nome, nome);
  strcpy(agenda->contatos[agenda->quantidade].sobrenome, sobrenome);
  strcpy(agenda->contatos[agenda->quantidade].email, email);
  strcpy(agenda->contatos[agenda->quantidade].telefone, telefone);

  // Incrementa a quantidade de contatos
  agenda->quantidade++;
  return 1; // Retorna 1 se o contato foi adicionado
}

// Funçao para listar os contatos da agenda
void listarContatos(const Agenda *agenda) {
  printf("Lista de Contatos:\n");
  printf("------------------\n");
  // Loop para imprimir os contatos
  for (int i = 0; i < agenda->quantidade; i++) {
    printf("%d. Nome: %s %s\n   Email: %s\n   Telefone: %s\n", i + 1,
           agenda->contatos[i].nome, agenda->contatos[i].sobrenome,
           agenda->contatos[i].email, agenda->contatos[i].telefone);
  }
}

// Funçao para deletar contato 
int deletarContato(Agenda *agenda, const char *telefone) {
  int encontrado = 0; // Variavel para verificar se o contato foi encontrado
  // Loop para verificar os contatos 
  for (int i = 0; i < agenda->quantidade; i++) {
    if (strcmp(agenda->contatos[i].telefone, telefone) == 0) {
      encontrado = 1; // Define como encontrado se o telefone for igual
      // Move todos os contatos depois de encontrar, uma posição para tras
      for (int j = i; j < agenda->quantidade - 1; j++) {
        agenda->contatos[j] = agenda->contatos[j + 1];
      }
      agenda->quantidade--; // Decrementa a quantidade de contatos
      break;
    }
  }
  return encontrado; // Retorna 1 se o contato foi encontrado e deletado caso nao seja retornar 0
}

// Funçao para salvar a agenda em um arquivo
void salvarAgenda(const Agenda *agenda, const char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "wb"); // Abre o arquivo para escrita binaria
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo\n");
    return; // Retorna se houver erro ao abrir
  }
  // Escreve os dados da agenda no arquivo
  fwrite(agenda, sizeof(Agenda), 1, arquivo);
  fclose(arquivo); // Fecha o arquivo
}

// Funçao para carregar a agenda de um arquivo
void carregarAgenda(Agenda *agenda, const char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "rb"); // Abre o arquivo para leitura binaria
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo\n");
    return; // Retorna se houver erro ao abrir o arquivo
  }

  // Le os dados da agenda do arquivo
  int lidos = fread(agenda, sizeof(Agenda), 1, arquivo);
  fclose(arquivo); // Fecha o arquivo
}