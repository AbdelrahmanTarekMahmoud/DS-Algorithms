#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class MaxHeap {
private:
    // Vector to store heap elements
    std::vector<int> heap;

    // Helper function to get the index of the parent of a node
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Helper function to get the index of the left child of a node
    int leftChild(int i) {
        return 2 * i + 1;
    }

    // Helper function to get the index of the right child of a node
    int rightChild(int i) {
        return 2 * i + 2;
    }

    // Function to maintain the max heap property by moving the node up
    // Time complexity: O(log n)
    void siftUp(int i) {
        // Continue while the node is not the root and its parent is less than the node
        while (i > 0 && heap[parent(i)] < heap[i]) {
            // Swap the node with its parent
            std::swap(heap[i], heap[parent(i)]);
            // Move up to the parent index
            i = parent(i);
        }
    }

    // Function to maintain the max heap property by moving the node down
    // Time complexity: O(log n)
    void siftDown(int i) {
        int maxIndex = i;

        // Get the left child index
        int l = leftChild(i);
        // If the left child exists and is greater than the current max, update maxIndex
        if (l < heap.size() && heap[l] > heap[maxIndex]) {
            maxIndex = l;
        }

        // Get the right child index
        int r = rightChild(i);
        // If the right child exists and is greater than the current max, update maxIndex
        if (r < heap.size() && heap[r] > heap[maxIndex]) {
            maxIndex = r;
        }

        // If the current node is not the largest, swap with the largest child and continue
        if (i != maxIndex) {
            std::swap(heap[i], heap[maxIndex]);
            siftDown(maxIndex);
        }
    }

public:
    // Constructor
    MaxHeap() {}

    // Constructor to build a heap from an unsorted array
    // Time complexity: O(n)
    MaxHeap(const std::vector<int>& array) {
        heap = array;
        heapify();
    }

    // Insert a new element into the heap
    // Time complexity: O(log n)
    void insert(int key) {
        // Add the new element to the end of the heap
        heap.push_back(key);
        // Restore the heap property by sifting the new element up
        siftUp(heap.size() - 1);
    }

    // Extract the maximum element from the heap
    // Time complexity: O(log n)
    int extractMax() {
        if (heap.size() == 0) {
            throw std::out_of_range("Heap is empty");
        }

        // The root of the heap is the maximum element
        int result = heap[0];
        // Replace the root with the last element in the heap
        heap[0] = heap[heap.size() - 1];
        // Remove the last element
        heap.pop_back();
        // Restore the heap property by sifting the new root down
        siftDown(0);
        // Return the maximum element
        return result;
    }

    // Get the maximum element from the heap
    // Time complexity: O(1)
    int getMax() {
        if (heap.size() == 0) {
            throw std::out_of_range("Heap is empty");
        }
        // The root of the heap is the maximum element
        return heap[0];
    }

    // Check if the heap is empty
    // Time complexity: O(1)
    bool isEmpty() {
        // Return true if the heap size is 0, otherwise false
        return heap.size() == 0;
    }

    // Get the size of the heap
    // Time complexity: O(1)
    int getSize() {
        // Return the size of the heap
        return heap.size();
    }

    // Delete an element by its value
    // Time complexity: O(n)
    void deleteValue(int value) {
        // Find the index of the value to be deleted
        int index = -1;
        for (int i = 0; i < heap.size(); ++i) {
            if (heap[i] == value) {
                index = i;
                break;
            }
        }

        // If the value is not found, throw an exception
        if (index == -1) {
            throw std::invalid_argument("Value not found in heap");
        }

        // Delete the element at the found index
        deleteIndex(index);
    }

    // Delete an element by its index
    // Time complexity: O(log n)
    void deleteIndex(int index) {
        if (index < 0 || index >= heap.size()) {
            throw std::out_of_range("Index out of range");
        }

        // Replace the element at the index with the last element in the heap
        heap[index] = heap[heap.size() - 1];
        // Remove the last element
        heap.pop_back();
        
        // If the index is within the current size, restore the heap property
        if (index < heap.size()) {
            siftDown(index); // First try to sift down
            siftUp(index);   // Then try to sift up
        }
    }

    // Convert an arbitrary array into a heap
    // Time complexity: O(n)
    void heapify() {
        // Start from the last non-leaf node and apply siftDown to each node
        for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
            siftDown(i);
        }
    }

    // Heap sort function
    // Time complexity: O(n log n)
    static std::vector<int> heapSort(std::vector<int> array) {
        MaxHeap maxHeap(array);  // Create a max heap from the array
        std::vector<int> sortedArray;

        // Repeatedly extract the maximum element and add it to the sorted array
        while (!maxHeap.isEmpty()) {
            sortedArray.push_back(maxHeap.extractMax());
        }

        // Since we extracted the elements in descending order, reverse the array to get ascending order
        std::reverse(sortedArray.begin(), sortedArray.end());
        return sortedArray;
    }

    // Print the heap (for debugging purposes)
    // Time complexity: O(n)
    void printHeap() {
        for (int i : heap) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap maxHeap;

    // Insert elements into the heap
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(7);
    maxHeap.insert(40);

    // Get and print the maximum element
    std::cout << "Max element: " << maxHeap.getMax() << std::endl;

    // Extract and print the maximum element
    std::cout << "Extracting max element: " << maxHeap.extractMax() << std::endl;
    std::cout << "Max element after extraction: " << maxHeap.getMax() << std::endl;

    // Insert more elements into the heap
    maxHeap.insert(15);
    maxHeap.insert(30);

    // Delete an element by its value
    std::cout << "Deleting element 15" << std::endl;
    maxHeap.deleteValue(15);
    std::cout << "Max element after deletion: " << maxHeap.getMax() << std::endl;

    // Create a heap from an unsorted array
    std::vector<int> unsortedArray = {3, 1, 6, 5, 2, 4};
    MaxHeap arrayHeap(unsortedArray);
    std::cout << "Heap created from array: ";
    arrayHeap.printHeap();

    // Perform heap sort on an unsorted array
    std::vector<int> arrayToSort = {3, 1, 6, 5, 2, 4};
    std::vector<int> sortedArray = MaxHeap::heapSort(arrayToSort);
    std::cout << "Array after heap sort: ";
    for (int num : sortedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
