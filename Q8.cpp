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
T Smallestnum();
    bool SearchElement(T);
    float Average();

    ~Vector()
    {
        delete[] arr;
    }
};

template <class T>
T Vector<T>::Smallestnum()
{
    T a;
    a = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }

        else
        {
            if (a > arr[i + 1])
            {
                a = arr[i + 1];
            }
        }
    }

    return a;
}      
