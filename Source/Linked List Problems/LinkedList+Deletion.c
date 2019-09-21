

//
//  LinkedList+Deletion.c
//  DataStructure
//
//  Created by raj on 14/09/19.
//  Copyright © 2019 test. All rights reserved.
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

Node* deleteItemFromFirstPosition(Node* head){
    if (head == NULL){
        return NULL;
    }
    
    printf("Delete item from list %d\n", head->data);
    Node *temp = head;
    head = head->next;
    free(temp);
    
    return head;
}

Node* deleteItemAt(int position, Node*head){
    if (head == NULL){
        return head;
    }
    
    Node *temp = head;
    Node *prev = head;
    int i = 1;
    while(temp->next != NULL && i < position){
        prev = temp;
        temp = temp->next;
        i++;
    }
    
    if (i < position){
        return head;
    }
    
    Node *nodeToDelete = temp;
    printf("Delete item from list = %d\n", temp->data);
    if (nodeToDelete == head){
        head = nodeToDelete->next;
    }
    prev->next = temp->next;
    free(nodeToDelete);
    
    return head;
}

Node * deleteItemAtLast(Node *head){
    Node *start = head;
    Node * prev = head;
    
    while(start->next != NULL){
        prev = start;
        start = start->next;
    }
    
    printf("Delete item from list is = %d\n", start->data);
    prev->next = NULL;
    free(start);
    
    return head;
}

int main (){
    Node *head = createLinkedList (10);
    head = deleteItemAt(2, head);
    printList(head);
}

