#include <stdio.h>
#include <string.h>

char clientes[10][50];  
int total_clientes = 0;
char produtos[10][50];  
int total_produtos = 0;

void cadastrar_cliente() {
    if (total_clientes >= 10) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    char nome[50];
    printf("Digite o nome do cliente: ");
    scanf("%s", nome);

    strcpy(clientes[total_clientes], nome);
    total_clientes++;

    printf("Cliente %s cadastrado com sucesso!\n", nome);
}

void cadastrar_produtos() {
    if (total_produtos >= 10) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    char nome[50];
    float preco;

    printf("Digite o nome do produto: ");
    scanf("%s", nome);
    printf("Digite o preco do produto: ");
    scanf("%f", &preco);

    strcpy(produtos[total_produtos], nome);
    total_produtos++;

    printf("Produto %s cadastrado com sucesso! Preço: %.2f\n", nome, preco);
}

void cadastrar_venda() {
    char cliente[50], produto[50];
    int quantidade;

    printf("Digite o nome do cliente: ");
    scanf("%s", cliente);
    printf("Digite o nome do produto: ");
    scanf("%s", produto);
    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);

    printf("Venda cadastrada com sucesso! Cliente: %s, Produto: %s, Quantidade: %d\n", cliente, produto, quantidade);
}

void listar_clientes() {
    if (total_clientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("Lista de clientes:\n");
    for (int i = 0; i < total_clientes; i++) {
        printf("%d. %s\n", i + 1, clientes[i]);
    }
}

void listar_produtos() {
    if (total_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Lista de produtos:\n");
    for (int j = 0; j < total_produtos; j++) {
        printf("%d. %s\n", j + 1, produtos[j]);
    }
}

int main() {
    int opcao = -1;

    do {
        printf("\nMENU\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Cadastrar Produto\n");
        printf("3. Cadastrar Venda\n");
        printf("4. Listar Clientes\n");
        printf("5. Listar Produtos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_cliente();
                break;
            case 2:
                cadastrar_produtos();
                break;
            case 3:
                cadastrar_venda();
                break;
            case 4:
                listar_clientes();
                break;
            case 5:
                listar_produtos();
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}