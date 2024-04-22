#include <stdio.h>
#include "contatos.h"
#include <string>

int main(){
  Contato contatos[MAX_CONTATOS];
  int total_contatos = 0;
  //variavél de controle do menu
  int opcao;

  do{
    //opções do menu 
    printf(" --- Menu Principal ---\n");
    printf("\n");
    printf("---- ESCOLHA UMA OPÇÃO ----\n");
    printf("\n");
    printf("1 - Cadastrar contato\n\t");
    printf("2 - Listar contatos\n\t");
    printf("3 - Deletar contato\n\t");
    printf("4 - Salvar agenda\n\t");
    printf("5 - Carregar agenda\n\t");
    printf("6 - Sair\n\t");
    scanf("%d", &opcao);

    //executa a opção escolhida
    switch(opcao){
      case 1:
      printf("Você escolheu a opção 1 - Cadastrar um novo contato\n");
      case 2:
      printf("Você escolheu a opção 2 - Listar contatos\n");
      break;
      case 3:
      printf("Você escolheu a opção 3 - Deletar contato\n");
      break;
      case 4:
      printf("Você escolheu a opção 4 - Salvar agenda\n");
      break;
      case 5:
      printf("Você escolheu a opção 5 - Carregar agenda\n");
      break;
      case 6:
      printf("Saindo do programa\n");
      break;
      default:
      printf("Digite uma opção válida\n");
    }
  }while(opcao != 6); //enquanto a opção for diferente de 6, o programa continua rodando
} 



