#pragma once
#include "FeNode.h"
#include <map>
class FeNodeCollection : public std::map<int, FeNode>
{
public:
	//add a node to the collection
	void AddNode(int id, FeNode node);
	//remove a node from the collection
	void RemoveNode(int id);
	//get a node in the collection
	FeNode* GetNode(int id);
	//get the number of nodes in the collection
	int GetNodeCount();


};

