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
    Contato contatos_pessoais[MAX_CONTATOS];
    Contato contatos_trabalho[MAX_CONTATOS];
    int quantidade_pessoais;
    int quantidade_trabalho;
} Agenda;

// Função para inicializar a agenda
void inicializarAgenda(Agenda *agenda);
// Função para adicionar um contato na agenda
int adicionarContatoPessoal(Agenda *agenda, const char *nome, const char *sobrenome, const char *email, const char *telefone);
// Função para adicionar um contato na agenda
int adicionarContatoTrabalho(Agenda *agenda, const char *nome, const char *sobrenome, const char *email, const char *telefone);
// Função para listar os contatos da agenda
void listarContatosPessoais(const Agenda *agenda);
// Função para listar os contatos da agenda
void listarContatosTrabalho(const Agenda *agenda);
// Função para deletar um contato da agenda
int deletarContatoPessoal(Agenda *agenda, const char *telefone);
// Função para deletar um contato da agenda
int deletarContatoTrabalho(Agenda *agenda, const char *telefone);
// Função para salvar a agenda em um arquivo
int alterarContatoPessoal(Agenda *agenda, const char *telefone);
// Função para salvar a agenda em um arquivo
int alterarContatoTrabalho(Agenda *agenda, const char *telefone);
// Função para carregar a agenda de um arquivo
int validarEmail(const char *email);
// Função para carregar a agenda de um arquivo
int telefoneExiste(const Agenda *agenda, const char *telefone);
// Função para carregar a agenda de um arquivo

#endif

