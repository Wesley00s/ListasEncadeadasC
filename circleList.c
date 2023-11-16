#include "lib.h"

void inserirInicioCircle(CircleListNode **list, int newData)
{
    CircleListNode *newNode = malloc(sizeof(CircleListNode));

    if (newNode)
    {
        newNode->data = newData;
        newNode->next = newNode;

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

        *list = newNode;
    }
    else
    {
        printf("\nERROR: Erro ao alocar memória!\n");
    }
}

void inserirFimCircle(CircleListNode **list, int newData)
{
    CircleListNode *newNode = malloc(sizeof(CircleListNode));

    if (newNode)
    {
        newNode->data = newData;
        newNode->next = newNode;

        if (*list == NULL)
        {
            *list = newNode;
        }
        else
        {
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
        newNode->data = newData;
        newNode->next = newNode;

        if (*list == NULL)
        {
            *list = newNode;
        }
        else
        {
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
        while (remove->next != *list)
        {
            remove = remove->next;
        }

        if (remove->next == remove)
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

        }
    }

    return remove;
}

CircleListNode *deletarPrimeiroCircle(CircleListNode **list)
{
    if (*list == NULL)
    {
        return NULL;
    }

    CircleListNode *remove = *list;

    if (remove->next == *list)
    {
        free(remove);
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
    if (!list)
    {
        printf("\nLISTA VAZIA\n\n");
        return;
    }

    CircleListNode *current = list;
    printf("\nLISTA: ");

    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != list);
    printf("NULL\n\n");
}

CircleListNode *buscarNaListaCircle(CircleListNode **list, int getData)
{
    CircleListNode *aux = *list;

    if (*list)
    {
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
    CircleListNode *nodeCircle, *listCircle = NULL;
    int optAction, newData, prev;

    printf("\n\n\tCIRCLE LIST *****************************************************************\n\n");
    do
    {
        showMenu();
        scanf("%d", &optAction);

        switch (optAction)
        {
        case EXIT_PROGRAM:
            printf("\nVoltando...\n\n");
            break;
        case ADD_BEGIN:
            printf("\nInforme o valor do novo elemento que deseja inserir no início da lista circular: ");
            scanf("%d", &newData);
            inserirInicioCircle(&listCircle, newData);
            break;
        case ADD_END:
            printf("\nInforme o valor do novo elemento que deseja inserir no final da lista circular: ");
            scanf("%d", &newData);
            inserirFimCircle(&listCircle, newData);
            break;
        case ADD_MIDDLE:
            printf("\nInforme o valor do novo elemento que deseja inserir no meio da lista circular: ");
            scanf("%d", &newData);
            printf("\nAgora informe o valor de referência: ");
            scanf("%d", &prev);
            inserirEspecificoCircle(&listCircle, newData, prev);
            break;
        case REMOVE_FIRST:
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
            printListCircle(listCircle);
            break;

        default:
            printf("\nOpção inválida!\n\n");
            break;
        }

    } while (optAction != 0);
}