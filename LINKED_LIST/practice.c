#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next=NULL;
}
void display(struct Node* head){
    struct Node* temp = head;  
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}
struct Node* insertatbeginning(struct Node* head,int data){
    struct Node* newnode = createNode(data);
    newnode->next=head;
}
int main() {
    struct Node* head = NULL;

    // Insertion operations
    insertatbeginning(head, 10);
    insertatbeginning(head, 20);
    insertatbeginning(head, 30);
    display(head);

    return 0;
}