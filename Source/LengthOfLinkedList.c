//
//  LengthOfLinkedList.c
//  
//
//  Created by Raj Aggrawal on 9/21/19.
//


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
    int data;
    struct Node *next;
} typedef Node;

void printList (Node * head){
    Node *temp = head;
    printf("Items in list is ");
    
    while (temp != NULL){
        printf ("%d ", temp->data);
        temp = temp->next;
    }
}

Node *createLinkedList (int numberOfNodes){
    Node *head = NULL;
    Node *currentNode = NULL;
    
    for (int i = 0; i < numberOfNodes; i++){
        Node *temp = (Node *) malloc (sizeof (Node));
        temp->data = i;
        if (head == NULL){
            head = temp;
            currentNode = temp;
        }
        else{
            currentNode->next = temp;
            currentNode = temp;
        }
    }
    
    return head;
}

//Find the length of linked list using iterative method
int lengthOfLinkedListIterativeMethod(Node *head){
    Node *temp = head;
    int length = 1;
    
    while(temp->next != NULL){
        length++;
        
        temp = temp->next;
    }
    
    return length;
}

//Find the length of linked list using recursive method
int lengthOfLinkedListRecursiveMethod(Node *head){
    if(head == NULL){
        return 0;
    }else{
        return lengthOfLinkedListRecursiveMethod(head->next) + 1;
    }
    
}


int main (){
    Node *head = createLinkedList (10);
    
    printf("length of linked list = %d", lengthOfLinkedListRecursiveMethod(head));
}



