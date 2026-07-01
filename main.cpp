#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto
{
    int codigo;
    char nome[100];
    float preco;
    int qtd;
    float QtdProd;
    struct Produto *prox;
} p;

void Inserir(p **lista, int codigo, char nome[100], float preco, float QtdProd, int qtd);
void Mostrar(p *lista);
void Delete(p **lista, int codigo);
void busca(p *lista, int codigo);

int main()
{
    p *lista = NULL;
    int qtd = 0, op;
    float QtdProd = 0;
    char nome[100];
    float preco;
    int codigo = 100;

    while (true)
    {
        printf("\n 1 --> inserir");
        printf("\n 2 --> Mostrar");
        printf("\n 3 --> deletar");
        printf("\n 4 --> Busca");
        printf("\n 0 --> Sair");
        printf("\n Informe opcao desejada: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\n Informe a quantidade de elementos que deseja inserir: ");
            scanf("%d", &qtd);
            for (int i = 0; i < qtd; i++)
            {
                printf("\n Informe o nome do produto %i: ", i + 1);
                scanf("%99s", &nome[i]);

                printf("\n Informe o preco do produto %20s: ", nome);
                scanf("%f", &preco);

                printf("\n Digite a quantidade do produto %20s: ", nome);
                scanf("%f", &QtdProd);

                Inserir(&lista, codigo, nome, preco, QtdProd, qtd);
                codigo++;
            }
            break;
        case 2:
            Mostrar(lista);
            break;
        case 3:
            int cod;
            printf("\n Informe a quantidade de elementos que deseja excluir: ");
            scanf("%d", &qtd);
            for (int i = 0; i < qtd; i++)
            {
                printf("\n Digite o codigo do produto que deseja apaguar %i: ", i + 1);
                scanf("%f", &cod);
                Delete(&lista, cod);
            }
            break;
        case 4:
            float codigo;
            printf("\n Informe codigo do produto que deseja encontrar: ");
            scanf("%f", &codigo);
            busca(lista, codigo);
            break;
        case 0:
            printf("\n saindo.....");
            return 0;
        }
    }
    return 0;
}
void Inserir(p **lista, int codigo, char nome[100], float preco, float QtdProd, int qtd)
{
    p *novo = (p *)malloc(sizeof(p));
    novo->codigo = codigo;
    strcpy(novo->nome, nome); // strcpy(destino , origem) -> destino aonde vai ser alocada, origem aonde ela vem copia a string para novo->nome
    novo->preco = preco;
    novo->QtdProd = QtdProd;
    novo->qtd = qtd;
    novo->prox = NULL;
    if (*lista == NULL || preco < (*lista)->preco) // O(1)
    {
        novo->prox = *lista;
        *lista = novo;
        return;
    }

    p *atual = *lista;
    while (atual->prox != NULL && atual->prox->preco < preco) // o(n)
        atual = atual->prox;

    novo->prox = atual->prox;
    atual->prox = novo;
    printf("\n Elementos inseridos com sucesso !");
    return;
}

void Mostrar(p *lista)
{
    while (lista != NULL) // o(n)
    {
        printf("\n Codigo: %d", lista->codigo);
        printf("\n Nome: %s", lista->nome);
        printf("\n preco: %.2f", lista->preco);
        printf("\n quantidade de produto: %.2f ", lista->QtdProd);
        if (lista->qtd != NULL) // o(1)
            printf("\n Quantidade Total de podutos cadastrados: %d", lista->qtd);
        lista = lista->prox;
    }
    printf(" NULL\n");
    // printf("\n ---------------- \n");
    // printf("Total de produtos cadastrados %d: ", lista->qtd);
}

// void QuickSort(p **lista)

void Delete(p **lista, int codigo) // recebo a lista é o codigo do produto que desejo deletar
{
    p *rem;      // aqui tenho um ponteiro
    if (!*lista) // se lista estiver vazia entra aqui
    {
        printf("\n Lista vazia !");
        return;
    }
    if (*lista != NULL && codigo == (*lista)->codigo) // se lista não está vazia é o codigo que recebo e igual ao codigo do primeiro elemento
    {
        rem = *lista;       // capturei o primeiro
        *lista = rem->prox; // primeiro é igual ao primeiro
        free(rem);
        return;
    }

    p *atual = *lista;
    while (atual->prox != NULL & codigo == atual->codigo) // tem proximo ? não codigo é igual ao codigo ddo primeiro ? sim
        atual = atual->prox;

    if (!atual->prox)
    { // se o não achar o codigo cai aqui
        printf("\n Valor não encontrado !");
        return;
    }
    rem = atual->prox;       // o rem aponta para o endereço do proximo que captura o endereço que o primeiro aponta
    atual->prox = rem->prox; // agr o prox do atual será o que aponta para prox do que está sendo deletado
    free(rem);
    printf("\n Valor deletado da lista com sucesso !");
}

void busca(p *lista, int codigo)
{
    while (lista != NULL) // O(n)
    {
        if (lista->codigo == codigo)
        {
            printf("\n Codigo: %d", lista->codigo);
            printf("\n Nome: %s", lista->nome);
            printf("\n preco: %.2f", lista->preco);
            printf("\n quantidade de produto: %.2f ", lista->QtdProd);

            if (lista->qtd != NULL)
                printf("\n Quantidade Total de podutos cadastrados: %d", lista->qtd);
        }
        else
            printf("\n Elemento não encontrado !");
        lista = lista->prox;
    }
    printf("NULL\n");
}