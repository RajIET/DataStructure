
//
//  CreateLinkedList.c
//  DataStructure
//
//  Created by raj on 14/09/19.
//  Copyright © 2019 test. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
} typedef Node;

void printList (Node * head){
    Node *temp = head;
    while (temp != NULL)
    {
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

int main (){
    Node *head = createLinkedList (10);
    printList (head);
}

