//
//  NthElement.c
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

//Return the nth element in linked list
int getNthElement(int position, Node *head){
    Node *temp = head;
    int i = 1;
    while(temp->next != NULL && i < position){
        temp = temp->next;
        i++;
    }
    
    if (i < position){
        return INT_MAX;
    }
    
    return temp->data;
}


int main (){
    Node *head = createLinkedList (10);
    printList(head);
    printf("\nnth element of linked list = %d", getNthElement(3, head));
}


