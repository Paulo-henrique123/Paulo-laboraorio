#include <stdio.h>
#include <string.h>

struct Cliente {
    int id;
    char nome[50];
    char cpf[20];
};

struct Produto {
    int id;
    char nome[50];
    float preco;
    int estoque;
};

struct ItemVenda {
    int id_produto;
    int quantidade;
    float valor_unitario;
};

struct Venda {
    int id_venda;
    int id_cliente;
    char data[20];
    struct ItemVenda itens[10];
    int total_itens;
    float total;
};

struct Cliente clientes[10];
int total_clientes = 0;

struct Produto produtos[10];
int total_produtos = 0;

struct Venda vendas[10];
int total_vendas = 0;

void cadastrar_cliente() {
    if (total_clientes >= 10) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    clientes[total_clientes].id = total_clientes + 1;

    printf("Nome: ");
    scanf(" %[^\n]", clientes[total_clientes].nome);
    printf("CPF: ");
    scanf(" %s", clientes[total_clientes].cpf);

    printf("Cliente cadastrado com ID %d!\n", clientes[total_clientes].id);
    total_clientes++;
}

void remover_cliente() {
    int id;
    printf("Digite o ID do cliente a remover: ");
    scanf("%d", &id);

    int pos = -1;
    for (int i = 0; i < total_clientes; i++) {
        if (clientes[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Cliente não encontrado.\n");
        return;
    }

    for (int i = pos; i < total_clientes - 1; i++) {
        clientes[i] = clientes[i + 1];
    }

    total_clientes--;
    printf("Cliente removido com sucesso.\n");
}

void cadastrar_produto() {
    if (total_produtos >= 10) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    produtos[total_produtos].id = total_produtos + 1;

    printf("Nome do produto: ");
    scanf(" %[^\n]", produtos[total_produtos].nome);
    printf("Preço unitário: ");
    scanf("%f", &produtos[total_produtos].preco);
    printf("Estoque disponível: ");
    scanf("%d", &produtos[total_produtos].estoque);

    printf("Produto cadastrado com ID %d!\n", produtos[total_produtos].id);
    total_produtos++;
}

void remover_produto() {
    int id;
    printf("Digite o ID do produto a remover: ");
    scanf("%d", &id);

    int pos = -1;
    for (int i = 0; i < total_produtos; i++) {
        if (produtos[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Produto não encontrado.\n");
        return;
    }

    for (int i = pos; i < total_produtos - 1; i++) {
        produtos[i] = produtos[i + 1];
    }

    total_produtos--;
    printf("Produto removido com sucesso.\n");
}

void listar_clientes() {
    printf("\nClientes:\n");
    for (int i = 0; i < total_clientes; i++) {
        printf("ID: %d | Nome: %s | CPF: %s\n", clientes[i].id, clientes[i].nome, clientes[i].cpf);
    }
}

void listar_produtos() {
    printf("\nProdutos:\n");
    for (int i = 0; i < total_produtos; i++) {
        printf("ID: %d | Nome: %s | Preço: R$ %.2f | Estoque: %d\n", produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].estoque);
    }
}

void cadastrar_venda() {
    if (total_vendas >= 10) {
        printf("Limite de vendas atingido.\n");
        return;
    }

    struct Venda v;
    v.id_venda = total_vendas + 1;
    v.total_itens = 0;
    v.total = 0;

    printf("ID do cliente: ");
    scanf("%d", &v.id_cliente);
    printf("Data da venda (opcional): ");
    scanf(" %[^\n]", v.data);

    int continuar = 1;
    while (continuar && v.total_itens < 10) {
        struct ItemVenda item;
        printf("ID do produto: ");
        scanf("%d", &item.id_produto);
        printf("Quantidade: ");
        scanf("%d", &item.quantidade);

        item.valor_unitario = produtos[item.id_produto - 1].preco;
        v.itens[v.total_itens] = item;
        v.total_itens++;
        v.total += item.quantidade * item.valor_unitario;

        printf("Adicionar outro item? (1-Sim / 0-Não): ");
        scanf("%d", &continuar);
    }

    vendas[total_vendas] = v;
    total_vendas++;

    printf("Venda cadastrada com sucesso! Total: R$ %.2f\n", v.total);
}

void listar_vendas() {
    for (int i = 0; i < total_vendas; i++) {
        struct Venda v = vendas[i];
        printf("\nVenda ID: %d | Cliente ID: %d | Data: %s\n", v.id_venda, v.id_cliente, v.data);
        for (int j = 0; j < v.total_itens; j++) {
            struct ItemVenda item = v.itens[j];
            printf("  Produto ID: %d | Quantidade: %d | Valor Unitário: R$ %.2f\n",
                   item.id_produto, item.quantidade, item.valor_unitario);
        }
        printf("Total da nota fiscal: R$ %.2f\n", v.total);
    }
}

int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Cadastrar Produto\n");
        printf("3. Cadastrar Venda\n");
        printf("4. Listar Clientes\n");
        printf("5. Listar Produtos\n");
        printf("6. Listar Vendas\n");
        printf("7. Remover Cliente\n");
        printf("8. Remover Produto\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrar_cliente(); break;
            case 2: cadastrar_produto(); break;
            case 3: cadastrar_venda(); break;
            case 5: listar_produtos(); break;
            case 6: listar_vendas(); break;
            case 7: remover_cliente(); break;
            case 8: remover_produto(); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
