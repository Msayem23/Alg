#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Item {
    int value, weight;
    Item(int v = 0, int w = 0) : value(v), weight(w) {}
};

// Comparator function to sort items by value/weight ratio in descending order
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), cmp);

    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < items.size(); i++) {
        if (curWeight + items[i].weight <= capacity) {
            curWeight += items[i].weight;
            finalValue += items[i].value;
        } else {
            int remain = capacity - curWeight;
            finalValue += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int numItems, capacity;
    
    cout << "Enter number of items: ";
    cin >> numItems;
    
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<Item> items;
    for (int i = 0; i < numItems; i++) {
        int value, weight;
        cout << "Enter value and weight for item " << i+1 << ": ";
        cin >> value >> weight;
        items.push_back(Item(value, weight));
    }

    cout << "Maximum value in Knapsack = " 
         << fractionalKnapsack(items, capacity) << endl;

    return 0;
}