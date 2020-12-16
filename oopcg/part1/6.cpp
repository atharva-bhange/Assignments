/*
Atharva Nitin Bhange

SE A 08
Write C++ program using STL for sorting and searching user defined records such as personal
records (Name, DOB, Telephone number etc) using vector container.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Record
{
    string name;
    string DOB;
    long number;
};

bool NameCompare(Record n1, Record n2)
{
    return (n1.name < n2.name);
}

bool NumberCompare(Record n1, Record n2)
{
    return (n1.number < n2.number);
}

class Records
{
    vector<Record> list;

public:
    Records()
    {
        int n;
        cout << "How Many Record You want: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "----- Input Record " << i + 1 << " -----" << endl;
            Record r;
            cout << "Name: ";
            cin >> r.name;
            cout << "DOB: ";
            cin >> r.DOB;
            cout << "Telephone Number: ";
            cin >> r.number;
            list.push_back(r);
        }
    }

    bool SearchName(string key)
    {
        Record search_term;
        search_term.name = key;
        return binary_search(list.begin(), list.end(), search_term, NameCompare);
    }

    void Sort()
    {
        sort(list.begin(), list.end(), NumberCompare);
    }

    void display()
    {
        for (int i = 0; i < list.size(); i++)
        {
            cout << "----- Record " << i + 1 << " -----" << endl;
            cout << "Name: " << list[i].name << endl;
            cout << "DOB: " << list[i].DOB << endl;
            cout << "Telephone Number: " << list[i].number << endl;
        }
    }
};

int main()
{
    bool breakFlag = true;
    Records A;
    while (breakFlag)
    {
        cout << "----------Menu----------" << endl;
        cout << "1) Search Name" << endl;
        cout << "2) Sort Records" << endl;
        cout << "3) Display Records" << endl;
        cout << "4) End" << endl;
        int option;
        cout << "Choose a Option: ";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            string k;
            cout << "Search Name: ";
            cin >> k;
            if (A.SearchName(k))
                cout << "Record is present" << endl;
            else
                cout << "Record is not present" << endl;
            break;
        }
        case 2:
        {
            A.Sort();
            cout << "Records are sorted!" << endl;
            break;
        }
        case 3:
        {
            A.display();
            break;
        }
        case 4:
        {
            breakFlag = false;
            break;
        }
        default:
        {
            breakFlag = false;
            break;
        }
        }
    }
}

/*
Output

How Many Record You want: 3
----- Input Record 1 -----
Name: atharva
DOB: 19/01/2002
Telephone Number: 99
----- Input Record 2 -----
Name: sarvesh
DOB: 19/05/2009
Telephone Number: 66
----- Input Record 3 -----
Name: rahul
DOB: 03/4/2001
Telephone Number: 22
----------Menu----------
1) Search Name
2) Sort Records
3) Display Records      
4) End
Choose a Option: 1      
Search Name: sarvesh
Record is present       
----------Menu----------
1) Search Name
2) Sort Records
3) Display Records      
4) End
Choose a Option: 1      
Search Name: dummyname
Record is not present   
----------Menu----------
1) Search Name
2) Sort Records
3) Display Records      
4) End
Choose a Option: 2      
Records are sorted!
----------Menu----------
1) Search Name
2) Sort Records
3) Display Records
4) End
Choose a Option: 3
----- Record 1 -----
Name: rahul
DOB: 03/4/2001
Telephone Number: 22
----- Record 2 -----
Name: sarvesh
DOB: 19/05/2009
Telephone Number: 66
----- Record 3 -----
Name: atharva
DOB: 19/01/2002
Telephone Number: 99
----------Menu----------
1) Search Name
2) Sort Records
3) Display Records
4) End
Choose a Option: 4

*/