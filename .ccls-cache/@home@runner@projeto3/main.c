#include "contatos.h"
#include <stdio.h>
#include <string.h>

int main() {
  Contato agenda[MAX_CONTATOS];
  int ncontato = 0;
  int menu;

  do {
    // Opções do menu
    printf("--- Menu Principal ---\n\n");
    printf("1 - Cadastrar contato\n");
    printf("2 - Listar contatos\n");
    printf("3 - Deletar contato\n");
    printf("4 - Salvar agenda\n");
    printf("5 - Carregar agenda\n");
    printf("6 - Sair\n\n");
    printf("Escolha uma opção: ");

    // Verificar a entrada
    if (scanf(" %d", &menu) != 1) {
      printf("Erro: entrada inválida.\n");

      // Limpar o buffer de entrada
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;

      continue; // Volta ao início do loop
    }

    if (menu == 1) {
      CadastrarContato(agenda, &ncontato);
    } else if (menu == 2) {
      ListarContatos(agenda, ncontato);
    } else if (menu == 3) {
      printf("Deletar contato\n");
    } else if (menu == 4) {
      printf("Salvar agenda\n");
    } else if (menu == 5) {
      printf("Carregar agenda\n");
    } else if (menu == 6) {
      printf("Saindo...\n");
    } else {
      printf("Opção inválida. Tente novamente.\n");
    }

  } while (menu != 6); // Enquanto a opção for diferente de 6, o loop continua

  return 0;
}
