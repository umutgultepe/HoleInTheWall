#include "StdAfx.h"
#define IncomingWallWidth  30 
#define IncomingWallHeight 20
#define START_SPEED 5
#define SPEED_INCREASE 3
#define DepthMaterialName "MyDepthTexture"
#define depthWidth 640
#define depthHeight 480
using namespace Ogre;
class IncomingWall
{
private:
	Ogre::String entityName;
	Entity* wall;
	Image* wallImage;

public:
	IncomingWall(SceneManager* mScene,Ogre::String name,Ogre::String MaterialName);
	~IncomingWall(void);
	Entity* getWall();
	Image* getImage();
	//bool compareTextures();

};

void initWallResources(SceneManager* mScene);