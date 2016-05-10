#include <tree.hpp>
#include <Node.hpp>

SCENARIO("Tree init", "[init]") {
Tree inttree;
inttree.input("in.txt");
	
}
/*
SCENARIO("Matrix >>", "[fill]") {
	Matrix A = Matrix(2, 2);
	REQUIRE( A.fill("A2x2.txt") );
}

SCENARIO("Matrix +", "[addition]") {
	Matrix A = Matrix(2, 2);
	A.fill("A2x2.txt");
	Matrix B = Matrix(2, 2);
	B.fill("B2x2.txt");
	Matrix expected = Matrix(2, 2);
	expected.fill("A+B2x2.txt");

	Matrix result = A + B;
	REQUIRE(result == expected);
}
*/
