#include <tree.hpp>
#include <Node.hpp>
#include <catch.hpp>


SCENARIO("Tree init", "[init]") {
         Tree<int> inttree;
         bool mark=false;
         mark=inttree.input("in.txt");
	 REQUIRE(mark);
}

SCENARIO("doubleTree init", "[init]") {
	Tree<double> dtree;
	bool mark=false;
         mark=inttree.input("indouble.txt");
	 REQUIRE(mark);
}
SCENARIO("Insert node","[insert]") {
	Tree<int> inttree;
	bool mark=false;
	mark=inttree.insert_node(125);
	REQUIRE(mark);
}

SCENARIO("Output tree","[output]") {
	Tree<int> inttree;
	inttree.input("in.txt");
	bool mark=false;
	mark=inttree.output(inttree.get_root());
	REQUIRE(mark);
}


SCENARIO("inorder walk","[inorder]") {
	Tree<int> inttree;
	inttree.input("in.txt");
	bool mark=false;
	mark=inttree.inorder_walk(inttree.get_root());
	REQUIRE(mark);
}

SCENARIO("inorder walkd","[inotderd]") {
	Tree<double> dtree;
	dtree.input("indouble.txt");
	bool mark=false;
	mark=dtree.inorder_walk(dtree.get_root());
	REQUIRE(mark);
}


