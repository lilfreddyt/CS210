#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

bool isSorted(const vector<int>& values) {
    for (int i = 0; i < values.size() - 1; i++) {
        if (values[i] > values[i + 1]) {
            return false;
        }
    }
    return true;
}

void bubbleSort(vector<int>& values) {
    for (int i = 0; i < values.size() - 1; i++) {
        for (int j = 0; j < values.size() - 1 - i; j++) {
            if (values[j] > values[j + 1]) {
                swap(values[j], values[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int>& values) {
    for (int i = 0; i < values.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < values.size(); j++) {
            if (values[min] > values[j]) {
                min = j;
            }
        }
        swap(values[i], values[min]);
    }
}

void insertionSort(vector<int>& values) {
    for (int i = 1; i < values.size(); i++) {
        int key = values[i];
        int j = i - 1;

        while (j >= 0 && values[j] > key) {
            values[j + 1] = values[j];
            j--;
        }

        values[j + 1] = key;
    }

}

int partition(vector<int>& values, int low, int high) {
    int pivot = values[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (values[j] <= pivot) {
            i++;
            swap(values[i], values[j]);
        }
    }

    swap(values[i + 1], values[high]);

    return i + 1;
}

void quickSort(vector<int>& values, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(values, low, high);

        quickSort(values, low, pivotIndex - 1);
        quickSort(values, pivotIndex + 1, high);
    }
}

void testSort(vector<int> original, string sortName, int runs) {
    double totalTime = 0;

    for (int i = 0; i < runs; i++) {

        // Make a fresh copy every time
        vector<int> values = original;

        auto start = chrono::high_resolution_clock::now();

        if (sortName == "Bubble") {
            bubbleSort(values);
        }
        else if (sortName == "Selection") {
            selectionSort(values);
        }
        else if (sortName == "Insertion") {
            insertionSort(values);
        }
        else if (sortName == "Quick") {
            quickSort(values, 0, values.size() - 1);
        }

        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> elapsed = end - start;

        totalTime += elapsed.count();

        if (!isSorted(values)) {
            cout << sortName << " failed!" << endl;
            return;
        }
    }

    double averageTime = totalTime / runs;

    cout << sortName
         << ": " << averageTime
         << " ms average" << endl;
}

void runTests(int size) {
    vector<int> randomValues;
    vector<int> sortedValues;
    vector<int> reverseValues;

    for (int i = 0; i < size; i++) {
        randomValues.push_back(rand() % 100);
    }

    for (int i = 0; i < size; i++) {
        sortedValues.push_back(i);
    }

    for (int i = size - 1; i >= 0; i--) {
        reverseValues.push_back(i);
    }

    cout << "\nSize of vector: " << size << endl;

    cout << "\nRandom:" << endl;
    testSort(randomValues, "Bubble", 5);
    testSort(randomValues, "Selection", 5);
    testSort(randomValues, "Insertion", 5);
    testSort(randomValues, "Quick", 5);

    cout << "\nSorted:" << endl;
    testSort(sortedValues, "Bubble", 5);
    testSort(sortedValues, "Selection", 5);
    testSort(sortedValues, "Insertion", 5);
    testSort(sortedValues, "Quick", 5);

    cout << "\nReverse Sorted:" << endl;
    testSort(reverseValues, "Bubble", 5);
    testSort(reverseValues, "Selection", 5);
    testSort(reverseValues, "Insertion", 5);
    testSort(reverseValues, "Quick", 5);
}

int main() {
    runTests(500);
    runTests(1000);
    runTests(2000);

    return 0;
}