#include "FeNodeCollection.h"
#include <iostream>

void FeNodeCollection::AddNode(int Id, FeNode value) {
	this->insert(std::pair<int, FeNode>(Id, value));

}

void FeNodeCollection::RemoveNode(int id)
{
	this->erase(id);
}
FeNode* FeNodeCollection::GetNode(int id)
{
	return &this->find(id)->second;;
}
int FeNodeCollection::GetNodeCount()
{
	return this->size();
}