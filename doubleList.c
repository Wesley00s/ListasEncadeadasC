#include "list.h"

void showMenu()
{
    // Exibe o menu de opções
    printf("\n\
        \t\t\tOLÁ, O QUE VOCÊ DESEJA HOJE?\n\
        -------------------------------------\t---------------------------------------\n\
        | 1 | Adicionar elemento no início. |\t| 2 | Adicionar elemento no fim.      |\n\
        -------------------------------------\t---------------------------------------\n\
        | 3 | Adicionar elemento especifico.|\t| 4 | Remover primeiro elemento.      |\n\
        -------------------------------------\t---------------------------------------\n\
        | 5 | Remover elemento especifico.  |\t| 6 | Remover último elemento.        |\n\
        -------------------------------------\t---------------------------------------\n\
        | 7 | Buscar elemento na lista.     |\t| 8 | Exibir lista.                   |\n\
        -------------------------------------\t---------------------------------------\n\
                                  | 0 | Voltar ao início. |\n\
                                  -------------------------\n\
    ");
}

void inserirInicioDouble(DoubleListNode **list, int newData)
{
    // Aloca memória para um novo nó
    DoubleListNode *newNode = malloc(sizeof(DoubleListNode));

    if (newNode)
    {
        // Inicializa o novo nó
        newNode->data = newData;
        newNode->next = *list;
        newNode->prev = NULL;

        // Se a lista não estiver vazia, ajusta os ponteiros
        if (*list)
        {
            (*list)->prev = newNode;
        }
        *list = newNode;
    }
    else
    {
        printf("\nERROR: Erro ao alocar memória!\n");
    }
}

void inserirFimDouble(DoubleListNode **list, int newData)
{
    // Aloca memória para um novo nó
    DoubleListNode *aux, *newNode = malloc(sizeof(DoubleListNode));

    if (newNode)
    {
        // Inicializa o novo nó
        newNode->data = newData;
        newNode->next = NULL;

        // Se a lista estiver vazia, o novo nó torna-se o único nó na lista
        if (*list == NULL)
        {
            *list = newNode;
            newNode->prev = NULL;
        }
        else
        {
            // Se a lista não estiver vazia, encontra o último nó e ajusta os ponteiros
            aux = *list;
            while (aux->next)
            {
                aux = aux->next;
            }
            aux->next = newNode;
            newNode->prev = aux;
        }
    }
    else
    {
        printf("\nERROR: Erro ao alocar memória!\n");
    }
}

void inserirEspecificoDouble(DoubleListNode **list, int newData, int prev)
{
    // Aloca memória para um novo nó
    DoubleListNode *aux, *newNode = malloc(sizeof(DoubleListNode));

    if (newNode)
    {
        // Inicializa o novo nó
        newNode->data = newData;
        newNode->next = NULL;

        // Se a lista estiver vazia, o novo nó torna-se o único nó na lista
        if (*list == NULL)
        {
            newNode->next = NULL;
            newNode->prev = NULL;
            *list = newNode;
        }
        else
        {
            // Se a lista não estiver vazia, encontra o nó de referência e ajusta os ponteiros
            aux = *list;
            while (aux->data != prev && aux->next)
            {
                aux = aux->next;
            }

            // Verifica se o nó de referência foi encontrado
            if (aux->data != prev)
            {
                printf("\nERROR: Valor %d não encontrado na lista!\n", prev);
                free(newNode);
                return;
            }

            newNode->next = aux->next;
            aux->next->prev = newNode;
            newNode->prev = aux;
            aux->next = newNode;
        }
    }
    else
    {
        printf("\nERROR: Erro ao alocar memória!\n");
    }
}

void printListDouble(DoubleListNode *list)
{
    if (list)
    {
        // Imprime os elementos da lista dupla
        printf("\nLISTA: ");

        while (list)
        {
            printf("%d -> ", list->data);
            list = list->next;
        }

        printf("NULL\n\n");
        return;
    }

    printf("\nLISTA VAZIA\n\n");
}

DoubleListNode *deletarUltimoDouble(DoubleListNode **list)
{
    // Remove o último nó da lista dupla
    DoubleListNode *prev, *remove = NULL;

    remove = *list;
    if (*list)
    {
        while (remove->next)
        {
            prev = remove;
            remove = remove->next;
        }

        if (remove->prev)
        {
            prev->next->next = NULL;
        }
        else
        {
            *list = NULL;
        }
    }
    return remove;
}

DoubleListNode *deletarPrimeiroDouble(DoubleListNode **list)
{
    // Remove o primeiro nó da lista dupla
    DoubleListNode *remove = NULL;

    if (*list)
    {
        remove = *list;
        *list = remove->next;
    }
    return remove;
}

