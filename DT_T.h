#pragma once
#include "string"
#include "list"

typedef void* DT_T;
typedef std::string Element_T;


//PRE true
//POST RETURN empty tree
DT_T Create_Tree();

//PRE true
//POST  IF Tree is empty
//		RETURN true
//		else
//		RETURN false
bool Q_EmptyTree(DT_T Tree);

//PRE NOT Q_Empty(Tree)
//POST RETURN datavalue of root
Element_T Get_Root_Data(DT_T Tree);

//PRE true
//POST IF not Q_Empty(Tree) 
//		RETURN next subtree of Tree
//		else
//		RETURN empty tree
DT_T Get_Next(DT_T Tree);

//PRE true
//POST RETURN tree with root element value an subtrees childs
DT_T Make_Tree(Element_T value, std::list<DT_T> childs);
