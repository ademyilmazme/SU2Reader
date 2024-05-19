#include "FeNode.h"
#include <iostream>

FeNode::FeNode()
{
	id = 0;
	x = 0;
	y = 0;
	z = 0;
}

FeNode::FeNode(int id, double x, double y, double z)
{
	this->id = id;
	this->x = x;
	this->y = y;
	this->z = z;
}