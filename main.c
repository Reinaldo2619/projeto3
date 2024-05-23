#include <stdio.h>
#include <stdlib.h>
#include "contatos.h"

int main() {
    // Declaração das agendas
    Agenda agenda_pessoais;
    Agenda agenda_trabalho;

    // Inicialização das agendas
    inicializarAgenda(&agenda_pessoais);
    inicializarAgenda(&agenda_trabalho);

    int opcao;
    char nome[50], sobrenome[50], email[50], telefone[50];

    do {
        printf("\nMenu:\n");
        printf("1- Adicionar contato pessoal\n");
        printf("2- Adicionar contato de trabalho\n");
        printf("3- Listar contatos pessoais\n");
        printf("4- Listar contatos de trabalho\n");
        printf("5- Excluir contato pessoal\n");
        printf("6- Excluir contato de trabalho\n");
        printf("7- Alterar contato pessoal\n");
        printf("8- Alterar contato de trabalho\n");
        printf("0- Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Erro ao ler a opcao.\n");
            return 1;
        }

        switch (opcao) {
            case 1:
                printf("\nDigite o nome: ");
                if (scanf("%49s", nome) != 1) {
                    printf("Erro\n");
                    return 1;
                }

                printf("\nDigite o sobrenome: ");
                if (scanf("%49s", sobrenome) != 1) {
                    printf("Erro\n");
                    return 1;
                }

                printf("\nDigite o email: ");
                if (scanf("%49s", email) != 1) {
                    printf("Erro\n");
                    return 1;
                }

                printf("\nDigite o telefone: ");
                if (scanf("%49s", telefone) != 1) {
                    printf("Erro\n");
                    return 1;
                }

                adicionarContatoPessoal(&agenda_pessoais, nome, sobrenome, email, telefone);
                break;

            case 2:
                printf("\nDigite o nome: ");
                if (scanf("%49s", nome) != 1) {
                    printf("Erro\n");
                    return 1;
                }

                printf("\nDigite o sobrenome: ");
                if (scanf("%49s", sobrenome) != 1) {
                    printf("Erro\n");
                    return 1;
                }

                printf("\nDigite o email: ");
                if (scanf("%49s", email) != 1) {
                    printf("Erro\n");
                    return 1;
                }

                printf("\nDigite o telefone: ");
                if (scanf("%49s", telefone) != 1) {
                    printf("Erro\n");
                    return 1;
                }

                adicionarContatoTrabalho(&agenda_trabalho, nome, sobrenome, email, telefone);
                break;

            case 3:
                listarContatosPessoais(&agenda_pessoais);
                break;

            case 4:
                listarContatosTrabalho(&agenda_trabalho);
                break;

            case 5:
                printf("\nDigite o telefone do contato que deseja excluir: ");
                if (scanf("%49s", telefone) != 1) {
                    printf("Erro\n");
                    return 1;
                }

                deletarContatoPessoal(&agenda_pessoais, telefone);
                break;

            case 6:
                printf("\nDigite o telefone do contato que deseja excluir: ");
                if (scanf("%49s", telefone) != 1) {
                    printf("Erro\n");
                    return 1;
                }

                deletarContatoTrabalho(&agenda_trabalho, telefone);
                break;

            case 7:
                printf("\nDigite o telefone do contato que deseja alterar: ");
                if (scanf("%49s", telefone) != 1) {
                    printf("Erro\n");
                    return 1;
                }

                alterarContatoPessoal(&agenda_pessoais, telefone);
                break;

            case 8:
                printf("\nDigite o telefone do contato que deseja alterar: ");
                if (scanf("%49s", telefone) != 1) {
                    printf("Erro\n");
                    return 1;
                }

                alterarContatoTrabalho(&agenda_trabalho, telefone);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida\n");
        }
    } while (opcao != 0);

    return 0;
}
