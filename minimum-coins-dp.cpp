#include<iostream>
using namespace std;

int min_coins_for_change(int* coins, int size, int sum){
    int** min_coins_array = new int*[size+1];
    for (int i=0; i < size+1; i++){
        min_coins_array[i] = new int[sum+1];
    }
    for (int columnIndex = 0; columnIndex < sum+1; columnIndex++){
        for (int rowIndex = 0; rowIndex < size+1; rowIndex++){
             if (columnIndex == 0){
                 min_coins_array[rowIndex][columnIndex] = 0;
             } else {
                 min_coins_array[rowIndex][columnIndex] = INT_MAX;
             }
         }
    }
    for (int i = 1; i <= size; i++){
        for (int tempSum = 1; tempSum <= sum; tempSum++){
            min_coins_array[i][tempSum] = min_coins_array[i-1][tempSum];
            if (min_coins_array[i][tempSum - coins[i-1]] != INT_MAX) {
                min_coins_array[i][tempSum] = min(min_coins_array[i][tempSum], 1 + min_coins_array[i][tempSum - coins[i-1]]);
            }
        }
    }
    return min_coins_array[size][sum];
};

int main(){
    int coins[] = {1,11,5,1};
    int size = sizeof coins/ sizeof (coins[0]);
    int sum = 11;
    cout << min_coins_for_change(coins, size, sum) << "/n";
    return 0;
};