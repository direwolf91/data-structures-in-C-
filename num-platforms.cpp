#include <iostream>
#include <algorithm>
using namespace std;

int numPlatforms(int arr[], int dep[], int size){
    sort(arr, arr+size);
    sort(dep, dep+size);
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;
    while (i < size && j < size){
        if (arr[i] <= dep[j]){
            plat_needed++;
            i++;
            if(plat_needed > result){
                result = plat_needed;
            }
        }else {
            plat_needed--;
            j++;
        }
    }
    return result;
}

int main() {
	//code
	int test_cases, size_array, *arr, *dept;
	cin >> test_cases;
	while(test_cases > 0){
	   cin >> size_array;
	   arr = new int[size_array];
	   dept = new int[size_array];
	   for (int i = 0; i < size_array; i++){
	       cin >> arr[i];
	   }
	   for (int j = 0; j < size_array; j++){
	       cin >> dept[j];
	   }
	   cout << numPlatforms(arr, dept, size_array);
	    delete arr;
	   delete dept;
	   test_cases--;
	}
	return 0;
}