//
//  NthElementFromLastInLinkedList.c
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
int getNthElementFromLast(int position, Node *head){
    Node *first = head;
    Node *second = head;
    int i = 1;
    while(first->next != NULL && i < position){
        first = first->next;
        i++;
    }
    
    while(first->next != NULL){
        second = second->next;
        first = first->next;
    }
    
    if (i < position){
        return INT_MAX;
    }
    
    return second->data;
}


int main (){
    Node *head = createLinkedList (10);
    printList(head);
    printf("\nnth element from last = %d", getNthElementFromLast(3, head));
}



