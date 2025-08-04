#ifndef SUPERINTARRAY_H
#define SUPERINTARRAY_H

#include <iostream>
#include <vector>
using namespace std;

class SuperIntArray {
private:
    int* nums;
    int numberOfNums;

public:
    SuperIntArray();
    SuperIntArray(int arr[], int size);
    SuperIntArray(int num);
    SuperIntArray(vector<int> vec);
    SuperIntArray(const SuperIntArray& arr);
    ~SuperIntArray();

    int* getNums() const;
    int getSize() const;
    void setNums(int arr[], int size);

    void add(int num);
    int get(int index) const;
    void change(int index, int value);

    SuperIntArray& operator=(const SuperIntArray& right);
    SuperIntArray operator+(const SuperIntArray& right) const;
    int& operator[](int index);

    friend ostream& operator<<(ostream& stream, const SuperIntArray& right);

    static int getMax(int arr[], int size);
    static int getMin(int arr[], int size);
    static double getMean(int arr[], int size);
};

#endif