//
//  CountOccurances.c
//  
//
//  Created by Raj Aggrawal on 9/21/19.
//

/*
 
 Write a function that counts the number of times a given int occurs in a Linked List
 
 */

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
int countOccurance(int item, Node *head){
    Node *temp = head;
    int count = 0;
    while(temp->next != NULL){
        if (temp->data == item){
            count++;
        }
        
        temp = temp->next;
    }
    
    return count;
}


int main (){
    Node *head = createLinkedList (11);
    printList(head);
    printf("\ncount the occurance of element = %d", countOccurance(15, head));
}


