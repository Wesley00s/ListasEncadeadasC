#include "list.h"

void inserirInicioCircle(CircleListNode **list, int newData)
{
    // Aloca memória para um novo nó
    CircleListNode *newNode = malloc(sizeof(CircleListNode));

    if (newNode)
    {
        // Inicializa o novo nó
        newNode->data = newData;
        newNode->next = newNode;

        // Se a lista não estiver vazia, ajusta os ponteiros para incluir o novo nó
        if (*list)
        {
            CircleListNode *lastNode = *list;
            while (lastNode->next != *list)
            {
                lastNode = lastNode->next;
            }

            newNode->next = *list;
            lastNode->next = newNode;
        }

        // Atualiza a cabeça da lista
        *list = newNode;
    }
    else
    {
        printf("\nERROR: Erro ao alocar memória!\n");
    }
}

void inserirFimCircle(CircleListNode **list, int newData)
{
    // Aloca memória para um novo nó
    CircleListNode *newNode = malloc(sizeof(CircleListNode));

    if (newNode)
    {
        // Inicializa o novo nó
        newNode->data = newData;
        newNode->next = newNode;

        // Se a lista estiver vazia, o novo nó torna-se o único nó na lista
        if (*list == NULL)
        {
            *list = newNode;
        }
        else
        {
            // Se a lista não estiver vazia, encontra o último nó e ajusta os ponteiros
            CircleListNode *lastNode = *list;
            while (lastNode->next != *list)
            {
                lastNode = lastNode->next;
            }

            newNode->next = *list;
            lastNode->next = newNode;
        }
    }
    else
    {
        printf("\nERROR: Erro ao alocar memória!\n");
    }
}

void inserirEspecificoCircle(CircleListNode **list, int newData, int prev)
{
    CircleListNode *aux, *newNode = malloc(sizeof(CircleListNode));

    if (newNode)
    {
        // Inicializa o novo nó
        newNode->data = newData;
        newNode->next = newNode;

        // Se a lista estiver vazia, o novo nó torna-se o único nó na lista
        if (*list == NULL)
        {
            *list = newNode;
        }
        else
        {
            // Se a lista não estiver vazia, encontra o nó de referência e ajusta os ponteiros
            aux = *list;
            while (aux->data != prev && aux->next != *list)
            {
                aux = aux->next;
            }

            newNode->next = aux->next;
            aux->next = newNode;
        }
    }
    else
    {
        printf("\nERROR: Erro ao alocar memória!\n");
    }
}

CircleListNode *deletarUltimoCircle(CircleListNode **list)
{
    CircleListNode *remove = *list;

    if (*list)
    {
        // Encontra o último nó e ajusta os ponteiros
        while (remove->next != *list)
        {
            remove = remove->next;
        }

        if (remove->next == remove)
        {
            // Se há apenas um nó na lista, a lista fica vazia
            *list = NULL;
        }
        else
        {
            // Se há mais de um nó na lista, ajusta os ponteiros do último nó
            CircleListNode *lastNode = *list;
            while (lastNode->next != remove)
            {
                lastNode = lastNode->next;
            }

            lastNode->next = remove->next;
        }
    }

    return remove;
}

CircleListNode *deletarPrimeiroCircle(CircleListNode **list)
{
    CircleListNode *remove = *list;

    if (*list)
    {
        if (remove->next == *list)
        {
            // Se há apenas um nó na lista
            *list = NULL;
        }
        else
        {
            // Se há mais de um nó na lista, ajusta os ponteiros para remover o primeiro nó
            CircleListNode *lastNode = *list;
            while (lastNode->next != remove)
            {
                lastNode = lastNode->next;
            }

            lastNode->next = remove->next;
            *list = remove->next;
        }
    }

    return remove;
}

CircleListNode *deletarEspecificoCircle(CircleListNode **list, int delData)
{
    CircleListNode *aux = *list;
    CircleListNode *remove = NULL;

    if (*list)
    {
        if (aux->data == delData)
        {
            // Se o nó a ser removido é o primeiro, ajusta os ponteiros
            remove = *list;
            if (remove->next == *list)
            {
                *list = NULL;
            }
            else
            {
                CircleListNode *lastNode = *list;
                while (lastNode->next != remove)
                {
                    lastNode = lastNode->next;
                }

                lastNode->next = remove->next;
                *list = remove->next;
            }
        }
    }

    // Procura e remove o nó com o valor especificado
    while (aux->next != *list)
    {
        if (aux->next->data == delData)
        {
            remove = aux->next;
            aux->next = remove->next;
            break;
        }

        aux = aux->next;
    }

    return remove;
}

