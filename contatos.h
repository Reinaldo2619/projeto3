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

void inicializaragenda(Agenda *agenda);
int adicionarcontato(Agenda *agenda, const char *nome, const char *sobrenome, const char *email, const char *telefone);
void listarcontatos(const Agenda *agenda);
int deletarcontato(Agenda *agenda, const char *telefone);
void salvaragenda(const Agenda *agenda, const char *nomeArquivo);
void carregaragenda(Agenda *agenda, const char *nomeArquivo);
int validaremail(const char *email);
int telefoneexiste(const Agenda *agenda, const char *telefone);

#endif
