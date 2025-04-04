#include "LinkedList.h"

/* 노드 생성 */
Node* SLL_CreateNode(ElementType newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = newData;
    newNode->next = NULL;

    return newNode;
}

/* 노드 소멸 */
void SLL_DestroyNode(Node* node) {
    free(node);
}

void SLL_AppendNode(Node** head, Node* newNode) {
    if ( *head == NULL ) {
        *head = newNode;
    } else {
        Node* tail = *head;
        while (tail->next != NULL) {
            tail = tail->next;
        }

        tail->next = newNode;
    }
}

void SLL_InsertAfter(Node* current, Node* newNode) {
    newNode->next = current->next;
    current->next = newNode;
}

void SLL_InsertNewHead(Node** head, Node* newHead) {
    if (*head == NULL) {
        *head = newHead;
    } else {
        newHead->next = *head;
        *head = newHead;
    }
}

void SLL_RemoveNode(Node** head, Node* remove) {
    if (*head == remove) {
        *head = remove->next;
    } else {
        Node* current = *head;
        while (current != NULL && current->next != remove) {
            current = current->next;
        }

        if (current != NULL) {
            current->next = remove->next;
        }
    }
}

Node* SLL_GetNodeAt(Node* head, int location) {
    Node* current = head;
    while (current != NULL && (--location >= 0)) {
        current = current->next;
    }

    return current;
}

int SLL_GetNodeCount(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        current = current->next;
        count++;
    }

    return count;
}

void printList(Node** list) {
    int count = SLL_GetNodeCount(*list);
    Node* current = NULL;
    for (int i = 0; i < count; i++) {
        current = SLL_GetNodeAt(*list, i);
        printf("List[%d]->%d\n", i, current->data);
    }
}

void  SLL_InsertBefore(Node** head, Node* current, Node* newHead) {
    if (*head == newHead) {
        SLL_InsertNewHead(head, newHead);
    } else {
        Node* pre = *head;

        while(pre != NULL && pre->next != current) {
            pre = pre->next;
        }
        pre->next = newHead;
        newHead->next = current;
    }
}

void  SLL_DestoryAllNodes(Node** list) {
    Node* current = *list;
    while(current != NULL) {
        SLL_RemoveNode(list, current);
        SLL_DestroyNode(current);
        current = SLL_GetNodeAt(*list, 0);
    }
}