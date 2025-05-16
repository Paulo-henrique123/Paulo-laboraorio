#include <stdio.h>

void cadastrar_cliente() {
    char nome[50];
    printf("Digite o nome do cliente: ");
    scanf("%s", nome);
    printf("Cliente %s cadastrado com sucesso!\n", nome);
}
void cadastrar_produto() {
    char nome[50];
    float preco;
    printf("Digite o nome do produto: ");
    scanf("%s", nome);
    printf("Digite o preco do produto: ");
    scanf("%f", &preco);
    printf("Produto %s cadastrado com sucesso! Preco: %.2f\n", nome, preco);
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

int main() {
int opcao = -1;
do {
    printf("MENU\n");
    printf("1. Cadastrar Cliente\n");
    printf("2. Cadastrar Produto\n");
    printf("3. Cadastrar Venda\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        cadastrar_cliente();
    } else if (opcao == 2) {
        cadastrar_produto();
    } else if (opcao == 3) {
        cadastrar_venda();
    } else if (opcao != 0) {
        printf("Opcao invalida. Tente novamente.\n");
    }
}
while (opcao != 0);
printf("Saindo do programa\n");
return 0;
}