#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    //declare array with n words for the dictionary
    int n;
    cout << "Enter number of words: " << endl;
    cin >> n;
    vector<string> dictionary;

    //initialize dictionary
    for(int i = 0; i < n; i++)
    {
        do
        {
            cout << "Enter word :" << i << endl;
            string s;
            cin >> s;
            dictionary.push_back(s);
        }while(dictionary[i].size() > 16);
    }

    //read string, use ignore() method to flush the newline character out of the buffer in between
    string readString;
    cout << "Enter string: "<<endl;
    cin.ignore();
    getline(cin, readString);

    //split the string
    istringstream iss(readString);
    vector<string> splitedString;
    do
    {
        string sub;
        iss >> sub;
        cout << sub << endl;
        splitedString.push_back(sub);
    } while (iss);

    string hit;

    //scan if words are in dictionary and print them backwards if they are
    for(int i = 0; i < splitedString.size(); i++)
    {
        for(int j = 0; j < dictionary.size(); j++)
        {
            if( !( splitedString[i].compare(dictionary[j]) ) )
               {
                   hit = splitedString[i];
                   for(int m = hit.size() - 1; m >= 0; m--)
                   {
                       cout << hit[m];
                   }
                   cout << " ";
               }
        }
    }

    return 0;
}
