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

SCENARIO("Output tree","[output]") {
	Tree inttree;
	bool mark=false;
	mark=inttree.output(inttree.get_root);
	REQUIRE(mark);
}
SCENARIO("inorder walk","[inorder]") {
	Tree inttree;
	bool mark=false;
	mark=inttree.inorder_walk(inttree.get_root);
	REQUIRE(mark);
}



