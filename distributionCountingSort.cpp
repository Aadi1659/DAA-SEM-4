/*
Distribution Counting Sort sorts an array within a limited range within low and high values.
It creates a frequency array, then iterates it from right to left and accordingly places the elements in order

Eg:                 13 11 12 13 12 12
array ->            11 12 13  
frequencies->       1  3  2  
distribution values 1  4  6

Time complexity -> O(n)
*/


#include <bits/stdc++.h> 
using namespace std;

vector<int> distributionCountingSort(vector<int> myArray,int low, int high);
void displayArray(vector<int> myArray);

int main(){
    int numberOfElements,low,high;
    cout<<"Enter the number of elements : ";
    cin>>numberOfElements;

    vector<int> unsortedArray(numberOfElements);

    cout<<"Enter the low value : ";
    cin>>low;

    cout<<"Enter the high value : ";
    cin>>high;

    for (int i = 0; i < numberOfElements; i++){
        int a;
        cout<<"Enter the element number "<<i<<": ";
        cin>>unsortedArray[i];
    }

    vector<int> sortedArray = distributionCountingSort(unsortedArray,low,high);

    cout<<"Unsorted Array :";
    displayArray(unsortedArray);    
    
    cout<<"Sorted Array :";
    displayArray(sortedArray);    

}

vector<int> distributionCountingSort(vector<int> myArray, int low, int high){
    int size = myArray.size();
    vector<int> frequecyArray(high-low+1);
    vector<int> answerArray(size);
    for (int j = 0; j <= high-low; j++) frequecyArray[j] = 0;

    for (int i = 0; i < size; i++) frequecyArray[myArray[i]- low]++;

    for (int j = 1; j <= high-low; j++) frequecyArray[j] = frequecyArray[j-1] + frequecyArray[j];
    
    for (int i = size-1; i >= 0; i--)
    {
        int j = myArray[i] - low;
        answerArray[frequecyArray[j]-1] = myArray[i];
        frequecyArray[j]--;
    }
    return answerArray;
}

void displayArray(vector<int> myArray){
    for (int  i = 0; i < myArray.size(); i++) cout<<myArray[i]<<" -> ";
}
    



    