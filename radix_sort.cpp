#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void radixSort(vector<int>& arr, int n, bool descending = false) {
    
    int max_num = *max_element(arr.begin(), arr.end());
    
    
    for (int digit_place = 1; max_num/digit_place > 0; digit_place *= 10) {
        vector<vector<int>> buckets(10); 
        
        
        for (int i = 0; i < n; i++) {
            int digit = (arr[i]/digit_place) % 10;
            buckets[digit].push_back(arr[i]);
        }
        
       
        int index = 0;
        if (descending) {
            // For descending order: collect from bucket 9 down to 0
            for (int bucket = 9; bucket >= 0; bucket--) {
                for (int num : buckets[bucket]) {  
                    arr[index++] = num;
                }
            }
        } else {
            // For ascending order (default): collect from bucket 0 to 9
            for (int bucket = 0; bucket <= 9; bucket++) {
                for (int num : buckets[bucket]) {  
                    arr[index++] = num;
                }
            }
        }
    }
}

int main() {
    int n;
   
    cin >> n;
    
    vector<int> arr(n);
  
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
 
    
    // Sort in ascending order (default)
    radixSort(arr, n);
    cout << "After ascending sort: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    // Sort in descending order
    radixSort(arr, n, true);
    cout << "After descending sort: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}
