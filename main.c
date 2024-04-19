//     gcc *.c && ./a.out
//     git add nome
//     git commit -m "escreva"
//     git push -u origin main

#include <stdio.h>
#include "contatos.h"

int main() {
    Agenda agenda;
    inicializar(&agenda);

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
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
          printf("\nDigite o nome: ");
          scanf("%%d", nome);
          getchar();
          printf("Digite o sobrenome: ");
          scanf("%d", sobrenome);
          getchar();
          printf("Digite o email: ");
          scanf("%%d", gmail);
          getchar();
          printf("Digite o telefone: ");
          scanf("%d", telefone);
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
          scanf("%49[^\n]", telefone);
          getchar();
          if (deletarContato(&agenda, telefone)) {
              printf("Contato deletado\n");
          } else {
              printf("Contato nao existe ou ja foi deletado\n");
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
                      printf("");
                      break;
                  default:
                      printf("Opçãoo invalida\n");
              }
          } while (opcao != 0);

          return 0;
      }


      

      

     
                      