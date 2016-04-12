#include "DoubleVector.h"
#include "boolVector.h"

int main()
{
	//create vector
	DoubleVector vec(5);
	vec.printVector();
	
	//show operator[]
	std::cout << std::endl;
	std::cout <<"Show operator[]"<< std::endl;
	std::cout << "coordinate [3] : " << vec[3] << std::endl;
	
	//create anotner two vectors and show operator+
	std::cout << std::endl;
	DoubleVector vec2(3);
	DoubleVector vec3 = vec + vec2;
	std::cout << "vec3 coordinates with value vec + vec2 are:" <<std::endl;
	vec3.printVector();

	//show operator+=
	std::cout << std::endl;
	vec3 += vec2;
	std::cout << "vec3 new coordinates after operaotr+= with vec2 are:" << std::endl;
	vec3.printVector();

	//show operator-=
	std::cout << std::endl;
	vec3 -= vec;
	std::cout << "vec3 new coordinates after operator-= with vec are:" << std::endl;
	vec3.printVector();

	//show operator-
	std::cout << std::endl;
	DoubleVector vec4 = vec - vec2;
	std::cout << "vec4 coordinates with value vec - vec2 are:" << std::endl;
	vec4.printVector();

	//show operator*
	std::cout << std::endl;
	DoubleVector vec5 = vec * 3;
	std::cout << "vec5 coordinates with value vec * 3 are:" << std::endl;
	vec5.printVector();

	//show operator*=
	std::cout << std::endl;
	vec5 *= 3;
	std::cout << "vec5 coordinates with vaule vec5 *= 3 are:" << std::endl;
	vec5.printVector();

	//show operator/
	std::cout << std::endl;
	DoubleVector vec6 = vec / 3;
	std::cout << "vec6 coordinates with value vec / 3 are:" << std::endl;
	vec6.printVector();

	//show operator/=
	std::cout << std::endl;
	vec6 /= 2;
	std::cout << "vec6 coordinates with vaule vec6 /= 2 are:" << std::endl;
	vec6.printVector();

	//show operator%
	std::cout << std::endl;
	double scalarProduct = vec % vec2;
	std::cout << "scalar product of vec and vec2 is : " << scalarProduct << std::endl;
	std::cout << std::endl;

	//TEST boolVec
	std::cout << "-----TEST OF BOOL VECTOR-----" <<std::endl;
	boolVector boolVec;
	boolVec.printVector();

	//show operator[]
	std::cout << std::endl;
	std::cout << "Show operator[] : " << std::endl;
	std::cout << "coordinate [3] : " << boolVec[3] << std::endl;
	std::cout << "coordinate [35] : " << boolVec[35] << std::endl;

	//show method bool set(int);
	std::cout << std::endl;
	std::cout << "Show method bool set(int) : " << std::endl;
	std::cout << "Initialize coordinates 3 and 29 with value 1 " << std::endl;
	boolVec.set(3);
	boolVec.set(29);
	boolVec.printVector();

	//show method bool clear(int);
	std::cout << std::endl;
	std::cout << "Show method bool clear(int) : " << std::endl;
	std::cout << "Initialize coordinates 4 and 30 with value 0 " << std::endl;
	boolVec.clear(4);
	boolVec.clear(30);
	boolVec.printVector();
	
	return 0;
}
