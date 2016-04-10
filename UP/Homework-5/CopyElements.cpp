#include <iostream>
#include <vector>

using namespace std;

vector<int> copyElements(vector<int> array1, vector<int> & array2, int n, int i)
{
    if (n == array1.size())
    {
        return array1;
    }
    else
    {
        if (array1[n] % 2 == 0)
        {
            array2.push_back(array1[n]);
        }

        return copyElements(array1, array2, n + 1, i);
    }

}

int main()
{

    //get vector size
	unsigned int max;
	do
    {
        cout << "Enter size of array" << endl;
        cin >> max;
	} while ( max > 1000);

	//initialize vector
	vector<int> array1;
	int element;
    for(int i = 0; i < max; i++)
    {
        cout << "enter element" << endl;
        cin >> element;
        array1.push_back(element);
    }

	//copy elements to 2nd vector
    vector<int> array2;
	copyElements(array1, array2, 0, 0);

	//print out 2nd vector
	for(int i = 0; i < array2.size(); i++) {
		cout << "vector2[" << i << "]=" << array2[i] << endl;
	}
	return 0;
}
