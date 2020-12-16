/*
Atharva Nitin Bhange SE A 08

Write a program in C++ to use map associative container. The keys will be the names of states
and the values will be the populations of the states. When the program runs, the user is
prompted to type the name of a state. The program then looks in the map, using the state
name as an index and returns the population of the state. 
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int GetPopulation(map<string, long> &ind, string key)
{
    int population = 0;
    population = ind[key];

    return population;
}

int main(void)
{
    map<string, long> India;
    // Adding to Map
    India["Maharashtra"] = 112374333;
    India["Gujarat"] = 60439692;
    India["Bihar"] = 104099452;
    India["Rajasthan"] = 68548437;
    India["Karnataka"] = 61095297;
    cout << "Type 'break' to exit the program." << endl;
    while (true)
    {
        string option;
        cout << "Which states population you want: ";
        cin >> option;
        if (option == "break")
            break;
        int ans = GetPopulation(India, option);
        if (ans == 0)
            cout << "State Name Does not Exist in Map" << endl;
        else
            cout << "The population of state " << option << " is " << ans << endl;
    }

    return 0;
}

/*
Output

Type 'break' to exit the program. 
Which states population you want: Bihar
The population of state Bihar is 104099452
Which states population you want: Karnataka
The population of state Karnataka is 61095297
Which states population you want: Maharashtra
The population of state Maharashtra is 112374333
Which states population you want: NoState
State Name Does not Exist in Map  
Which states population you want: break
*/