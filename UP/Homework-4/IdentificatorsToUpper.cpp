#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

 void IdenficatorsToUpper(char * str)
 {
    //convert char[] to string and split it
    string str2(str);
    istringstream iss(str2);
    vector<string> splitedString;
    do
    {
        string sub;
        iss >> sub;
        splitedString.push_back(sub);
    } while (iss);

    //find valid identifiers using ASCII table
    vector<string> validIdentifiers;
    string iC;
    for(int i = 0; i < splitedString.size(); i++)
    {
        iC = splitedString[i];
        if(iC[0] < 95 || iC[0] > 122 || iC[0] != 96)
        {
            validIdentifiers.push_back(splitedString[i]);
        }
    }

    //modify first letter of valid identifiers
    for(int i = 0; i < validIdentifiers.size(); i++)
        {
            int startIndex = str2.find(validIdentifiers[i]);
            if(str2[startIndex] != '_')
            {
                str2[startIndex] = toupper(str2[startIndex]);
            }else
            {
                 str2[startIndex+1] = toupper(str2[startIndex+1]);
            }
        }

    str = &str2[0];
    cout << str;
 }

int main()
{
    char str[] = "imam 3deset i edna _qbulki";
    IdenficatorsToUpper(str);
    return 0;
}
