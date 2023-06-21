#include <iostream>
#include <string>
#include <vector>
#include "headerFile.h"

using namespace std;

int main()
{
    int n, q, i, k, queryResults[q];
    char queryChoice;
    double s_lower, s_higher;
    string cityChoice, input,temp;
    vector<string> output;
    vector<personDetails> arr;

    cin >> n >> q ;
    cin.ignore();

    //input names
    getline(cin, input);
    cout<<"\n"<<input;
    output = splitStrings(input);
    for (i = 0; i < n; i++)
    {
        arr[i].name = output[i];
    }
    //input age
    for (i = 0; i < n; i++)
    {
        cin >> arr[i].salary;
    }
    cin.ignore();

    // input cities
    getline(cin, input);
    output = splitStrings(input);
    for (i = 0; i < n; i++)
    {
        arr[i].name = output[i];
    }
    cin.ignore();

    // input salary
    for (i = 0; i < n; i++)
    {
        cin >> arr[i].salary;
    }
    cin.ignore();
    
    //query
    for (i = 0; i < q; i++)
    {
        cout << "Query choice";
        cin >> queryChoice;
        switch (queryChoice)
        {
        case '1':
            cout << "enter k";
            cin.ignore();
            cin >> k;
            queryResults[i] = Age_More_than_k(arr, n, k);
            break;
        case '2':
            cout << "enter city";
            cin.ignore();
            cin >> cityChoice;
            queryResults[i] = Persons_from_city(arr, n, cityChoice);
            break;
        case '3':
            cout << "enter salaries";
            cin.ignore();
            cin >> s_lower >> s_higher;
            queryResults[i] = salary_between(arr, n, s_lower, s_higher);
            break;
        }
    }
    for (i = 0; i < q; i++)
    {
        cout << queryResults[i] << "\t";
    }
}