//     gcc *.c && ./a.out
//     git add nome
//     git commit -m "escreva"
//     git push -u origin main

#ifndef CONTATOS_H
#define CONTATOS_H

// Define uma constante MAX_CONTATOS para indicar o maximo de contatos que podem ser armazenados
#define MAX_CONTATOS 255 

// Define a estrutura contato que guarda informaçoes sobre um contato (nome, sobrenome, gmail, telefone)
typedef struct {
    char nome[50];
    char sobrenome[50];
    char email[50];
    char telefone[50];
} Contato;

// Define uma estrutura agenda que contém um array
typedef struct {
    Contato contatos[MAX_CONTATOS];
    int quantidade;
} Agenda;

// Inicializar agenda, adicionar contato, lista de contatos, excluir contato, salvar agenda e carregar a agenda (todos estao definidos em contatos.c)
void inicializarAgenda(Agenda *agenda);
int adicionarContato(Agenda *agenda, const char *nome, const char *sobrenome, const char *email, const char *telefone);
void listarContatos(const Agenda *agenda);
int deletarContato(Agenda *agenda, const char *telefone);
void salvarAgenda(const Agenda *agenda, const char *nomeArquivo);
void carregarAgenda(Agenda *agenda, const char *nomeArquivo);

#endif 