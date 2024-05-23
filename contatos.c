#include "contatos.h"
#include <stdio.h>
#include <string.h>
#include <regex.h>

// Inicializa a agenda
void inicializarAgenda(Agenda *agenda) {
    agenda->quantidade = 0; // Define a quantidade de contatos como 0
}

// Função para validar o email 
int validarEmail(const char *email) {
    const char *regex = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
    regex_t reg; 
    if (regcomp(&reg, regex, REG_EXTENDED) != 0) { // Compilar
        return 0; // Retorna 0 se houver erro na compilação
    }

    // Validar o email
    int result = regexec(&reg, email, 0, NULL, 0);
    regfree(&reg); // Libera a memória

    return result == 0; // Retorna 1 se o email for válido, caso não seja retorna 0
}

// Função para verificar se o telefone já existe
int telefoneExiste(const Agenda *agenda, const char *telefone) {
    // Loop para verificar cada contato 
    for (int i = 0; i < agenda->quantidade; i++) {
        if (strcmp(agenda->contatos[i].telefone, telefone) == 0) {
            return 1; // Retorna 1 se o telefone já existe
        }
    }
    return 0; // Retorna 0 se o telefone não existe
}

// Função para adicionar um contato na agenda
int adicionarContato(Agenda *agenda, const char *nome, const char *sobrenome, const char *email, const char *telefone) {
    // Verifica se a agenda está cheia
    if (agenda->quantidade >= MAX_CONTATOS) {
        printf("Erro, limite de contatos foi atingido.\n");
        return 0; // Retorna 0 caso a agenda já tenha atingido o limite
    }

    // Verifica se o email é válido
    if (!validarEmail(email)) {
        printf("Email inválido. Por favor, insira um email válido.\n");
        return 0; // Retorna 0 se o email for inválido
    }

    // Verifica se o telefone já existe 
    if (telefoneExiste(agenda, telefone)) {
        printf("Erro, telefone já existe.\n");
        return 0; // Retorna 0 se o telefone já existe
    }

    // Copia os dados do contato para a próxima posição na agenda
    strcpy(agenda->contatos[agenda->quantidade].nome, nome);
    strcpy(agenda->contatos[agenda->quantidade].sobrenome, sobrenome);
    strcpy(agenda->contatos[agenda->quantidade].email, email);
    strcpy(agenda->contatos[agenda->quantidade].telefone, telefone);

    // Incrementa a quantidade de contatos
    agenda->quantidade++;
    return 1; // Retorna 1 se o contato foi adicionado
}

// Função para listar os contatos da agenda
void listarContatos(const Agenda *agenda) {
    printf("Lista de Contatos:\n");
    printf("------------------\n");
    // Loop para imprimir os contatos
    for (int i = 0; i < agenda->quantidade; i++) {
        printf("%d. Nome: %s %s\n   Email: %s\n   Telefone: %s\n", i + 1,
               agenda->contatos[i].nome, agenda->contatos[i].sobrenome,
               agenda->contatos[i].email, agenda->contatos[i].telefone);
    }
}

// Função para deletar contato 
int deletarContato(Agenda *agenda, const char *telefone) {
    int encontrado = 0; // Variável para verificar se o contato foi encontrado
    // Loop para verificar os contatos 
    for (int i = 0; i < agenda->quantidade; i++) {
        if (strcmp(agenda->contatos[i].telefone, telefone) == 0) {
            encontrado = 1; // Define como encontrado se o telefone for igual
            // Move todos os contatos depois de encontrar, uma posição para trás
            for (int j = i; j < agenda->quantidade - 1; j++) {
                agenda->contatos[j] = agenda->contatos[j + 1];
            }
            agenda->quantidade--; // Decrementa a quantidade de contatos
            break;
        }
    }
    return encontrado; // Retorna 1 se o contato foi encontrado e deletado, caso não seja retorna 0
}

// Função para salvar a agenda em um arquivo
void salvarAgenda(const Agenda *agenda, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb"); // Abre o arquivo para escrita binária
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return; // Retorna se houver erro ao abrir
    }
    // Escreve os dados da agenda no arquivo
    fwrite(agenda, sizeof(Agenda), 1, arquivo);
    fclose(arquivo); // Fecha o arquivo
}

// Função para carregar a agenda de um arquivo
void carregarAgenda(Agenda *agenda, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb"); // Abre o arquivo para leitura binária
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return; // Retorna se houver erro ao abrir o arquivo
    }

    // Lê os dados da agenda do arquivo
    if(fread(agenda, sizeof(Agenda), 1, arquivo) != 1){
        printf("Erro ao ler os dados da agenda\n");
        
    }
    fclose(arquivo); // Fecha o arquivo
}
// Função para alterar dados do contato
int alterarContato(Agenda *agenda, const char *telefone) {
    // Verifica se o telefone existe na agenda
    int encontrado = 0;
    for (int i = 0; i < agenda->quantidade; i++) {
        if (strcmp(agenda->contatos[i].telefone, telefone) == 0) {
            encontrado = 1;
            // Solicita os novos dados do contato
            printf("Digite o novo nome: ");
            if (scanf("%49s", agenda->contatos[i].nome) != 1) {
                printf("Erro ao ler o nome.\n");
                return 0;
            }
            printf("Digite o novo sobrenome: ");
            if (scanf("%49s", agenda->contatos[i].sobrenome) != 1) {
                printf("Erro ao ler o sobrenome.\n");
                return 0;
            }
            printf("Digite o novo email: ");
            if (scanf("%49s", agenda->contatos[i].email) != 1) {
                printf("Erro ao ler o email.\n");
                return 0;
            }
            printf("Digite o novo telefone: ");
            if (scanf("%49s", agenda->contatos[i].telefone) != 1) {
                printf("Erro ao ler o telefone.\n");
                return 0;
            }
            printf("Contato alterado com sucesso.\n");
            return 1;
        }
    }
    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
    return 0;
}

