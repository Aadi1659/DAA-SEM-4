/*
Comparision sort uses the technique of creating one array called count, which will contain the number of elements smaller than the specified ith postion element, and then replaces the elements with their respective count array element.

Eg:             5 6 3 1 2
count array ->  3 4 2 0 1  
sorted array->  1 2 3 6 5 --> placed according to count array values

Time complexity -> O(n^2)
*/


#include <bits/stdc++.h> 
using namespace std;

vector<int> comparisionSort(vector<int> myArray);
void displayArray(vector<int> myArray);

int main(){
    int numberOfElements;
    cout<<"Enter the number of elements : ";
    cin>>numberOfElements;

    vector<int> unsortedArray(numberOfElements);

    for (int i = 0; i < numberOfElements; i++){
        int a;
        cout<<"Enter the element number "<<i<<": ";
        cin>>unsortedArray[i];
    }

    vector<int> sortedArray = comparisionSort(unsortedArray);

    cout<<"Unsorted Array :";
    displayArray(unsortedArray);    
    
    cout<<"Sorted Array :";
    displayArray(sortedArray);    

}

vector<int> comparisionSort(vector<int> myArray){
    int size = myArray.size();
    vector<int> answer(size);
    vector<int> count(size);
    for (int i = 0; i < size; i++) count[i] = 0;

    for (int i = 0; i < size-1; i++){
        for (int j = i+1; j < size; j++)
        {
            if(myArray[j]>myArray[i]) count[j]++;
            else count[i] ++;
        }
    }

    for (int i = 0; i < size; i++) answer[count[i]] = myArray[i];
    
    return answer;
}

void displayArray(vector<int> myArray){
    for (int  i = 0; i < myArray.size(); i++) cout<<myArray[i]<<" -> ";
}
    



    