#include "XMLParser.h"
#include <iostream>




using namespace tinyxml2;

XMLParser::XMLParser(const char* path)
{
	if (LoadXMLFile(path) == false) {
		std::cout << "Couldnt load path: " << path << std::endl;
		exit(1);
	}	
}

XMLParser::~XMLParser()
{
	delete(&doc);
}

bool XMLParser::LoadXMLFile(const char* path)
{
	XMLError eResult = doc.LoadFile(path);
	if (eResult != XML_SUCCESS) return false;
	return true;
}

bool XMLParser::ReadXMLFile(Level level){

	
	XMLElement* root = doc.FirstChildElement("Level");

	if (root != 0) {

		//lvl element
	
		root->FindAttribute("RowCount")->QueryUnsignedValue(level.RowCount);
	
		root->FindAttribute("ColumnCount")->QueryUnsignedValue(level.ColumnCount);
	
		root->FindAttribute("RowSpacing")->QueryUnsignedValue(level.RowSpacing);
	
		root->FindAttribute("ColumnSpacing")->QueryUnsignedValue(level.ColumnSpacing);

		level.BackgroundTexture =root->FindAttribute("BackgroundTexture")->Value();

		/*level->RowCount = RowCount;
		level->ColumnCount = ColumnCount;
		level->RowSpacing = RowSpacing;
		level->ColumnSpacing = ColumnSpacing;
		level->BackgroundTexture = BackgroundTexture;*/

		Brick* bricks[4] = { 0,0,0,0};
		XMLElement* brickTypes = root->FirstChildElement("BrickTypes");
		if (brickTypes != 0) {
			
			int i = 0;
			for(XMLElement* brickType = brickTypes->FirstChildElement("BrickType");brickType!=NULL;brickType->NextSiblingElement("BrickType")){
		    	if (brickType != 0) {
					//bricktype element
					

					const char* Id =brickType->FindAttribute("Id")->Value();
					const char* Texture=brickType->FindAttribute("Texture")->Value();
				    unsigned int *HitPoints=NULL;
		    		brickType->FindAttribute("HitPoints")->QueryUnsignedValue(HitPoints);
					
					const char* HitSound=brickType->FindAttribute("HitSound")->Value();
					const char* BreakSound=brickType->FindAttribute("BreakSound")->Value();
					unsigned int *BreakScore=NULL;
		    		brickType->FindAttribute("BreakScore")->QueryUnsignedValue(BreakScore);

					Brick newBrick = Brick(Id,Texture,HitPoints,HitSound,BreakSound,BreakScore);
					bricks[i] = &newBrick;
					i++;
		        }
			}
		}
		//input to 
		level.BrickSoft = bricks[0];
		level.BrickMedium = bricks[1];
		level.BrickHard = bricks[2];
		level.BrickImpenetrable = bricks[3];

		//bricks element
		level.BricksMap = root->NextSiblingElement("Bricks")->GetText();
		return true;
	}
	return false;
}