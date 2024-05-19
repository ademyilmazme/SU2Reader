#include "FeElement.h"
#include <iostream>

FeElement::FeElement()
{
	Id = 0;
	Type = ElementType::None;
}

FeElement::FeElement(int id, std::vector<int> nodeIds)
{
	this->Id = id;
	this->NodeIds = nodeIds;
}