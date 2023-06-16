#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//int main(int argc, const char * argv[]) {
//    printf("Hello, World!\n");
//    return 0;
//}


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void push (Node** head, int data) {                             //добавление элемента в бинарное дерево
    Node* tempNode = malloc(sizeof(Node));
    tempNode->data = data;
    tempNode->left = NULL;
    tempNode->right = NULL;
    
    if (*head == NULL) {
        *head = tempNode;
        return;
    }
    
    if ((*head)->data == data) return;
    
    Node* current = *head;
    
    for (int i = 0; ; i++) {
        
        if (data == current->data) return;
        
        if (data < current->data) {
            if (current->left == NULL) {
                current->left = tempNode;
                return;
            }
            current = current->left;
        }
        
        else if (data > current->data) {
             if (current->right == NULL) {
                 current->right = tempNode;
                 return;
             }
             current = current->right;
        }
    }
}
