#include "LinkedList.h"

int main(void) {
    int i = 0;
    int count = 0;
    Node* list = NULL;
    Node* current = NULL;
    Node* newNode = NULL;

    /* add 5 nodes*/
    for (i = 0; i < 5; i++) {
        newNode = SLL_CreateNode(i);
        SLL_AppendNode(&list, newNode);
    }

    newNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&list, newNode);

    newNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&list, newNode);

    printList(&list);

    /* insert node at 2 */
    printf("\nInserting 3000 After [2]...\n\n");

    current = SLL_GetNodeAt(list, 2);
    newNode = SLL_CreateNode(3000);
    SLL_InsertAfter(current, newNode);
    newNode = SLL_CreateNode(1000);
    SLL_InsertBefore(&list, current, newNode);

    printList(&list);
    count = SLL_GetNodeCount(list);
    /* 모든 노드를 메모리에서 제거 */
    printf("\n모든 노드를 메모리에서 제거...\n");

    SLL_DestoryAllNodes(&list);
    printList(&list);

    return 0;
}