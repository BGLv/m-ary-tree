// Derivation tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "DT_T.h"
#include "list"
using namespace std;
int main()
{
	/*Element_T el = "start";
	Element_T el1 = "test1";
	Element_T el2 = "test2";
	Element_T el3 = "test3";
	DT_T test1 = Make_Tree(el1);
	DT_T test2 = Make_Tree(el2);
	DT_T test3 = Make_Tree(el3);

	DT_T res = Make_Tree(el, &list<DT_T>{test1, test2, test3});
	Free_Tree(res);*/
	Element_T el = "start";
	DT_T root = Make_Tree(el);
	Add_Child(root, "test1");
	Add_Child(root, "test2");
	Add_Child(root, "test3");
	Free_Tree(root);

    std::cout << "Hello World!\n"; 
}


