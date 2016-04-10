#include <iostream>

using namespace std;

int main()
{
    int n;

     //read N
    do{
    cout<<"enter n: ";
    cin >> n;
    }while(n <= 2 || n >= 1024);

    int array[1024];

    //read N numbers
    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    //find longest sequence
    int endIndexChecker = 0;
    int endIndex = 0;
    int longestSeqChecker = 1;
    int longestSeq = 1;
    for(int i = 0; i < n - 1; i++)
    {
        if(array[i] == array[i+1])
        {
            endIndexChecker = i+1;
            longestSeqChecker++;
            if(longestSeqChecker > longestSeq)
            {
                longestSeq = longestSeqChecker;
                endIndex = endIndexChecker;
            }
        }else
        {
            endIndexChecker = 0;
            longestSeqChecker = 1;
        }
    }

    int startIndex = (endIndex+1) - longestSeq;
    cout << "Longest sequence is " << longestSeq << " elements long, with a start index from the array: " << startIndex;

    return 0;
}
