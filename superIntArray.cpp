#include "superIntArray.h"


SuperIntArray::SuperIntArray() : nums(nullptr), numberOfNums(0) {}

SuperIntArray::SuperIntArray(int arr[], int size) : numberOfNums(size) {
    nums = new int[size];
    for (int i = 0; i < size; i++) {
        nums[i] = arr[i];
    }
}

SuperIntArray::SuperIntArray(int num) : numberOfNums(1) {
    nums = new int[1];
    nums[0] = num;
}

SuperIntArray::SuperIntArray(vector<int> vec) : numberOfNums(vec.size()) {
    nums = new int[numberOfNums];
    for (int i = 0; i < numberOfNums; i++) {
        nums[i] = vec[i];
    }
}

SuperIntArray::SuperIntArray(const SuperIntArray& arr) : numberOfNums(arr.numberOfNums) {
    nums = new int[numberOfNums];
    for (int i = 0; i < numberOfNums; i++) {
        nums[i] = arr.nums[i];
    }
}

SuperIntArray::~SuperIntArray() {
    delete[] nums;
}

int* SuperIntArray::getNums() const {
    return nums;
}

int SuperIntArray::getSize() const {
    return numberOfNums;
}

void SuperIntArray::setNums(int arr[], int size) {
    delete[] nums;
    numberOfNums = size;
    nums = new int[size];
    for (int i = 0; i < size; i++) {
        nums[i] = arr[i];
    }
}

void SuperIntArray::add(int num) {
    int* temp = new int[numberOfNums + 1];
    for (int i = 0; i < numberOfNums; i++) {
        temp[i] = nums[i];
    }
    temp[numberOfNums] = num;
    delete[] nums;
    nums = temp;
    numberOfNums++;
}

int SuperIntArray::get(int index) const {
    return nums[index];
}

void SuperIntArray::change(int index, int value) {
    nums[index] = value;
}

SuperIntArray& SuperIntArray::operator=(const SuperIntArray& right) {
    if (this != &right) {
        delete[] nums;
        numberOfNums = right.numberOfNums;
        nums = new int[numberOfNums];
        for (int i = 0; i < numberOfNums; i++) {
            nums[i] = right.nums[i];
        }
    }
    return *this;
}

SuperIntArray SuperIntArray::operator+(const SuperIntArray& right) const {
    SuperIntArray result;
    result.numberOfNums = numberOfNums + right.numberOfNums;
    result.nums = new int[result.numberOfNums];
    for (int i = 0; i < numberOfNums; i++) {
        result.nums[i] = nums[i];
    }
    for (int i = 0; i < right.numberOfNums; i++) {
        result.nums[i + numberOfNums] = right.nums[i];
    }
    return result;
}

int& SuperIntArray::operator[](int index) {
    return nums[index];
}

ostream& operator<<(ostream& stream, const SuperIntArray& right) {
    stream << "[";
    for (int i = 0; i < right.numberOfNums; i++) {
        stream << right.nums[i];
        if (i < right.numberOfNums - 1) stream << ", ";
    }
    stream << "]";
    return stream;
}

int SuperIntArray::getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int SuperIntArray::getMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

double SuperIntArray::getMean(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}


