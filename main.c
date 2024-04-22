//     gcc *.c && ./a.out
//     git add nome
//     git commit -m "escreva"
//     git push -u origin main

//Bibliotecas padrao
#include <stdio.h>
#include "contatos.h"

//Funçao principal
int main() {
    Agenda agenda;//Variavel agenda
    inicializar(&agenda);

  int opcao;// Variaveis do menu de 0 a 6
  char nome[50], sobrenome[50], gmail[50], telefone[50];

  do {//loop enquanto a opcao for diferente de 0
    // Menu de com todas as opçoes
    printf("\nMenu:\n");
    printf("1-Adicionar contato\n");
    printf("2-Lista de contatos\n");
    printf("3-Excluir contato\n");
    printf("4-Salvar agenda\n");
    printf("5-Carregar agenda\n");
    printf("0-Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);// Pede que o usuario escolha uma das opçoes

    switch (opcao) {
      case 1:// SE opçao 1 for escolhida ele cria um novo contato pedindo as informaçoes ao ususario
          printf("\nDigite o nome: ");
          scanf("%d", nome);// pede o nome ao usuario
          getchar();
          printf("Digite o sobrenome: ");
          scanf("%d", sobrenome);// pede o sobrenome ao usuario
          getchar();
          printf("Digite o email: ");
          scanf("%%d", gmail);// pede o gmail ao usuario
          getchar();
          printf("Digite o telefone: ");
          scanf("%d", telefone);// pede o telefone ao usuario
          getchar();
          
        if (adicionarContato(&agenda, nome, sobrenome, gmail, telefone)) {// Chama a funçao adicionar contato e verifica se o contato foi adicionado ou nao
              printf("Contato adicionado\n");// Se o contato foi adicionado ele mostra a menssagem "Contato adicionado"
          } else {
              printf("Erro, contato não adicionado\n");// Se ele nao foi ele mostra a menssagem "Erro, contato não adicionado""
          }
          break;
      
      case 2:// Se a opçao 2 foi escolhida ele chama a funçao listar contatos e mostra os contatos da agenda
          listarContatos(&agenda);
          break;
     
      case 3: // Se a opçao 3 foi escolhida ele pede o telefone do contato que o usuario deseja excluir
          printf("\nDigite o telefone do contato que deseja deletar: ");
          scanf("%49[^\n]", telefone);// Pede o numero de telefone ao usuario
          getchar();
          if (deletarContato(&agenda, telefone)) {
              printf("Contato deletado\n");// Se o contato foi excluido ele mostra a menssagem "Contato deletado"
          } else {
              printf("Contato nao existe ou ja foi deletado\n");// Se ele nao foi ele mostra a menssagem "Contato nao existe ou ja foi deletado""
          }
          break;
     
      case 4: // Se a opaçao 4 foi escolhida chama a funçao salvar agenda
      salvarAgenda(&agenda, "agenda.bin");
      printf("Agenda salva\n");// Mostra a menssagem "Agenda salva"
      break;

      case 5: // Se a opaçao 5 foi escolhida chama a funçao carregar agenda
      carregarAgenda(&agenda, "agenda.bin");
      printf("Agenda carregada\n");// Mostra a menssagem "Agenda carregada"
      break;

      case 0:// Se a opçao 0 for escolhida ele sai do loop e encerra 
                      printf("");
                      break;
                  default:// Caso uma opçao diferente de 0 a 6 seja escolhida ele mostra a menssagem "Opçao invalida"
                      printf("Opçãoo invalida\n");
              }
          } while (opcao != 0);// Fecha o loop

          return 0;
      }


      

      

     
                      