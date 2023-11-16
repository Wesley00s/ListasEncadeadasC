#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

// Definição de constantes para as opções do menu
#define EXIT_PROGRAM 0
#define ADD_BEGIN 1
#define ADD_END 2
#define ADD_MIDDLE 3
#define REMOVE_FIRST 4
#define REMOVE_MIDDLE 5
#define REMOVE_LAST 6
#define SEARCH 7
#define PRINT_LIST 8

// Definição de constantes para escolher entre lista dupla e lista circular
#define DOUBLE_LIST_OPT 1
#define CIRCLE_LIST_OPT 2

// Definição da estrutura de um nó em uma lista duplamente encadeada
typedef struct doubleListNode
{
    int data;
    struct doubleListNode *next;
    struct doubleListNode *prev;

} DoubleListNode;

// Definição da estrutura de um nó em uma lista circular
typedef struct circleListNode
{
    int data;
    struct circleListNode *next;

} CircleListNode;

void showMenu(); // Mostrar menu

// Protótipos de funções para operações em listas duplamente encadeadas
DoubleListNode *buscarNaListaDouble(DoubleListNode **list, int getData);
DoubleListNode *deletarPrimeiroDouble(DoubleListNode **list);
DoubleListNode *deletarUltimoDouble(DoubleListNode **list);
DoubleListNode *deletarEspecificoDouble(DoubleListNode **list, int delData);
void inserirInicioDouble(DoubleListNode **list, int newData);
void inserirFimDouble(DoubleListNode **list, int newData);
void inserirEspecificoDouble(DoubleListNode **list, int newData, int prev);
void printListDouble(DoubleListNode *list);
void opcoesDoubleList();

// Protótipos de funções para operações em listas circulares
CircleListNode *buscarNaListaCircle(CircleListNode **list, int getData);
CircleListNode *deletarPrimeiroCircle(CircleListNode **list);
CircleListNode *deletarUltimoCircle(CircleListNode **list);
CircleListNode *deletarEspecificoCircle(CircleListNode **list, int delData);
void inserirInicioCircle(CircleListNode **list, int newData);
void inserirFimCircle(CircleListNode **list, int newData);
void inserirEspecificoCircle(CircleListNode **list, int newData, int prev);
void printListCircle(CircleListNode *list);
void opcoesCircleList();

#endif