DoubleListNode *deletarEspecificoDouble(DoubleListNode **list, int delData)
{
    // Remove um nó específico da lista dupla
    DoubleListNode *aux, *remove = NULL;

    if (*list)
    {
        if ((*list)->data == delData)
        {
            // Remove o primeiro nó da lista
            remove = *list;
            *list = remove->next;
            if (*list)
            {
                (*list)->prev = NULL;
            }
        }
        else
        {
            // Procura o nó a ser removido na lista
            aux = *list;
            while (aux->next && aux->next->data != delData)
            {
                aux = aux->next;
            }

            if (aux->next)
            {
                // Remove o nó da lista e ajusta os ponteiros
                remove = aux->next;
                aux->next = remove->next;

                if (aux->next)
                {
                    aux->next->prev = aux;
                }
            }
        }
    }
    return remove;
}

DoubleListNode *buscarNaListaDouble(DoubleListNode **list, int getData)
{
    // Busca um elemento na lista dupla
    DoubleListNode *aux, *node = NULL;

    aux = *list;
    while (aux && aux->data != getData)
    {
        aux = aux->next;
    }
    if (aux)
    {
        node = aux;
    }

    return node;
}

void opcoesDoubleList()
{
    // Função principal para manipulação da lista dupla
    DoubleListNode *nodeDouble, *listDouble = NULL;
    int optAction, newData, prev;

    printf("\n\n\tDOUBLE LIST *****************************************************************\n\n");

    do
    {
        // Exibe o menu de opções
        showMenu();
        scanf("%d", &optAction);

        switch (optAction)
        {
        case EXIT_PROGRAM:
            printf("\nVoltando...\n\n");
            break;
        case ADD_BEGIN:
            // Adiciona um elemento no início da lista dupla
            printf("\nInforme o valor do novo elemento que deseja inserir no início da lista dupla: ");
            scanf("%d", &newData);
            inserirInicioDouble(&listDouble, newData);
            break;
        case ADD_END:
            // Adiciona um elemento no final da lista dupla
            printf("\nInforme o valor do novo elemento que deseja inserir no final da lista dupla: ");
            scanf("%d", &newData);
            inserirFimDouble(&listDouble, newData);
            break;
        case ADD_MIDDLE:
            // Adiciona um elemento em uma posição específica da lista dupla
            printf("\nInforme o valor do novo elemento que deseja inserir no meio da lista dupla: ");
            scanf("%d", &newData);
            printf("\nAgora informe o valor de referência: ");
            scanf("%d", &prev);
            inserirEspecificoDouble(&listDouble, newData, prev);
            break;
        case REMOVE_FIRST:
            // Remove o primeiro elemento da lista dupla
            nodeDouble = deletarPrimeiroDouble(&listDouble);

            if (nodeDouble)
            {
                printf("\nPrimeiro elemento %d removido.\n\n", nodeDouble->data);
                free(nodeDouble);
            }
            else
            {
                printf("\nImpossível remover elemento, a lista dupla está vazia!\n\n");
            }

            break;
        case REMOVE_MIDDLE:
            // Remove um elemento específico da lista dupla
            printf("\nInforme o elemento que deseja remover da lista dupla: ");
            scanf("%d", &newData);
            nodeDouble = deletarEspecificoDouble(&listDouble, newData);

            if (nodeDouble)
            {
                printf("\nElemento %d removido.\n", nodeDouble->data);
                free(nodeDouble);
            }
            else
            {
                printf("\nElemento %d não encontrado na lista dupla!\n", newData);
            }
            break;
        case REMOVE_LAST:
            // Remove o último elemento da lista dupla
            nodeDouble = deletarUltimoDouble(&listDouble);

            if (nodeDouble)
            {
                printf("\nÚltimo elemento %d removido.\n\n", nodeDouble->data);
                free(nodeDouble);
            }
            else
            {
                printf("\nImpossível remover elemento, a lista dupla está vazia!\n\n");
            }

            break;
        case SEARCH:
            // Busca um elemento na lista dupla
            printf("\nInforme o elemento que deseja buscar: ");
            scanf("%d", &newData);
            nodeDouble = buscarNaListaDouble(&listDouble, newData);
            if (nodeDouble)
            {
                printf("\nElemento %d encontrado!\n\n", nodeDouble->data);
            }
            else
            {
                printf("\nElemento %d não encontrado na lista dupla!\n", newData);
            }

            break;
        case PRINT_LIST:
            // Exibe a lista dupla
            printListDouble(listDouble);
            break;

        default:
            printf("\nOpção inválida!\n\n");
            break;
        }

    } while (optAction != 0);

    // Libera a memória da lista dupla
    free(listDouble);
}
