#ifndef _CONTATOS_H // Verifica se o arquivo já foi incluído
#define _CONTATOS_H 
#define MAX_CONTATOS 255 
//define o tamanho máximo de contatos

// Estrutura para armazenar os dados de um contato
typedef struct {
  char nome[50];
  char sobrenome[50];
  char email[50];
  char tel[20];

} Contato;
// Função para cadastrar um contato
void CadastrarContato(Contato agenda[], int *ncontato);
// Função para listar os contatos
void ListarContatos(Contato agenda[], int ncontato);
// Função para salvar um contato
void SalvarContatos(Contato agenda[], int ncontato);
// Função para carregar os contatos
void CarregarContatos(Contato agenda[], int *ncontato);
// Função para deletar um contato
void DeletarContatos(Contato agenda[], int *ncontato, char *tel);

#endif