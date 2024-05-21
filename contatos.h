#ifndef CONTATOS_H
#define CONTATOS_H

#define MAX_CONTATOS 255 

typedef struct {
    char nome[50];
    char sobrenome[50];
    char email[50];
    char telefone[50];
} Contato;

typedef struct {
    Contato contatos[MAX_CONTATOS];
    int quantidade;
} Agenda;

void inicializarAgenda(Agenda *agenda);
int adicionarContato(Agenda *agenda, const char *nome, const char *sobrenome, const char *email, const char *telefone);
void listarContatos(const Agenda *agenda);
int deletarContato(Agenda *agenda, const char *telefone);
void salvarAgenda(const Agenda *agenda, const char *nomeArquivo);
void carregarAgenda(Agenda *agenda, const char *nomeArquivo);
int validarEmail(const char *email);

#endif
