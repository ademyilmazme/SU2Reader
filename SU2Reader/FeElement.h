#pragma once
#include <vector>

//Create enum for element type
enum class ElementType
{
	LINE,
	TRIANGLE,
	Quadrilateral,
	Tetrahedral,
	Hexahedral,
	Prism,
	Pyramid,
	None
};
class FeElement
{
public:
	int Id;
	std::vector<int> NodeIds;
	//Virtual Element type
	ElementType Type;


	FeElement();
	FeElement(int id, std::vector<int> nodeIds);

};

