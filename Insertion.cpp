#include<bits/stdc++.h>

using namespace std;

void  insertion(int ar[], int n){
    for(int i=1; i<n; i++){ 
        int x = ar[i];
        int j = i-1;
        while(j>=0 && ar[j] >x){ //ar[j]<x
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = x;
    }

}
int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    insertion(ar,n);
    cout<<"Sorted Array is:"<<endl;
    for(int i=0; i<n; i++){
        cout<<ar[i]<<" ";
    }
    return 0;

}
//best O(n), avg O(n^2),O(n^2)
//space complexity: O(1)
