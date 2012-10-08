#include "StdAfx.h"
#include "IncomingWall.h"
TexturePtr depthTexture;
Ogre::SceneNode* wallNode;
Entity* fitIndicatorTop;
Entity* fitIndicatorLeft;
Entity* fitIndicatorRight;
void initWallResources(SceneManager* mScene)
{
	//Incoming Wall Plane
	MeshPtr wall= MeshManager::getSingleton().createPlane("wall", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
			Plane(Vector3::UNIT_X, 0),IncomingWallWidth, IncomingWallHeight, 1, 1, true, 1, 1, 1, Vector3::UNIT_Y);
	unsigned short src, dest;
	 if (!wall->suggestTangentVectorBuildParams(VES_TANGENT, src, dest))
    {
		wall->buildTangentVectors(VES_TANGENT, src, dest);
		// this version cleans mirrored and rotated UVs but requires quality models
		// mesh->buildTangentVectors(VES_TANGENT, src, dest, true, true);
    }

	

	MeshManager::getSingleton().createPlane("fitIndicatorTop", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
			Plane(Vector3::UNIT_X, 0),IncomingWallWidth+3, 1.5, 1, 1, true, 1, 1, 1, Vector3::UNIT_Y);
	MeshManager::getSingleton().createPlane("fitIndicatorSide", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
			Plane(Vector3::UNIT_X, 0),1.5, IncomingWallHeight, 1, 1, true, 1, 1, 1, Vector3::UNIT_Y);

	Ogre::ResourceGroupManager& lRgMgr = Ogre::ResourceGroupManager::getSingleton();
	
	lRgMgr.addResourceLocation(".", "FileSystem", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, false);
	lRgMgr.initialiseResourceGroup(ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	wallNode=mScene->getRootSceneNode()->createChildSceneNode("IncomingWallNode",Vector3(0,IncomingWallHeight/2,0));
	
	Ogre::SceneNode* fitNode=wallNode->createChildSceneNode("FitNode",Vector3(-0.015,0.75,0));

	Ogre::SceneNode* topNode=fitNode->createChildSceneNode("FitNodeTop",Vector3(0,IncomingWallHeight/2,0));
	Ogre::SceneNode* leftNode=fitNode->createChildSceneNode("FitNodeLeft",Vector3(0,-0.75,-IncomingWallWidth/2-0.75));
	Ogre::SceneNode* rightNode=fitNode->createChildSceneNode("FitNodeRight",Vector3(0,-0.75,IncomingWallWidth/2+0.75));
	

	fitIndicatorTop= mScene->createEntity("FitIndicateTop","fitIndicatorTop");
	fitIndicatorLeft= mScene->createEntity("FitIndicateLeft","fitIndicatorSide");
	fitIndicatorRight= mScene->createEntity("FitIndicateRight","fitIndicatorSide");

	

	fitIndicatorTop->setMaterialName("unfit_mat");
	fitIndicatorTop->setCastShadows(false);

	fitIndicatorLeft->setMaterialName("unfit_mat");
	fitIndicatorLeft->setCastShadows(false);
	fitIndicatorRight->setMaterialName("unfit_mat");
	fitIndicatorRight->setCastShadows(false);

	topNode->attachObject(fitIndicatorTop);
	leftNode->attachObject(fitIndicatorLeft);
	rightNode->attachObject(fitIndicatorRight);

	fitIndicatorRight->setVisible(true);
	fitIndicatorTop->setVisible(true);
	fitIndicatorLeft->setVisible(true);

}



IncomingWall::IncomingWall(SceneManager* mScene,Ogre::String name,Ogre::String MaterialName)
{

		entityName=name;
		//Add the incoming Wall 
		wall = mScene->createEntity(entityName,"wall");
		wall->setMaterialName(MaterialName);
		
		String texName=wall->getSubEntity(0)->getMaterial()->getTechnique(0)->getPass(0)->getTextureUnitState(1)->getTextureName();
		wallImage=new Image();
		wallImage->load(texName,ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
		wallImage->resize(640,480);
		//wall->setCastShadows(false);
		wallNode->attachObject(wall);
		wall->setVisible(false);
}


IncomingWall::~IncomingWall(void)
{
}

Entity* IncomingWall::getWall()
{
	return wall;
}

Image* IncomingWall::getImage()
{
	return wallImage;
}