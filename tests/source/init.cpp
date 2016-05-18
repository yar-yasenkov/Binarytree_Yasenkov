#include <tree.hpp>
#include <Node.hpp>
#include <catch.hpp>


SCENARIO("Tree init", "[init]") {
         Tree<int> inttree;
         bool mark=false;
         try {mark=inttree.input("in.txt");}
	 catch (Empty_tree & e){}
	 REQUIRE(mark);
}

SCENARIO("doubleTree init", "[init]") {
	Tree<double> dtree;
	bool mark=false;
        try{ mark=dtree.input("indouble.txt");}
	catch (Empty_tree & e){}
        REQUIRE(mark);
}
SCENARIO("Insert node","[insert]") {
	Tree<int> inttree;
	bool mark=false;
	try{mark=inttree.insert_node(125);}
	catch (Empty_tree & e){}
	REQUIRE(mark);
}

SCENARIO("Output tree","[output]") {
	Tree<int> inttree;
	inttree.input("in.txt");
	bool mark=false;
	mark=inttree.output(inttree.get_root());
	catch (Empty_tree & e){}
	REQUIRE(mark);
}


SCENARIO("inorder walk","[inorder]") {
	Tree<int> inttree;
	inttree.input("in.txt");
	bool mark=false;
	mark=inttree.inorder_walk(inttree.get_root());
	catch (Empty_tree & e){}
	REQUIRE(mark);
}

SCENARIO("inorder walkd","[inotderd]") {
	Tree<double> dtree;
	dtree.input("indouble.txt");
	bool mark=false;
	mark=dtree.inorder_walk(dtree.get_root());
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

/*SCENARIO("Exception inorder","[exceptinorder]") {
	bool marker=false;
	Tree<int> inttree;
	inttree.input("in.txt");
	try
	{
		inttree.inorder_walk(inttree.get_root());
	}
		catch (Empty_tree & e)
		{
			marker=true;
		}
		REQUIRE(marker);
}*/

SCENARIO("Exception find","[exceptionfind]") {
	bool marker=false;
	Tree<int> inttree;
	try
	{
		cout << inttree.get_root();
		inttree.find_node(inttree.get_root(),10);
	}
	catch (Empty_tree & e)
	{
		marker=true;
	}
	REQUIRE(marker);
}
