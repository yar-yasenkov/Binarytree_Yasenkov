#include <tree.hpp>
#include <Node.hpp>
#include <catch.hpp>


SCENARIO("Tree init", "[init]") {
         Tree inttree;
         bool mark=false;
         mark=inttree.input("in.txt");
	 REQUIRE(mark);
}

SCENARIO("Insert node","[insert]") {
	Tree inttree;
	bool mark=false;
	mark=inttree.insert_node(125);
	REQUIRE(mark);
}


/*
SCENARIO("Matrix >>", "[fill]") {
	Matrix A = Matrix(2, 2);
	REQUIRE( A.fill("A2x2.txt") );
}


*/
