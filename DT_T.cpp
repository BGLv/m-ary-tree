#include "pch.h"
#include "DT_T.h"
#include "list"
using namespace std;

// node structure for tree
typedef struct TN_T {
	int currentChild;
	Element_T	Element;
	list<TN_T*> childs;
} Node_T, *Node_Ptr_T;

int	NumberAllocated = 0;

DT_T Create_Tree()
{
	return (NULL);
}

bool Q_EmptyTree(DT_T Tree)
{
	return(Tree == NULL);
}

Element_T Get_Root_Data(DT_T Tree)
{
	Node_Ptr_T	Node_Ptr;

	Node_Ptr = (Node_Ptr_T)Tree;

	return(Node_Ptr->Element);
}

DT_T Get_Next(DT_T Tree)
{
	Node_Ptr_T	Node_Ptr;

	Node_Ptr = (Node_Ptr_T)Tree;

	if (Node_Ptr == NULL) {
		return(NULL);
	}
	else if(Node_Ptr->currentChild < Node_Ptr->childs.size()){
		list<Node_Ptr_T> temp = Node_Ptr->childs;
		for(int i=0; i< Node_Ptr->currentChild; i++)
			temp.pop_front();
		Node_Ptr->currentChild++;
		return((void *)temp.front());
	}
	else {
		Node_Ptr->currentChild=0;
		return(NULL);
	}
}

DT_T Make_Tree(Element_T Element, std::list<DT_T> *childs)
{
	Node_Ptr_T	NewTree;

	NewTree = new Node_T;
	NumberAllocated++;
	NewTree->Element = Element;
	std::list<DT_T>::iterator it;
	if (NULL != childs) {
		for (it = childs->begin(); it != childs->end(); ++it) {
			NewTree->childs.push_back((Node_Ptr_T)*it);
		}
		NewTree->currentChild = 0;
	}
	return((void *)NewTree);
}

DT_T Make_Tree(Element_T Element) {
	return Make_Tree(Element, (NULL));
}

void Add_Child(DT_T Tree, Element_T element)
{
	Node_Ptr_T	NewChild;

	NewChild = new Node_T;

	NewChild->Element = element;
	NewChild->currentChild = 0;

	Node_Ptr_T PTree = (Node_Ptr_T)Tree;
	PTree->childs.push_back(NewChild);
	PTree->currentChild = 0;
}

void Free_Tree(DT_T Tree)
{
	Node_Ptr_T	Node_Ptr;
	Node_Ptr = (Node_Ptr_T) Tree;
	while (0 != Node_Ptr->childs.size()) {
		Free_Tree((DT_T)Node_Ptr->childs.front());
		Node_Ptr->childs.pop_front();
	}
	delete Node_Ptr;
	
}
