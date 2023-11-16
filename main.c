#include "lib.h"

int main()
{

    int optListType;

    printf("\n\t====================================================================================|\n\t|\n");
    printf("\t|  BEM VINDO AO MELHOR SISTEMA GERENCIADOR DE LISTAS ENCADEADAS QUE VOCÊ VERÁ HOJE! |\n\t|");
    printf("\n\t====================================================================================|\n\n");

    do
    {
        printf("\n\
        Com qual tipo de lista você pretende interagir?\n\
        --------------------\t-------------------------\n\
        | 1 | Double List. |\t| 2 | Circle List.      |\n\
        --------------------\t-------------------------\n\
                 | 0 | Encerrar programa. |\n\
                 --------------------------\n\
        ");
        scanf("%d", &optListType);

        switch (optListType)
        {
        case EXIT_PROGRAM:
            printf("\nEncerrando...\n\n");
            break;

        case DOUBLE_LIST_OPT:
            opcoesDoubleList();
            break;

        case CIRCLE_LIST_OPT:
            opcoesCircleList();
            break;

        default:
            printf("\nOpção inválida!\n");
            break;
        }

    } while (optListType != 0);

    return 0;
}