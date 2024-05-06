#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

class Heap {
private:
    int arr[100]; // Size can be changed or made dynamic as per requirement
    int size;
    void heapify(int i, bool isMaxHeap) {
        int largestOrSmallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        // For Max Heap
        if (isMaxHeap) {
            if (left < size && arr[left] > arr[largestOrSmallest])
                largestOrSmallest = left;

            if (right < size && arr[right] > arr[largestOrSmallest])
                largestOrSmallest = right;
        }
        // For Min Heap
        else {
            if (left < size && arr[left] < arr[largestOrSmallest])
                largestOrSmallest = left;

            if (right < size && arr[right] < arr[largestOrSmallest])
                largestOrSmallest = right;
        }
        if (largestOrSmallest != i) {
            swap(arr[i], arr[largestOrSmallest]);
            heapify(largestOrSmallest, isMaxHeap);
        }
    }
    void buildHeap(bool isMaxHeap) {
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(i, isMaxHeap);
    }
public:
    Heap() : size(0) {}
    bool readFromFile(const string& fileName) {
        ifstream file(fileName);

        if (!file.is_open())
            return false;

        size = 0;
        while (file >> arr[size]) {
            size++;
            if (size >= 100) // Prevent overflow for demo purposes
                break;
        }
        file.close();
        return true;
    }
    void createMaxHeap() {
        buildHeap(true);
    }
    void convertToMinHeap() {
        buildHeap(false);
    }
    void printHeap() const {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Heap heap;
    if (!heap.readFromFile("C:\\Users\\USER-Q\\Desktop\\data.txt")) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    heap.createMaxHeap();
    cout << "Max Heap: ";

    heap.printHeap();

    heap.convertToMinHeap();
    cout << "Min Heap: ";

    heap.printHeap();
    return 0;
}