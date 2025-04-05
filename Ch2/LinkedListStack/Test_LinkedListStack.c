#include "LinkedListStack.h"

int main(void) {
    int i = 0;
    int Count = 0;
    Node* Popped;

    LinkedListStack* Stack;
    LLS_CreateStack(&Stack);

    LLS_Push(Stack, LLS_CreateNode("ABC"));
    LLS_Push(Stack, LLS_CreateNode("DEF"));
    LLS_Push(Stack, LLS_CreateNode("EFG"));
    LLS_Push(Stack, LLS_CreateNode("HIJ"));

    Count = LLS_GetSize(Stack);
    printf("Size: %d, Top: %s\n\n",
                 Count, LLS_Top(Stack)->Data);
    
    for(i=0; i<Count; i++) {
        if (LLS_IsEmpty(Stack)) break;

        Popped = LLS_Pop(Stack);
        printf("Popped: %s, ", Popped->Data);
        LLS_DestoryNode(Popped);

        if(!LLS_IsEmpty(Stack)) {
            printf("CurrentTop: %s\n", LLS_Top(Stack)->Data);
        } else {
            printf("Stack Is Empty.\n");
        }
    }

    LLS_DestroyStack(Stack);
}