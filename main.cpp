#include "SuperIntArray.h"
#include "Time.h"



void assignmentTest() {
    Time t1(1, 2, 30, 45);
    Time t2;
    t2 = t1;
    cout << "Assignment Test: " << t2 << endl;
}

void testTimeAddition() {
    Time t1(0, 10, 30, 40);
    Time t2(0, 2, 45, 30);
    cout << "Addition: " << (t1 + t2) << endl;
}

void testTimeSubtraction() {
    Time t1(0, 10, 30, 40);
    Time t2(0, 2, 45, 30);
    cout << "Subtraction: " << (t1 - t2) << endl;
}

void testTimeRelationalOperators() {
    Time t1(0, 5, 0, 0), t2(0, 3, 0, 0);
    cout << (t1 > t2 ? "t1 > t2" : "t1 <= t2") << endl;
}

void testTimeOutStreamOperator() {
    Time t1(1, 12, 30, 15);
    cout << "Time: " << t1 << endl;
}

void testTimeIntegerConversion() {
    Time t1(1, 0, 0, 0);
    cout << "Total seconds: " << int(t1) << endl;
}

int main() {
    assignmentTest();
    testTimeAddition();
    testTimeSubtraction();
    testTimeRelationalOperators();
    testTimeOutStreamOperator();
    testTimeIntegerConversion();
    return 0;
} 




/*int main() {
    int arr[] = { 1, 2, 3 };
    SuperIntArray s1(arr, 3);
    s1.add(4);
    cout << "s1: " << s1 << endl;

    SuperIntArray s2(5);
    cout << "s2: " << s2 << endl;

    vector<int> vec = { 6, 7, 8 };
    SuperIntArray s3(vec);
    cout << "s3: " << s3 << endl;

    SuperIntArray s4 = s1 + s3;
    cout << "s4 (s1 + s3): " << s4 << endl;

    SuperIntArray s5;
    s5 = s2;
    cout << "s5 (assigned s2): " << s5 << endl;

    s5.change(0, 10);
    cout << "s5 after change: " << s5 << endl;

    cout << "s5[0]: " << s5[0] << endl;

    cout << "Max: " << SuperIntArray::getMax(arr, 3) << endl;
    cout << "Min: " << SuperIntArray::getMin(arr, 3) << endl;
    cout << "Mean: " << SuperIntArray::getMean(arr, 3) << endl;

    return 0;
}*/