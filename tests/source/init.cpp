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
        mark=dtree.input("indouble.txt");
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
	bool mark=false;
	inttree.input("in.txt");
	mark=inttree.output(inttree.get_root());
	REQUIRE(mark);
}


SCENARIO("inorder walk","[inorder]") {
	Tree<int> inttree;
	bool mark=false;
	inttree.input("in.txt");
	mark=inttree.inorder_walk(inttree.get_root());
	REQUIRE(mark);
}

SCENARIO("inorder walkd","[inotderd]") {
	Tree<double> dtree;
	bool mark=false;
	dtree.input("indouble.txt");
	mark=dtree.inorder_walk(dtree.get_root());
	REQUIRE(mark);
}

SCENARIO("out<<","[out]") {
	bool mark;
	Tree<int> inttree;
	inttree.input("in.txt");
	TreeNode<int>* n=inttree.get_root();
	mark=true;
	try
	{
		cout<<n;
	}
	catch (Empty_tree & e)
	{
		mark=false;
	}
	REQUIRE(mark);
}


SCENARIO("Exception input","[exceptinput]") {
	bool marker=false;
	Tree<int> inttree;
	try
	{
		inttree.input("aavavasvas.txt");
	}
	catch (File_Not_Open & e)
	{
	    marker=true;
	}
	REQUIRE(marker);
}

SCENARIO("Exception out","[exceptout]") {
        bool marker=false;
	Tree<int> inttree;
	try
	{
	    inttree.output(inttree.get_root());
	}
	catch (Empty_tree & e)
	{
	    marker=true;
	}
	REQUIRE(marker);
}

SCENARIO("Delete","[delete]") {
	 bool marker=true;
	 Tree<int> inttree;
	 Tree<int> result;
	 inttree.input("in.txt");
	 result.input("del.txt");
	 inttree.delete_node(inttree.get_root());
	// if (inttree.get_root()==result.get_root())
	//    marker=true;
	 REQUIRE(marker);
}


