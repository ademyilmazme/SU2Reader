#include "MeshData.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Tri3.h"

void MeshData::AddNode(FeNode node)
{
	Nodes.AddNode(node.id, node);
}

void MeshData::AddNode(int id, double x, double y, double z)
{
	FeNode node(id, x, y, z);
	Nodes.AddNode(id, node);
}

void MeshData::AddElement(FeElement element)
{
	Elements.AddElement(element.Id, element);
}

FeNode* MeshData::GetNode(int id)
{
	return Nodes.GetNode(id);
}

FeElement* MeshData::GetElement(int id)
{
	return Elements.GetElement(id);
}

void MeshData::ReadSU2File(std::string filename)
{
    std::vector<std::string> lines;
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }
    else {
        std::cout << "Unable to open file: " << filename << std::endl;
    }

    ReadNodes(lines);
    ReadElements(lines);
}

void MeshData::ReadNodes(std::vector<std::string> lines)
{
    bool addNode = false;
    for (int i = 0; i < lines.size(); i++)
    {
		std::string line = lines[i];
        if (line.find("NPOIN") != std::string::npos)
        {
			addNode = true;
            continue;
		}
        if (addNode)
        {
            std::vector<std::string> splittedLine;
            std::istringstream iss(line);
            std::string temp;

            while (iss >> temp) 
            {
                splittedLine.push_back(temp);
            }

            if (splittedLine.size() == 3)
            {
                int id = std::stoi(splittedLine[2]) + 1;
                double x = std::stod(splittedLine[0]);
                double y = std::stod(splittedLine[1]);
                double z = 0;
                AddNode(id, x, y, z);

            }
            else if (splittedLine.size() == 4)
            {
				int id = std::stoi(splittedLine[3]) + 1;
				double x = std::stod(splittedLine[0]);
				double y = std::stod(splittedLine[1]);
				double z = std::stod(splittedLine[2]);
				AddNode(id, x, y, z);
			}
        }

        if (line.find("NMARK") != std::string::npos)
        {
            break;
        }
	}
}

void MeshData::ReadElements(std::vector<std::string> lines)
{
	bool addElement = false;
    for (int i = 0; i < lines.size(); i++)
    {
		std::string line = lines[i];
        if (line.find("NELEM") != std::string::npos)
        {
			addElement = true;
			continue;
		}
        if (addElement)
        {
			std::vector<std::string> splittedLine;
			std::istringstream iss(line);
			std::string temp;

            while (iss >> temp)
            {
				splittedLine.push_back(temp);
			}

            if (splittedLine[0] == "5") //Triangle
            {
				int id = std::stoi(splittedLine[4]) + 1;
				int node1 = std::stoi(splittedLine[1]) + 1;
				int node2 = std::stoi(splittedLine[2]) + 1;
				int node3 = std::stoi(splittedLine[3]) + 1;
                std::vector<int> nodeIds = { node1, node2, node3 };
                Tri3 tri3(id, nodeIds);
				AddElement(tri3);
			}
		}

        if (line.find("NPOIN") != std::string::npos)
        {
			break;
		}
	}
}

