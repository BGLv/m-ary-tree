#pragma once
#include "string"

typedef void* DT_T;
typedef std::string Element_T;



//PRE TRUE
//POST RETURN initialized DT_T
DT_T Create_Derivation_Tree();

//PRE DT_Empty(DT)
//POST free memory for DT_T
//NOTE: for next use of Tree we must reinitialize it by Create_Derivation_Tree()
void Free_Derivation_Tree(DT_T Tree);


//PRE TRUE
//POST IF tree is empty
//RETURN true
//else
//RETURN false
bool DT_Empty(DT_T Tree);

//PRE DT_Empty(Tree)
//POST Tree with current element as head with value inside;
void Add_Head(Element_T value, DT_T Tree);

//PRE NOT DT_Empty(Tree)
//POST Tree with new child at current node child list
void Add_Child_To_Current(Element_T value, DT_T Tree)



//PRE NOT DT_Empty(Tree)
//POST head become current element
void Go_To_Head(DT_T Tree);