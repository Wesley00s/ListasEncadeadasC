#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define EXIT_PROGRAM 0
#define ADD_BEGIN 1
#define ADD_END 2
#define ADD_MIDDLE 3
#define REMOVE_FIRST 4
#define REMOVE_MIDDLE 5
#define REMOVE_LAST 6
#define SEARCH 7
#define PRINT_LIST 8

#define DOUBLE_LIST_OPT 1
#define CIRCLE_LIST_OPT 2

typedef struct doubleListNode
{
    int data;
    struct doubleListNode *next;
    struct doubleListNode *prev;

} DoubleListNode;

typedef struct circleListNode
{
    int data;
    struct circleListNode *next;

} CircleListNode;

void showMenu();
DoubleListNode *buscarNaListaDouble(DoubleListNode **list, int getData);
DoubleListNode *deletarPrimeiroDouble(DoubleListNode **list);
DoubleListNode *deletarUltimoDouble(DoubleListNode **list);
DoubleListNode *deletarEspecificoDouble(DoubleListNode **list, int delData);
void inserirInicioDouble(DoubleListNode **list, int newData);
void inserirFimDouble(DoubleListNode **list, int newData);
void inserirEspecificoDouble(DoubleListNode **list, int newData, int prev);
void printListDouble(DoubleListNode *list);
void opcoesDoubleList();

void inserirInicioCircle(CircleListNode **list, int newData);
void inserirFimCircle(CircleListNode **list, int newData);
void inserirEspecificoCircle(CircleListNode **list, int newData, int prev);
CircleListNode *deletarUltimoCircle(CircleListNode **list);
CircleListNode *deletarPrimeiroCircle(CircleListNode **list);
CircleListNode *deletarEspecificoCircle(CircleListNode **list, int delData);
void printListCircle(CircleListNode *list);
CircleListNode *buscarNaListaCircle(CircleListNode **list, int getData);
void opcoesCircleList();

#endif
