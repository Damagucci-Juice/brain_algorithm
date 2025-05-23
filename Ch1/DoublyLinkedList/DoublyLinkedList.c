#include "DoublyLinkedList.h"

/* 노드 생성 */
Node* DLL_CreateNode(ElementType NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->PrevNode = NULL;

    return NewNode;
}

/* 노드 소멸 */
void DLL_DestoryNode(Node* Node) {
    free(Node);
}

/* 노드 추가 */
void DLL_AppendNode(Node** Head, Node* NewNode) {
    /* 헤드 노드가 NULL이라면 새로운 노드가 Head */
    if (*Head == NULL ) {
        *Head = NewNode;
    } else {
        /* 테일을 찾아 NewNode를 연결한다. */
        Node* Tail = (*Head);
        while (Tail->NextNode != NULL) {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
    }
}

/* 노드 삽입 */
void DLL_InsertAfter(Node* Current, Node* NewNode) {
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if (Current->NextNode != NULL) {
        Current->NextNode->PrevNode = NewNode;
    }
    Current->NextNode = NewNode;
}

/* 노드 제거 */
void DLL_RemoveNode(Node** Head, Node* Remove) {
    if (*Head == Remove) {
        *Head = Remove->NextNode;

        if (*Head != NULL) {
            (*Head)->PrevNode = NULL;
        }

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    } else {
        if (Remove->PrevNode != NULL) {
            Remove->PrevNode->NextNode = Remove->NextNode;
        }

        if (Remove->NextNode != NULL) {
            Remove->NextNode->PrevNode = Remove->PrevNode;
        }

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
}

/* 노드 탐색 */
Node* DLL_GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;
    while(Current != NULL && (--Location) >= 0) {
        Current = Current->NextNode;
    }
    return Current;
}

/* 노드 수 세기 */
int DLL_GetNodeCount(Node* Head) {
    unsigned int Count = 0;
    Node*        Current = Head;

    while (Current != NULL) {
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}

/* 역순으로 함수를 세기 */
void  PrintReverse(Node* Head) {
    Node* Tail = Head;
    int Count = 0;

    while(Tail != NULL && Tail->NextNode != NULL) {
        Tail = Tail->NextNode;
        Count++;
    }

    while(Tail != NULL) {
        printf("List[%d] : %d\n", Count--, Tail->Data);
        Tail = Tail->PrevNode;
    }
}