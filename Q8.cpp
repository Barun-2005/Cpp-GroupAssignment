#include <iostream>

using namespace std;

template <class T>
class Vector
{
private:
    int n;
    T *arr;

public:
    void setValue(void)
    {
        cout << "Enter the number of elements present in the array" << endl;
        cin >> n;
        arr = new T[n];
        cout << "Enter the elements of the array:" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
