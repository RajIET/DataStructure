

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

int deleteItemFromFirstPosition(Node** head){
    if (*head == NULL){
        return INT_MAX;//Assumes INT_MAX is not part of list item.
    }
    
    Node *temp = *head;
    int itemToDelete = temp->data;
    *head = temp->next;
    free(temp);
    
    return itemToDelete;
}

int deleteItemAt(int position, Node**head){
    if (head == NULL){
        return INT_MAX;//Assumes INT_MAX is not part of list item.
    }
    
    Node *temp = *head;
    Node *prev = *head;
    int i = 1;
    while(temp->next != NULL && i < position){
        prev = temp;
        temp = temp->next;
        i++;
    }
    
    if (i < position){
        return INT_MAX;
    }
    
    Node *nodeToDelete = temp;
    int itemToDelete = temp->data;
    if (nodeToDelete == *head){
        *head = nodeToDelete->next;
    }
    prev->next = temp->next;
    free(nodeToDelete);
    
    return itemToDelete;
}

int deleteItemAtLast(Node **head){
    Node *start = *head;
    
    int itemToDelete = INT_MAX;
    
    if (start == NULL){
        return itemToDelete;
    }
    
    if (start->next == NULL){
        itemToDelete = start->data;
        free(start);
        *head = NULL;
        
        return itemToDelete;
    }
    
    Node *temp = *head;
    while(temp->next != NULL && temp->next->next != NULL){
        temp = temp->next;
    }
    
    itemToDelete = temp->next->data;
    free(temp->next);
    temp->next = NULL;
    
    return itemToDelete;
}

int main (){
    Node *head = createLinkedList (10);
    printf("Deleted item = %d\n", deleteItemAt(11, &head));
    
    printList(head);
}

