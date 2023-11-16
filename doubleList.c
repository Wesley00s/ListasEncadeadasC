#include "lib.h"

void showMenu()
{
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
    DoubleListNode *newNode = malloc(sizeof(DoubleListNode));

    if (newNode)
    {
        newNode->data = newData;
        newNode->next = *list;
        newNode->prev = NULL;

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
    DoubleListNode *aux, *newNode = malloc(sizeof(DoubleListNode));

    if (newNode)
    {
        newNode->data = newData;
        newNode->next = NULL;

        if (*list == NULL)
        {
            *list = newNode;
            newNode->prev = NULL;
        }
        else
        {
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
    DoubleListNode *aux, *newNode = malloc(sizeof(DoubleListNode));

    if (newNode)
    {
        newNode->data = newData;
        newNode->next = NULL;

        if (*list == NULL)
        {
            newNode->next = NULL;
            newNode->prev = NULL;
            *list = newNode;
        }
        else
        {
            aux = *list;
            while (aux->data != prev && aux->next)
            {
                aux = aux->next;
            }

            if (aux->data != prev)
            {
                printf("\nERROR: Valor %d não encontado na lista!\n", prev);
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
    if (!list)
    {
        printf("\nLISTA VAZIA\n\n");
        return;
    }

    printf("\nLISTA: ");

    while (list)
    {
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("NULL\n\n");
}

DoubleListNode *deletarUltimoDouble(DoubleListNode **list)
{
    DoubleListNode *prev, *remove = NULL;

    remove = *list;
    if (*list)
    {
        while (remove->next)
        {
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
    DoubleListNode *aux, *remove = NULL;

    if (*list)
    {
        if ((*list)->data == delData)
        {
            remove = *list;
            *list = remove->next;
            if (*list)
            {
                (*list)->prev = NULL;
            }
        }
        else
        {
            aux = *list;
            while (aux->next && aux->next->data != delData)
            {
                aux = aux->next;
            }
            if (aux->next)
            {
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
    DoubleListNode *nodeDouble, *listDouble = NULL;
    int optAction, newData, prev;

    printf("\n\n\tDOUBLE LIST *****************************************************************\n\n");

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
            printf("\nInforme o valor do novo elemento que deseja inserir no início da lista dupla: ");
            scanf("%d", &newData);
            inserirInicioDouble(&listDouble, newData);
            break;
        case ADD_END:
            printf("\nInforme o valor do novo elemento que deseja inserir no final da lista dupla: ");
            scanf("%d", &newData);
            inserirFimDouble(&listDouble, newData);
            break;
        case ADD_MIDDLE:
            printf("\nInforme o valor do novo elemento que deseja inserir no meio da lista dupla: ");
            scanf("%d", &newData);
            printf("\nAgora informe o valor de referência: ");
            scanf("%d", &prev);
            inserirEspecificoDouble(&listDouble, newData, prev);
            break;
        case REMOVE_FIRST:
            nodeDouble = deletarPrimeiroDouble(&listDouble);

            if (nodeDouble)
            {
                printf("\nPrimerio elemento %d removido.\n\n", nodeDouble->data);
                free(nodeDouble);
            }
            else
            {
                printf("\nImpossível remover elemento, a lista dupla está vazia!\n\n");
            }

            break;
        case REMOVE_MIDDLE:
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
            printListDouble(listDouble);
            break;

        default:
            printf("\nOpção inválida!\n\n");
            break;
        }

    } while (optAction != 0);

}