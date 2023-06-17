#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

bool compareItems(const Item& item1, const Item& item2) {
    double valuePerWeight1 = static_cast<double>(item1.value) / item1.weight;
    double valuePerWeight2 = static_cast<double>(item2.value) / item2.weight;
    return valuePerWeight1 > valuePerWeight2;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (const Item& item : items) {
        if (remainingCapacity >= item.weight) {
            totalValue += item.value;
            remainingCapacity -= item.weight;
        } else {
            double fraction = static_cast<double>(remainingCapacity) / item.weight;
            totalValue += fraction * item.value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    cin >> n >> capacity;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }

    double maxValue = fractionalKnapsack(items, capacity);

    cout << "Maximum value: " << maxValue << endl;

    return 0;
}
