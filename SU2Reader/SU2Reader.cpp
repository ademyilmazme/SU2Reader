// SU2Reader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MeshData.h"
using namespace std;

int main()
{

    //creta object from meshdata
    MeshData meshData;

    string su2FilePath = "\\repos\\SU2Reader\\TestFile\\t1.su2";
    meshData.ReadSU2File(su2FilePath);
    FeNode* node = meshData.GetNode(1);
    
    int ali = 2;
}


