#include<iostream.h>
#include<math.h> 

int main{
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;

	if (y = > 0 && (x*x + y*y) <= 4)
	{
		cout << "Target is in the shape, in the semicircle.";
	}
	else if (y < 0 && y = > -2 && abs(x) <= 1)
	{
		cout << "Target is in the shape, in the square.";
	}
	else
	{
		cout << "Target is offside";
	}
	return 0;
}
