#include "contatos.h" // Include do arquivo de cabeçalho
#include <stdio.h>
#include <string.h>

// int de inicio com algumas variaveis
int main() {
  Contato agenda[MAX_CONTATOS];
  int ncontato = 0;
  int menu;
  char tel[MAX_CONTATOS];

  do {
    // Opções do menu de opções de 1 a 6
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
    // Menu principal do programa usando if , else if e else
    if (menu == 1) {
      CadastrarContato(agenda, &ncontato); // Chama a função CadastrarContato
    } else if (menu == 2) {
      ListarContatos(agenda, ncontato); // Chama a função ListarContatos
    } else if (menu == 3) {
      printf("Digite o telefone do contato a ser deletado:");
      if (scanf("%s", tel) != 1) {
        printf("Erro ao ler o telefone\n");
      }
      DeletarContatos(agenda, &ncontato, tel); // Chama a função DeletarContatos
    } else if (menu == 4) {
      SalvarContatos(agenda, ncontato); // Chama a função SalvarContatos
    } else if (menu == 5) {
      CarregarContatos(agenda, &ncontato); // Chama a função CarregarContatos
    } else if (menu == 6) {
      printf("Saindo...\n");
    } else {
      printf("Opção inválida. Tente novamente.\n");
    }

  } while (menu != 6); // Enquanto a opção for diferente de 6, o loop continua

  return 0;
}
