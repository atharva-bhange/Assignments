#include <iostream>
using namespace std;

template <class T>
class Sort
{
    T array[10];
    int n;

public:
    void read();
    void display();
    void SelectionSort();
};

template <class T>
void Sort<T>::read()
{
    cout << "How many terms you want: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter number: ";
        cin >> array[i];
    }
}

template <class T>
void Sort<T>::display()
{
    cout << "Sorted array is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i];
        if (i != n - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

template <class T>
void Sort<T>::SelectionSort()
{
    int minIndex;
    T temp;
    for (int i = 0; i < n; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

int main(void)
{
    cout << "Taking Integer array" << endl;
    Sort<int> intArray;
    intArray.read();
    intArray.SelectionSort();
    intArray.display();

    cout << "Taking Float array" << endl;
    Sort<float> floatArray;
    floatArray.read();
    floatArray.SelectionSort();
    floatArray.display();

    return 0;
}