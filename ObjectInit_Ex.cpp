#include "ObjectInit_Ex.h"


void ObjecInit_Ex::InitObject(const bool& toValidate, const char* objName)
{
	if (!toValidate) {
		std::cout << objName << "was not initialised" << std::endl;
		exit(1);
	}
}
