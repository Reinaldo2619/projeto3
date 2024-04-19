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

  do{
    printf("\nMenu:\n");
    printf("1- Adicionar contato\n");
    printf("2- Lista de contatos\n");
    printf("3- Excluir contato\n");
    printf("4- Salvar agenda de contatos\n");
    printf("5- Carregar agenda de contatos\n");
    printf("0- Sair");
    printf("Escolha uma opção: ");
    scanf(%d, &opcao);

    switch(opcao){
  