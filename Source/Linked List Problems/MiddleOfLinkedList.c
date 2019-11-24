//
//  MiddleOfLinkedList.c
//  
//
//  Created by Raj Aggrawal on 9/21/19.
//

/*
 Method 1:
 Step 1: Count number of elements of linked list
 Step 2: Traverse the count / 2 th element
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

//Optimum solution

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
int midOfLinkedList(Node *head){
    Node *slow = head;
    Node *fast = head;
    if (head != NULL){
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    
    return slow->data;
}


int main (){
    Node *head = createLinkedList (11);
    printList(head);
    printf("\nmiddle element from last = %d", midOfLinkedList(head));
}


