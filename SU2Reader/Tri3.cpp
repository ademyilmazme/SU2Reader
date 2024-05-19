#include "Tri3.h"

Tri3::Tri3(int id, std::vector<int> nodeIds) : FeElement(id, nodeIds)
{
	Type = ElementType::TRIANGLE3;

}