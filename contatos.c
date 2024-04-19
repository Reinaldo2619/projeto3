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
