
//
//  UnionOfArrays.c
//  DataStructure
//
//  Created by raj on 14/09/19.
//  Copyright © 2019 test. All rights reserved.
//

#include "UnionOfArrays.h"

/**
 
 Union of two array is an array which contains one occurance of all elements of both arrays.
 
 Paramters:
 - 2 arrays of integers
 - Number of elements in both the arrays: Arrays to be sorted
 
 - Return: Union of arrays
 
 
 */

void printUnion(int arr1[], int arr2[], int m, int n){
    int i = 0, j = 0;
    
    while (i < m || j < n){
        if (arr1[i] < arr2[j]){
            printf("%d ", arr1[i++]);
        }else if (arr1[i] > arr2[j]){
            printf("%d ", arr2[j++]);
        }else{
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
    }
}
