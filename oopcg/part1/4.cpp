/*
Write a C++ program that creates an output file,
writes information to it, close the file, open it 
again as an input file and read the information from the file.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class student
{
public:
    char name[50];
    int roll_no;
    float marks;
    void get_data();
    void put_data();
};

void student::get_data()
{
    cout << "\n Enter the roll number => ";
    cin >> roll_no;
    cin.ignore();
    cout << "\n Enter the name   =>  ";
    cin.getline(name, 50);
    cout << "\n Enter the marks   =>  ";
    cin >> marks;
}

void student::put_data()
{
    cout << "\n-----------------------------------";
    cout << "\nName :    " << name;
    cout << "\nRoll No : " << roll_no;
    cout << "\nMarks   : " << marks;
    cout << "\n-----------------------------------";
}

int main()
{
    student s;
    fstream file;
    int n, i;
    file.open("student.txt", ios::out);
    cout << "Enter the total number of students";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        s.get_data();
        file.write((char *)&s, sizeof(s));
    }
    file.close();
    file.open("student.txt", ios::in);
    while (file.read((char *)&s, sizeof(s)))
        s.put_data();
    cout << "\n";
    file.close();
    return 0;
}