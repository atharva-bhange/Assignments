/*
Atharva Nitin Bhange SE A 08

Write a function template for selection sort that inputs, sorts and outputs an integer array and
a float array. 
*/

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

/*
Output 

Taking Integer array     
How many terms you want: 4
Enter number: 5
Enter number: 4
Enter number: 7
Enter number: 2
Sorted array is
2, 4, 5, 7
Taking Float array       
How many terms you want: 4
Enter number: 1.2
Enter number: 3.4
Enter number: 6.2
Enter number: 3.1
Sorted array is
1.2, 3.1, 3.4, 6.2
*/