#pragma once
#include "FeNodeCollection.h"
#include "FeElementCollection.h"
#include <string>
class MeshData
{
public:
	FeNodeCollection Nodes;
	FeElementCollection Elements;

	void AddNode(FeNode node);
	void AddNode(int id, double x, double y, double z);
	void AddElement(FeElement element);
	FeNode* GetNode(int id);
	FeElement* GetElement(int id);
	void ReadSU2File(std::string filename);
	void ReadNodes(std::vector<std::string> lines);
	void ReadElements(std::vector<std::string> lines);
};
