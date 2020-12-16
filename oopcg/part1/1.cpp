/*
Atharva Nitin Bhange SE A 08
Implement a class Complex which represents the Complex Number data type. Implement the
following
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overload operator+ to add two complex numbers.
3. Overload operator* to multiply two complex numbers.
4. Overload operators << and >> to print and read Complex Numbers. 
*/

#include <iostream>
#include <string>
using namespace std;

class Complex
{
private:
    int i;
    int r;

public:
    Complex()
    {
        r = 0;
        i = 0;
    }

    Complex operator+(const Complex &secondNumber)
    {
        Complex ans;
        ans.i = i + secondNumber.i;
        ans.r = r + secondNumber.r;
        return ans;
    }
    Complex operator*(const Complex &secondNumber)
    {
        Complex ans;
        ans.r = (r * secondNumber.r) - (i * secondNumber.i);
        ans.i = (r * secondNumber.i) + (secondNumber.r * i);
        return ans;
    }
    friend ostream &operator<<(ostream &out, const Complex &c)
    {
        out << c.r;
        if (c.i > 0)
            out << " + " << c.i << "i" << endl;
        else
            out << " - " << c.i * -1 << "i" << endl;
        return out;
    }
    friend istream &operator>>(istream &in, Complex &c)
    {
        cout << "Real Part: ";
        in >> c.r;
        cout << "Imaginary Part: ";
        in >> c.i;
        return in;
    }
};

int main()
{
    Complex n1;
    Complex n2;
    cin >> n1;
    cin >> n2;
    Complex multiplication = n1 * n2;
    Complex addition = n1 + n2;
    cout << multiplication;
    cout << addition;
    return 0;
}

/*
Output

Real Part: 1
Imaginary Part: 2
Real Part: 3
Imaginary Part: 4
-5 + 10i
4 + 6i
*/