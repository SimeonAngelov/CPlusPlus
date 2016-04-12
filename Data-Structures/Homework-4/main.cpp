#include "Tree.hpp"	

int main()
{
	//Example of isomorphic treees
	std::string da = "(5 {(1 {(4 {}) (18 {}) (259 {})}) (19 {})})";
	std::string da2 ="(5 {(9 {}) (1 {(4 {}) (8 {}) (9 {})})})";

	Tree durvo;
	Tree durvo2;

	durvo.readEntry(da);
	durvo2.readEntry(da2);

	durvo.assignKnutTuples(durvo.getRoot());
	durvo2.assignKnutTuples(durvo2.getRoot());

	bool areIsomorphic = false;
	if (durvo.getRoot()->tupleName == durvo2.getRoot()->tupleName)
		areIsomorphic = true;

	return 0;
}