#pragma once
#include "FeElement.h"
#include <map>
class FeElementCollection :public std::map<int, FeElement>
{
public:
	//add an element to the collection
	void AddElement(int id, FeElement element);
	//remove an element from the collection
	void RemoveElement(int id);
	//get an element in the collection
	FeElement* GetElement(int id);
	//get the number of elements in the collection
	int GetElementCount();
};


