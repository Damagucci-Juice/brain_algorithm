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
Node* SSL_CreateNode(ElementType newData);
void  SSL_DestroyNode(Node* node);
void  SSL_AppendNode(Node** head, Node* newNode);
void  SSL_InsertAfter(Node* current, Node* newNode);
void  SSL_InsertNewHead(Node** head, Node* newHead);
void  SSL_RemoveNode(Node** head, Node* remove);
Node* SLL_GetNodeAt(Node* Head, int location);
int   SSL_GetNodeCount(Node* Head);


#endif