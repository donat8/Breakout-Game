//#include "XMLParser.h"
//using namespace tinyxml2;
//
//
//XMLError XMLParser::LoadXMLFile(const char* path)
//{
//	XMLError eResult = doc.LoadFile(path);
//	if (eResult != XML_SUCCESS) return XML_ERROR_FILE_COULD_NOT_BE_OPENED;
//}
//XMLError XMLParser::ReadXMLFile(){
//
//	XMLNode* root = doc.FirstChildElement("Level");
//	if (root == nullptr) return XML_ERROR_FILE_READ_ERROR;
//
//
//
//	XMLElement*  element = root->FirstChildElement("BrickTypes");
//
//	element->FindAttribute("BrickType");
//	
//
//    element = root->NextSiblingElement("Bricks");
//
//	Bricks = element->GetText();
//
//}