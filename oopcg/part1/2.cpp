/*
Atharva Nitin Bhange 
SE A 08

Develop a program in C++ to create a database of student’s information system containing the
following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact
address, Telephone number, Driving license no. and other. Construct the database with
suitable member functions. Make use of constructor, default constructor, copy constructor,
destructor, static member functions, friend class, this pointer, inline code and dynamic
memory allocation operators-new and delete as well as exception handling.
*/

#include <iostream>
#include <string>
using namespace std;

class PersonClass
{
private:
    string name, clas, div, dob, bloodgrp;
    int rol;

public:
    static int count;
    friend class PersonnelClass;
    PersonClass()
    {
        name = "";
        clas = "";
        div = "";
        dob = "";
        bloodgrp = "";
        rol = 0;
    }
    static void TotalRecordCount()
    {
        cout << "\nTotal Number Of Records: " << count << endl;
    }
};

class PersonnelClass
{
private:
    string address, telephone_no, policy_no, license_no;

public:
    PersonnelClass()
    {
        address = "";
        telephone_no = "";
        policy_no = "";
        license_no = "";
    }
    void InputData(PersonClass *obj);
    void DisplayData(PersonClass *obj);
    friend class PersonClass;
};

int PersonClass::count = 0;

void PersonnelClass::DisplayData(PersonClass *obj)
{
    cout << "Roll No : ";
    cout << obj->rol << endl;
    cout << "Name : ";
    cout << obj->name << endl;
    cout << "Class : ";
    cout << obj->clas << endl;
    cout << "Division : ";
    cout << obj->div << endl;
    cout << "Date Of Birth : ";
    cout << obj->dob << endl;
    cout << "Blood Group : ";
    cout << obj->bloodgrp << endl;
    cout << "Address : ";
    cout << this->address << endl;
    cout << "Telephone Number : ";
    cout << this->telephone_no << endl;
    cout << "Driving License Number : ";
    cout << this->license_no << endl;
    cout << "Policy Number : ";
    cout << this->policy_no << endl;
}

void PersonnelClass::InputData(PersonClass *obj)
{
    cout << "Roll No : ";
    cin >> obj->rol;
    cout << "Name : ";
    cin >> obj->name;
    cout << "Class : ";
    cin >> obj->clas;
    cout << "Division : ";
    cin >> obj->div;
    cout << "Date Of Birth : ";
    cin >> obj->dob;
    cout << "Blood Group : ";
    cin >> obj->bloodgrp;
    cout << "Address : ";
    cin >> this->address;
    cout << "Telephone Number : ";
    cin >> this->telephone_no;
    cout << "Driving License Number : ";
    cin >> this->license_no;
    cout << "Policy Number : ";
    cin >> this->policy_no;
    obj->count++;
}

int main(void)
{
    PersonnelClass *a[10];
    PersonClass *c[10];
    int n = 0, choice;
    char ans;
    do
    {
        cout << "Menu" << endl;
        cout << "1) Input Data\n"
             << "2) Display Data\n"
             << "Enter Your Choice";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "------Enter Detail------" << endl;
            do
            {
                a[n] = new PersonnelClass;
                c[n] = new PersonClass;
                a[n]->InputData(c[n]);
                n++;
                PersonClass::TotalRecordCount();
                cout << "\nDo you want to add more records(y/n)? ";
                cin >> ans;
            } while (ans == 'y' || ans == 'Y');
            break;
        case 2:
            cout << "\n-------Displaying Data--------" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "\tRecord " << i + 1 << endl;
                a[i]->DisplayData(c[i]);
            }
            break;
        default:
            break;
        }
        cout << "\nDo you want to go to main menu(y/n)? ";
        cin >> ans;
        cin.ignore(1, '\n');
    } while (ans == 'y' || ans == 'Y');
    return 0;
}

/*
Output

Menu
1) Input Data    
2) Display Data  
Enter Your Choice1
------Enter Detail------
Roll No : 12
Name : Atharva
Class : 12
Division : A
Date Of Birth : 12/01/2002
Blood Group : A+
Address : --
Telephone Number : 11
Driving License Number : 33
Policy Number : 44

Total Number Of Records: 1

Do you want to add more records(y/n)? y
Roll No : 34
Name : Rohan
Class : 8
Division : B
Date Of Birth : 23/01/2001
Blood Group : B+
Address : --
Telephone Number : 44
Driving License Number : 33
Policy Number : 22

Total Number Of Records: 2

Do you want to add more records(y/n)? n

Do you want to go to main menu(y/n)? y
Menu
1) Input Data
2) Display Data
Enter Your Choice2

-------Displaying Data--------
        Record 1
Roll No : 12
Name : Atharva
Class : 12
Division : A
Date Of Birth : 12/01/2002
Blood Group : A+
Address : --
Telephone Number : 11
Driving License Number : 33
Policy Number : 44
        Record 2
Roll No : 34
Name : Rohan
Class : 8
Division : B
Date Of Birth : 23/01/2001
Blood Group : B+
Address : --
Telephone Number : 44
Driving License Number : 33
Policy Number : 22

Do you want to go to main menu(y/n)? n
*/