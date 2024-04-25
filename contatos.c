//     gcc *.c && ./a.out
//     git add nome
//     git commit -m "escreva"
//     git push -u origin main

// Bibliotecas
#include <stdio.h>
#include <string.h>
#include "contatos.h"

// Define a funçao inicalizar agenda
void inicializarAgenda(Agenda *agenda) {
    agenda->quantidade = 0;// Colocando o ponteiro como 0
}

int adicionarContato(Agenda *agenda, const char *nome, const char *sobrenome, const char *email, const char *telefone) {//  Estrutura Agenda com as quatro strings (nome, sobrenome, gmail, telefone)
    if (agenda->quantidade >= MAX_CONTATOS) {// Verifica se a quantidade de contatos foi atingida. Se ela foi atingida ele mostra a menssagem "Erro, limite de contatos atingido""
        printf("Erro, limite de contatos atingido.\n");
        return 0;// Retorna 0 se a quantidade de contatos foi atingida
    }

  //  Copiam as strings para o proxima posiçao
    strcpy(agenda->contatos[agenda->quantidade].nome, nome);
    strcpy(agenda->contatos[agenda->quantidade].sobrenome, sobrenome);
    strcpy(agenda->contatos[agenda->quantidade].email, email);
    strcpy(agenda->contatos[agenda->quantidade].telefone, telefone);

    agenda->quantidade++;//  Incrementa a quantidade de contatos na agenda depopis de  adicionar um novo contato
    return 1; // Retorna 1 se o contato foi adicionado
}

  void listarContatos(const Agenda *agenda) {// Define a funçao listar contatos
      printf("Lista de Contatos:\n");// Mostra a menssagem "Lista de Contatos:"
      printf("------------------\n");// So pra enfeitar
      for (int i = 0; i < agenda->quantidade; i++) {// Loop para ver todos os contatos na lista
          printf("%d. Nome: %s %s\n   Email: %s\n   Telefone: %s\n", i + 1, agenda->contatos[i].nome,
                 agenda->contatos[i].sobrenome, agenda->contatos[i].email, agenda->contatos[i].telefone);//  Imprime na tela as informaçoes do contato (nome, sobrenome, email e telefone)
      }
  }

  int deletarContato(Agenda *agenda, const char *telefone) {// Define a funçao deletar contatos 
      int encontrado = 0;// Variavel encontrado 
      for (int i = 0; i < agenda->quantidade; i++) {//  Loop para ver todos os contatos na lista
          if (strcmp(agenda->contatos[i].telefone, telefone) == 0) {// Verifica se o telefone do contato é o mesmo 
              encontrado = 1; // Define a variavel como 1 para dizer que foi encontrado
              for (int j = i; j < agenda->quantidade - 1; j++) {
                  agenda->contatos[j] = agenda->contatos[j + 1];
              }// Move todos os contatos apos o contato encontrado uma posiçao para tras na lista
              agenda->quantidade--;
              break;
          }// Decrementa a quantidade de contatos na agenda depois de deletar um contato e encerra o loop
      }
      return encontrado;
  }// Indica se o contato foi encontrado e deletado

  void salvarAgenda(const Agenda *agenda, const char *nomeArquivo) {// Define a funçao salvar agenda
      FILE *arquivo = fopen(nomeArquivo, "wb");// Escrita binaria
      if (arquivo == NULL) {// Verifica se houve um erro ao abrir o arquivo
          printf("Erro ao abrir o arquivo\n");// Se dar  erro exibe a menssagem "Erro ao abrir o arquivo""
          return;
      }
      fwrite(agenda, sizeof(Agenda), 1, arquivo);// Escreve os dados da agenda para o arquivo
      fclose(arquivo);// fecha o arquivo
  }

  void carregarAgenda(Agenda *agenda, const char *nomeArquivo) {// Define a variavel carregar agenda
      FILE *arquivo = fopen(nomeArquivo, "rb");//  Abre arquivo para ler binario
      if (arquivo == NULL) {// Ve se teve erro pra abrir o arquivo
          printf("Erro ao abrir o arquivo\n");// Se tiver manda a menssagem "Erro ao abrir o arquivo""
          return;
      }
    
      fread(agenda, sizeof(Agenda), 1, arquivo);
      fclose(arquivo);// Fecha o arquivo depois de ler
  }
