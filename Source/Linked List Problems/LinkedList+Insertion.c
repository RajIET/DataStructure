

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

Node* insertItemAtFirst(int item, Node* head){
    Node *temp = head;
    Node *newNode = (Node *) malloc (sizeof (Node));
    newNode->data  = item;
    
    newNode->next = temp;
    head = newNode;
}

Node *insertItemAt(int position, int item, Node*head){
    Node *temp = head;
    int i = 0;
    
    Node *newNode = (Node *) malloc (sizeof (Node));
    newNode->data  = item;
    
    if (i == 0){
        newNode->next = temp;
        head = newNode;
        
        return head;
    }
    
    while(temp->next != NULL && i < position - 1){
        temp = temp->next;
        i++;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    
    return head;
}

Node *insertItemAtLast(int item, Node *head){
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    Node *newNode = (Node *) malloc (sizeof (Node));
    newNode->data  = item;
    
    temp->next = newNode;
    newNode->next = NULL;
    
    return head;
}

int main (){
    Node *head = createLinkedList (10);
    head = insertItemAtFirst(100, head);
    head = insertItemAtLast(120, head);
    head = insertItemAt(0, 105, head);
    printList (head);
}

