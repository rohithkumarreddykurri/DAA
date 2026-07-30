#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Iterative Method
// Time Complexity : O(n)
// Space Complexity : O(1)
unsigned long long iterativeFact(int num)
{
    unsigned long long fact = 1;

    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }

    return fact;
}

// Recursive Method
// Time Complexity : O(n)
// Space Complexity : O(n)
unsigned long long recursiveFact(int num)
{
    if (num == 0 || num == 1)
        return 1;

    return num * recursiveFact(num - 1);
}

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (number < 0)
    {
        cout << "Please enter a non-negative number." << endl;
        return 0;
    }

    // Iterative Execution Time
    auto begin = high_resolution_clock::now();

    unsigned long long ans1 = iterativeFact(number);

    auto finish = high_resolution_clock::now();

    auto time1 = duration_cast<nanoseconds>(finish - begin);

    // Recursive Execution Time
    begin = high_resolution_clock::now();

    unsigned long long ans2 = recursiveFact(number);

    finish = high_resolution_clock::now();

    auto time2 = duration_cast<nanoseconds>(finish - begin);

    // Display Output
    cout << "\n===== Factorial Result =====" << endl;

    cout << "Iterative Factorial : " << ans1 << endl;
    cout << "Execution Time      : " << time1.count() << " ns" << endl;

    cout << "\nRecursive Factorial : " << ans2 << endl;
    cout << "Execution Time      : " << time2.count() << " ns" << endl;

    return 0;
}
