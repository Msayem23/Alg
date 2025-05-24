#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
        //asscending
            if(arr[j]>arr[j+1]){ //for descending arr[j]<arr[j+1]
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
       
    }
    cout<<"Sorted array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
//time complexit best O(n), worst O(n^2), average O(n^2)
//space complexity O(1)