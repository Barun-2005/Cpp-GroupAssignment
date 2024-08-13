/*Design a class template by name Vector and perform the following: 
• Find the smallest of the element in the Vector. 
• Search for an element in the Vector. 
• Find the average of the element in the array.*/

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

template <class T>
bool Vector<T>::SearchElement(T ele)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            cout << "The element is found at " << i << "'th position" << endl;
            return true;
        }
    }
    cout << "Element Not found" << endl;
    return false;
};

template <class T>
float Vector<T>::Average()
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
};
//Main function
int main()
{
    Vector<float> List;
    List.setValue();
    cout << "Smallest number: " << List.Smallestnum() << endl;

    int num;
    cout << "Enter the element to search: ";
    cin >> num;

    List.SearchElement(num);

    cout << "Average: " << List.Average() << endl;
    return 0;
}

