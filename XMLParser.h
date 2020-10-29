#pragma once
#include "deps/tinyxml2.h"
#include "Level.h"



class XMLParser
{
	
public:
	XMLParser(/*const char* path*/);
	~XMLParser();

	bool LoadXMLFile(const char* path);

	bool ReadXMLFile(Level *level);
	
protected:
	tinyxml2::XMLDocument doc;

};

