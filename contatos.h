#ifndef CONTATOS_H
#define CONTATOS_H

#define MAX_CONTATOS 255 // Define o número máximo de contatos na agenda

// Estrutura para armazenar informações do contato
typedef struct {
  char nome[50];      // Nome do contato
  char sobrenome[50]; // Sobrenome do contato
  char email[50];     // Email do contato
  char telefone[50];  // Telefone do contato
} Contato;

// Estrutura para armazenar a agenda
typedef struct {
  Contato contatos[MAX_CONTATOS]; // Array
  int quantidade;                 // Quantidade de contatos
} Agenda;

// Declaração das funções
void inicializarAgenda(Agenda *agenda); // Inicializa a agenda
int adicionarContato(Agenda *agenda, const char *nome, const char *sobrenome,
                     const char *email,
                     const char *telefone); // Adiciona um contato na agenda
void listarContatos(const Agenda *agenda);  // Lista todos os contatos na agenda
int deletarContato(Agenda *agenda,
                   const char *telefone); // Deleta um contato da agenda
void salvarAgenda(const Agenda *agenda,
                  const char *nomeArquivo); // Salva a agenda em um arquivo
void carregarAgenda(Agenda *agenda,
                    const char *nomeArquivo); // Carrega a agenda de um arquivo
int validarEmail(const char *email);          // Valida o email
int telefoneExiste(
    const Agenda *agenda,
    const char *telefone); // Verifica se o telefone já existe na agenda

// Declaração da função para alterar dados do contato
int alterarContato(Agenda *agenda, const char *telefone);


#endif
