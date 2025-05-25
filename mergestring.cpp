#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void merge(vector<string>& names, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = names[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = names[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        string l = L[i];
        string r = R[j];
        transform(l.begin(), l.end(), l.begin(), ::tolower);
        transform(r.begin(), r.end(), r.begin(), ::tolower);

        if (l <= r) {
            names[k] = L[i];
            i++;
        } else {
            names[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        names[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        names[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<string>& names, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(names, left, mid);
        mergeSort(names, mid + 1, right);

        merge(names, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Enter number of names: ";
    cin >> n;
    cin.ignore(); // Clear the input buffer

    vector<string> student_names;
    cout << "Enter " << n << " names:\n";
    for (int i = 0; i < n; i++) {
        string name;
        getline(cin, name);
        student_names.push_back(name);
    }

    mergeSort(student_names, 0, student_names.size() - 1);

    cout << "\nSorted names:\n";
    for (const string& name : student_names) {
        cout << name << endl;
    }

    return 0;
}
