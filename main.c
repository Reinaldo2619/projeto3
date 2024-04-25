//     gcc *.c && ./a.out
//     git add nome
//     git commit -m "escreva"
//     git push -u origin main

#include <stdio.h>
#include "contatos.h"

int main() {
    Agenda agenda;
    inicializarAgenda(&agenda);

    int opcao;
    char nome[50], sobrenome[50], gmail[50], telefone[50];

    do {
        printf("\nMenu:\n");
        printf("1-Adicionar contato\n");
        printf("2-Lista de contatos\n");
        printf("3-Excluir contato\n");
        printf("4-Salvar agenda\n");
        printf("5-Carregar agenda\n");
        printf("0-Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Erro ao ler a opcao.\n");
            return 1;
        }

        switch (opcao) {
            case 1:
                printf("\nDigite o nome: ");
                if (scanf("%49s", nome) != 1) {
                    printf("Erro ao ler o nome.\n");
                    return 1;
                }
                getchar();

                printf("\nDigite o sobrenome: ");
                if (scanf("%49s", sobrenome) != 1) {
                    printf("Erro ao ler o sobrenome.\n");
                    return 1;
                }
                getchar();

                printf("\nDigite o gmail: ");
                if (scanf("%49s", gmail) != 1) {
                    printf("Erro ao ler o gmail.\n");
                    return 1;
                }
                getchar();

                printf("\nDigite o telefone: ");
                if (scanf("%49s", telefone) != 1) {
                    printf("Erro ao ler o telefone.\n");
                    return 1;
                }
                getchar();

                if (adicionarContato(&agenda, nome, sobrenome, gmail, telefone)) {
                    printf("Contato adicionado\n");
                } else {
                    printf("Erro, contato não adicionado\n");
                }
                break;

            case 2:
                listarContatos(&agenda);
                break;

            case 3:
                printf("\nDigite o telefone do contato que deseja deletar: ");
                if (scanf("%49[^\n]", telefone) != 1) {
                    printf("Erro ao ler o telefone.\n");
                    return 1;
                }
                getchar();
                if (deletarContato(&agenda, telefone)) {
                    printf("Contato deletado\n");
                } else {
                    printf("Contato não existe ou já foi deletado\n");
                }
                break;

            case 4:
                salvarAgenda(&agenda, "agenda.bin");
                printf("Agenda salva\n");
                break;

            case 5:
                carregarAgenda(&agenda, "agenda.bin");
                printf("Agenda carregada\n");
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
