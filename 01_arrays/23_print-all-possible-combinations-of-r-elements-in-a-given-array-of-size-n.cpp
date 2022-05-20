// problem link : https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/

#include <iostream>
using namespace std;

void combinationUtil(int arr[], int n, int r, int idx, int data[], int i){

    if(idx == r){
        for(int j=0; j<r; j++){
            cout<<data[j]<<" ";
        }
        cout<<endl;
        return;
    }

    if(i >= n) return;

    // including the element
    data[idx] = arr[i];

    combinationUtil(arr, n, r, idx+1, data, i+1);

    // excluding
    combinationUtil(arr, n, r, idx, data, i+1);
}

void printCombination(int arr[], int n, int r){

    int data[r]; // output data

    combinationUtil(arr, n, r, 0, data, 0);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int r=3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n, r);
    return 0;
}