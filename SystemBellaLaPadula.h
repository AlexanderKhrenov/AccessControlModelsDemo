#pragma once
// SystemBellaLaPadula.h
#include <iostream>
#include <vector>
#include "System.h"

class SystemBellaLaPadula : public System 
{
public:
	SystemBellaLaPadula(int objNum, bool useG) : System(objNum, useG)
	{}
	bool checkForREAD(Object& inObj);
	bool checkForWRITE(Object& inObj);
};