void printListCircle(CircleListNode *list)
{
    if (list)
    {
        CircleListNode *current = list;
        printf("\nLISTA: ");

        // Percorre a lista circular e imprime os elementos
        do
        {
            printf("%d -> ", current->data);
            current = current->next;

        } while (current != list);

        printf("NULL\n\n");
        return;
    }

    printf("\nLISTA VAZIA\n\n");
}

CircleListNode *buscarNaListaCircle(CircleListNode **list, int getData)
{
    CircleListNode *aux = *list;

    if (*list)
    {
        // Procura o elemento na lista circular
        do
        {
            if (aux->data == getData)
            {
                return aux;
            }

            aux = aux->next;
        } while (aux != *list);
    }

    return NULL;
}

void opcoesCircleList()
{
    // Função principal para manipulação da lista dupla
    CircleListNode *nodeCircle, *listCircle = NULL;
    int optAction, newData, prev;

    printf("\n\n\tCIRCLE LIST *****************************************************************\n\n");
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
            // Adiciona um elemento no início da lista circular
            printf("\nInforme o valor do novo elemento que deseja inserir no início da lista circular: ");
            scanf("%d", &newData);
            inserirInicioCircle(&listCircle, newData);
            break;
        case ADD_END:
            // Adiciona um elemento no final da lista circular
            printf("\nInforme o valor do novo elemento que deseja inserir no final da lista circular: ");
            scanf("%d", &newData);
            inserirFimCircle(&listCircle, newData);
            break;
        case ADD_MIDDLE:
            // Adiciona um elemento em uma posição específica da lista circular
            printf("\nInforme o valor do novo elemento que deseja inserir no meio da lista circular: ");
            scanf("%d", &newData);
            printf("\nAgora informe o valor de referência: ");
            scanf("%d", &prev);
            inserirEspecificoCircle(&listCircle, newData, prev);
            break;
        case REMOVE_FIRST:
            // Remove o primeiro elemento da lista circular
            nodeCircle = deletarPrimeiroCircle(&listCircle);

            if (nodeCircle)
            {
                printf("\nPrimerio elemento %d removido.\n\n", nodeCircle->data);
                free(nodeCircle);
            }
            else
            {
                printf("\nImpossível remover elemento, a lista circular está vazia!\n\n");
            }

            break;
        case REMOVE_MIDDLE:
            // Remove um elemento específico da lista circular
            printf("\nInforme o elemento que deseja remover da lista circular: ");
            scanf("%d", &newData);
            nodeCircle = deletarEspecificoCircle(&listCircle, newData);

            if (nodeCircle)
            {
                printf("\nElemento %d removido.\n", nodeCircle->data);
                free(nodeCircle);
            }
            else
            {
                printf("\nElemento %d não encontrado na lista circular!\n", newData);
            }
            break;
        case REMOVE_LAST:
            // Remove o último elemento da lista circular
            nodeCircle = deletarUltimoCircle(&listCircle);

            if (nodeCircle)
            {
                printf("\nÚltimo elemento %d removido.\n\n", nodeCircle->data);
                free(nodeCircle);
            }
            else
            {
                printf("\nImpossível remover elemento, a lista está vazia!\n\n");
            }

            break;
        case SEARCH:
            // Busca um elemento na lista circular
            printf("\nInforme o elemento que deseja buscar na lista circular: ");
            scanf("%d", &newData);
            nodeCircle = buscarNaListaCircle(&listCircle, newData);
            if (nodeCircle)
            {
                printf("\nElemento %d encontrado!\n\n", nodeCircle->data);
            }
            else
            {
                printf("\nElemento %d não encontrado na lista circular!\n", newData);
            }

            break;
        case PRINT_LIST:
            // Exibe a lista circular
            printListCircle(listCircle);
            break;

        default:
            printf("\nOpção inválida!\n\n");
            break;
        }

    } while (optAction != 0);

    // Libera a memória da lista circular
    free(listCircle);
}