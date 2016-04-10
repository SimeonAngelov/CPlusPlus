#include <iostream>
using namespace std;

void Row(int start, int end)
{
	if (start > end)
	{
		return;
	}
	else{
		cout << start << " ";
		Row(start + 1, end);
		if (start == end)
		{
			cout << endl;
		}
	}
}

void Pyramid(int start, int end)
{
	if (start > end) return;
	else{
		Row(1, start);
		Pyramid(start + 1, end);
		//start from start-1 to avoid repeating longest row
		Row(1, start - 1);
	}
}

int main(){
	int n;
	do{
		cout << "Number between 1 and 20: ";
		cin >> n;
	} while (n<0 || n >20);

	Pyramid(1,n);

	return 0;
}
