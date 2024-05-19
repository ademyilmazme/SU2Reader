#pragma once
#include <vector>

//Create enum for element type
enum class ElementType
{
	LINE2,
	TRIANGLE3,
	Quadrilateral4,
	Tetrahedral4,
	Prism5,
	Pyramid6,
	Hexahedral8,
	None
};
class FeElement
{
public:
	int Id;
	std::vector<int> NodeIds;
	//Virtual Element type
	ElementType Type = ElementType::None;


	FeElement();
	FeElement(int id, std::vector<int> nodeIds);

};

