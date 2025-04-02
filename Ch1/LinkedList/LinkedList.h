#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct tagNode {
    ElementType data;
    struct tagNode* next;
} Node;

/* 함수 원형 선언 */
Node* SLL_CreateNode(ElementType newData);
void  SLL_DestroyNode(Node* node);
void  SLL_AppendNode(Node** head, Node* newNode);
void  SLL_InsertAfter(Node* current, Node* newNode);
void  SLL_InsertNewHead(Node** head, Node* newHead);
void  SLL_RemoveNode(Node** head, Node* remove);
Node* SLL_GetNodeAt(Node* Head, int location);
int   SLL_GetNodeCount(Node* Head);
void printList(Node** list);

#endif