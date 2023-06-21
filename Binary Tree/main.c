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

void pop(Node** head, int data) {                               //удаление эелемента из бинарного дерева
    if (*head == NULL) return;
    
    if ((*head)->data == data) {
        if ((*head)->left == NULL && (*head)->right == NULL) {
            *head = NULL;
            return;
        }
        if ((*head)->left != NULL && (*head)->right == NULL) {
            Node* delNode = *head;
            *head = (*head)->left;
            free(delNode);
            return;
        }
        if ((*head)->right != NULL && (*head)->left == NULL) {
            Node* delNode = *head;
            *head = (*head)->right;
            free(delNode);
            return;
        }
        if ((*head)->left != NULL && (*head)->right != NULL) {
            Node* temp = (*head)->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            (*head)->data = temp->data;
            pop(&(*head)->right, temp->data);
            return;
        }
    }
    
    else if (data < (*head)->data)
        pop(&(*head)->left, data);
    else
        pop(&(*head)->right, data);
}

void outputDepth (Node** head) {                                  //обход в глубину
    if (*head == NULL) return;
    
    printf("%d", (*head)->data);
    outputDepth(&(*head)->left);
    outputDepth(&(*head)->right);
}


void outputWidth (Node** head) {                                  //обход в ширину
    if (*head == NULL) return;

    Node** queue = malloc(sizeof(Node*) * 100);
    int start = 0, end = 0;
    queue[end++] = *head;
    while (start != end) {
        Node* current = queue[start++];
        printf("%d ", current->data);
        if (current->left != NULL) queue[end++] = current->left;
        if (current->right != NULL) queue[end++] = current->right;
    }
    free(queue);
}

void backOutput(Node** Head) {                                    //обратный обход
    if (*Head == NULL) return;

    backOutput(&(*Head)->left);
    backOutput(&(*Head)->right);
    printf("%d ", (*Head)->data);
}
