#include<iostream>
using namespace std;

bool isSubsetSum(int *set, int size, int sum){
    bool** isSubsetArray = new bool*[size+1];
    for(int i = 0; i < size+1; ++i)
      isSubsetArray[i] = new bool[size + 1];
    int remainingSum = 0;
    for (int i=0; i<=size;i++){
        isSubsetArray[0][i] = false; 
    };
    for (int rowIndex=0; rowIndex<=size;rowIndex++){
        isSubsetArray[rowIndex][0] = true; // Since it is possible to get sum zero with any elements
    };
    for (int i = 1; i <= size; i++){
        for (int tempSum = 1; tempSum <= sum; tempSum++){
            if (set[i - 1] > tempSum){
                isSubsetArray[i][tempSum] = isSubsetArray[i-1][tempSum];
            }else {
                remainingSum = tempSum - set[i-1];
                isSubsetArray[i][tempSum] = isSubsetArray[i-1][tempSum] ? isSubsetArray[i-1][tempSum] : isSubsetArray[i-1][remainingSum];
            }
        };
    };
    return isSubsetArray[size][size];
}

int main(){
    int set[] = {3,34,4,12,5,2};
    int sum = 9;
    int size = sizeof set/ sizeof(set[0]);
    cout << isSubsetSum(set, size, sum) << "\n";
    return 0;
}