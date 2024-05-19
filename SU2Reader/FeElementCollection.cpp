#include "FeElementCollection.h"
#include <iostream>

void FeElementCollection::AddElement(int id, FeElement element)
{
	this->insert(std::pair<int, FeElement>(id, element));
}

void FeElementCollection::RemoveElement(int id)
{
	this->erase(id);
}

FeElement* FeElementCollection::GetElement(int id)
{
	return &this->find(id)->second;
}

int FeElementCollection::GetElementCount()
{
	return this->size();
}

