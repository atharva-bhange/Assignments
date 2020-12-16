/*

Atharva Nitin Bhange 
SE A 08

Imagine a publishing company which does marketing for book and audio cassette versions.
Create a class publication that stores the title (a string) and price (type float) of publications.
From this class derive two classes: book which adds a page count (type int) and tape which
adds a playing time in minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter data and
displays the data members. If an exception is caught, replace all the data member values with
zero values.

*/

#include <iostream>
#include <string>
using namespace std;

class publications
{
protected:
    string title;
    float price;
    void input()
    {
        cout << "What is the title: ";
        cin >> title;
        cout << "What is the price: ";
        cin >> price;
    }
    void display()
    {
        cout << "Title : " << title << endl;
        cout << "Price : " << price << endl;
    }
};

class book : public publications
{
    int pageCount;

public:
    book()
    {
        title = "";
        price = 0.0;
        pageCount = 0;
    }
    void input()
    {
        cout << "-----Input for Book-----" << endl;
        ;
        publications::input();
        cout << "What is the page count: ";
        cin >> pageCount;
    }
    void display()
    {
        cout << "-----Book-----" << endl;
        publications::display();
        cout << "Page count : " << pageCount << endl;
    }
};

class tape : public publications
{
    float playingTime;

public:
    tape()
    {
        title = "";
        price = 0.0;
        playingTime = 0.0;
    }
    void input()
    {
        cout << "-----Input for Tape-----" << endl;
        ;
        publications::input();
        cout << "What is the playtime: ";
        cin >> playingTime;
    }
    void display()
    {
        cout << "-----Tape-----" << endl;
        publications::display();
        cout << "Play time : " << playingTime << endl;
    }
};

int main(void)
{
    tape t;
    book b;

    t.input();
    b.input();

    t.display();
    b.display();

    return 0;
}

/*
Output

-----Input for Tape-----
What is the title: ABC  
What is the price: 12.54
What is the playtime: 4.5
-----Input for Book-----
What is the title: EFG  
What is the price: 33.4
What is the page count: 5
-----Tape-----
Title : ABC
Price : 12.54
Play time : 4.5
-----Book-----
Title : EFG
Price : 33.4
Page count : 5
*/