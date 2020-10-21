#pragma once
#include "deps/tinyxml2.h"
#include "Level.h"

class XMLParser: public Level
{
	 XMLParser();
	~XMLParser();
public:
	XMLError LoadFile(const char* path);

	XMLError ReadFile();
	
protected:
	XMLDocument doc;



};

