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
	for (int i = 0; i < this->size(); i++)
	{
		if (this->at(i).Id == id)
		{
			return &this->at(i);
		}
	}
	return nullptr;
}

int FeElementCollection::GetElementCount()
{
	return this->size();
}

