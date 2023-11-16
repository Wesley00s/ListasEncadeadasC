#include "list.h"

int main(void)
{
    // Declaração da variável para o tipo de lista
    int optListType;

    // Mensagem de boas-vindas
    printf("\n\t====================================================================================|\n\t|\n");
    printf("\t|  BEM VINDO AO MELHOR SISTEMA GERENCIADOR DE LISTAS ENCADEADAS QUE VOCÊ VERÁ HOJE! |\n\t|");
    printf("\n\t====================================================================================|\n\n");

    // Loop principal do programa
    do
    {
        // Menu para escolher o tipo de lista ou encerrar o programa
        printf("\n\
        Com qual tipo de lista você pretende interagir?\n\
        --------------------\t-------------------------\n\
        | 1 | Double List. |\t| 2 | Circle List.      |\n\
        --------------------\t-------------------------\n\
                 | 0 | Encerrar programa. |\n\
                 --------------------------\n\
        ");
        scanf("%d", &optListType);

        // Switch para escolher a ação com base na opção do usuário
        switch (optListType)
        {
        case EXIT_PROGRAM:
            printf("\nEncerrando...\n\n");
            break;

        case DOUBLE_LIST_OPT:
            // Chama as opções para a lista dupla
            opcoesDoubleList();
            break;

        case CIRCLE_LIST_OPT:
            // Chama as opções para a lista circular
            opcoesCircleList();
            break;

        default:
            // Mensagem de opção inválida
            printf("\nOpção inválida!\n");
            break;
        }

    } while (optListType != 0); // Loop continua até que o usuário escolha encerrar o programa

    return 0;
}
