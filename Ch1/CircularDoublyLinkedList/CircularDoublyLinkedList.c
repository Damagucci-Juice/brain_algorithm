#include "CircularDoublyLinkedList.h"

/* 노드 생성 */
Node* CDLL_CreateNode(ElementType NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->PrevNode = NULL;

    return NewNode;
}

/* 노드 소멸 */
void CDLL_DestoryNode(Node* Node) {
    free(Node);
}

/* 노드 추가 */
void CDLL_AppendNode(Node** Head, Node* NewNode) {
    /* 헤드 노드가 NULL이라면 새로운 노드가 Head */
    if (*Head == NULL ) {
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
    } else {
        /* 테일과 헤드사이에 NewNode를 삽입한다. */
        Node* Tail = (*Head)->PrevNode;
        
        Tail->NextNode->PrevNode = NewNode;
        Tail->NextNode = NewNode;

        NewNode->NextNode = *Head;
        NewNode->PrevNode = Tail;
    }
}

/* 노드 삽입 */
void CDLL_InsertAfter(Node* Current, Node* NewNode) {
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    Current->NextNode->PrevNode = NewNode;
    Current->NextNode = NewNode;
}

/* 노드 제거 */
void CDLL_RemoveNode(Node** Head, Node* Remove) {
    if (*Head == Remove) {
        (*Head)->PrevNode->NextNode = Remove->NextNode;
        (*Head)->NextNode->PrevNode = Remove->PrevNode;

        *Head = Remove->NextNode;
    } else {
        Remove->PrevNode->NextNode = Remove->NextNode;
        Remove->NextNode->PrevNode = Remove->PrevNode;
    }

    Remove->PrevNode = NULL;
    Remove->NextNode = NULL;
}

/* 노드 탐색 */
Node* CDLL_GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;
    while(Current != NULL && (--Location) >= 0) {
        Current = Current->NextNode;
    }
    return Current;
}

/* 노드 수 세기 */
int CDLL_GetNodeCount(Node* Head) {
    unsigned int Count = 0;
    Node*        Current = Head;

    while (Current != NULL) {
        Current = Current->NextNode;
        Count++;

        if (Current == Head) break;
    }
    return Count;
}

void PrintNode(Node* _Node) {
    if (_Node->PrevNode == NULL)
        printf("Prev: NULL");
    else 
        printf("Prev: %d", _Node->PrevNode->Data);

    printf(" Current: %d ", _Node->Data);

    if (_Node->NextNode == NULL)
        printf("Next: NULL\n");
    else
        printf("Next: %d\n", _Node->NextNode->Data);
}