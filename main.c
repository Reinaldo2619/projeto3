//        gcc *.c && ./a.out
//        git add nome
//        git commit -m "escreva"
//        git push -u origin main

// Bibliotecas
#include <stdio.h> 
#include "contatos.h" 

int main() {
    Agenda agenda; // Declara uma variável do tipo Agenda
    inicializarAgenda(&agenda); // Inicializa a agenda

    int opcao; // Variavel para armazenar a opçao do menu
    char nome[50], sobrenome[50], gmail[50], telefone[50]; // Variaveis para armazenar os dados do contato que sera adicionado

    do {
        // Exibe o menu de opçoes
        printf("\nMenu:\n");
        printf("1-Adicionar contato\n");
        printf("2-Lista de contatos\n");
        printf("3-Excluir contato\n");
        printf("4-Salvar agenda\n");
        printf("5-Carregar agenda\n");
        printf("0-Sair\n");
        printf("Escolha uma opcao: ");

        // Lê a opçao do usuário
        if (scanf("%d", &opcao) != 1) {
            printf("Erro ao ler a opcao.\n");
            return 1;
        }

        // Verifica a opçao que foi escolhida
        switch (opcao) {
            case 1:
                // Adicionar contato
                printf("\nDigite o nome: ");
                if (scanf("%49s", nome) != 1) {
                    printf("Erro\n");
                    return 1;
                }
                getchar(); // Limpar o buffer

                printf("\nDigite o sobrenome: ");
                if (scanf("%49s", sobrenome) != 1) {
                    printf("Erro\n");
                    return 1;
                }
                getchar(); // Limpar o buffer

                printf("\nDigite o gmail: ");
                if (scanf("%49s", gmail) != 1) {
                    printf("Erro\n");
                    return 1;
                }
                getchar(); // Limpar o buffer

                printf("\nDigite o telefone: ");
                if (scanf("%49s", telefone) != 1) {
                    printf("Erro\n");
                    return 1;
                }
                getchar(); // Limpa o buffer

                // Adiciona o contato e verifica se ele foi adicionado
                if (adicionarContato(&agenda, nome, sobrenome, gmail, telefone)) {
                    printf("Contato adicionado\n");
                } else {
                    printf("Erro\n");
                }
                break;

            case 2:
                // Listar contatos
                listarContatos(&agenda);
                break;

            case 3:
                // Excluir contato
                printf("\nDigite o telefone do contato que deseja deletar: ");
                if (scanf("%49s", telefone) != 1) {
                    printf("Erro ao ler o telefone.\n");
                    return 1;
                }
                getchar(); // Limpar o buffer

                // Deleta o contato e verifica se foi deletado
                if (deletarContato(&agenda, telefone)) {
                    printf("Contato deletado\n");
                } else {
                    printf("Contato não existe ou já foi deletado\n");
                }
                break;

            case 4:
                // Salvar agenda em arquivo
                salvarAgenda(&agenda, "agenda.bin");
                printf("Agenda salva\n");
                break;

            case 5:
                // Carregar agenda de arquivo
                carregarAgenda(&agenda, "agenda.bin");
                printf("Agenda carregada\n");
                break;

            case 0:
                // Sair do programa
                printf("Encerrando...\n");
                break;

            default:
                // Opção inválida
                printf("Opção inválida\n");
        }
    } while (opcao != 0); // Exibe o menu ate o usuário escolher sair

    return 0; // Retorna 0 para indicar que o programa terminou 
}
