#include<iostream>
using namespace std;

int lis(int *arr, int size){
    int maxTillHere = 1;
    int* lis = new int[size];
    for (int i=0; i<size;i++){
        lis[i] = 1;
    }
    for (int i=0; i<size;i++){
        for(int j =0; j < i; j++){
            if (arr[j] < arr[i]){
                lis[i] = max(1 + lis[j], lis[i]);
                maxTillHere = max(maxTillHere, lis[i]);
            }
        }
    }
    return lis[size - 1];
};

int main() 
{ 
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Length of lis is %d\n", 
           lis( arr, n )); 
    return 0; 
} 