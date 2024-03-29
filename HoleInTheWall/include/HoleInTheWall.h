/*
-----------------------------------------------------------------------------
Filename:    HoleInTheWall.h
-----------------------------------------------------------------------------


This source file is generated by the
   ___                   _              __    __ _                  _ 
  /___\__ _ _ __ ___    /_\  _ __  _ __/ / /\ \ (_)______ _ _ __ __| |
 //  // _` | '__/ _ \  //_\\| '_ \| '_ \ \/  \/ / |_  / _` | '__/ _` |
/ \_// (_| | | |  __/ /  _  \ |_) | |_) \  /\  /| |/ / (_| | | | (_| |
\___/ \__, |_|  \___| \_/ \_/ .__/| .__/ \/  \/ |_/___\__,_|_|  \__,_|
      |___/                 |_|   |_|                                 
      Ogre 1.7.x Application Wizard for VC10 (July 2011)
      http://code.google.com/p/ogreappwizards/
-----------------------------------------------------------------------------
*/
#ifndef __HoleInTheWall_h_
#define __HoleInTheWall_h_
#include "StdAfx.h"
#include "BaseApplication.h"
#include "SinbadCharacterController.h"
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#include "../res/resource.h"
#endif
OgreBites::TrayLocation;

enum status
{
	PROGRESS,
	FAILURE,
	SUCCESS,
	DEATH,
};

class HoleInTheWall : public BaseApplication
{
public:
    HoleInTheWall(void);
    virtual ~HoleInTheWall(void);

protected:
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
	    // OIS::KeyListener

    virtual void createScene(void);
	void createHoleRoom(Real roomWidth,Real roomHeight);
	void processWall(const FrameEvent& evt,float outPerc);
	void setupContent();
	Ogre::OverlayElement* mDepthPanel;
	Ogre::OverlayElement* mSuccess;
	Ogre::OverlayElement* mLives[3];
	Ogre::OverlayElement* mFailure;
	Ogre::OverlayElement* mDeath;
	Ogre::OverlayElement* mStart;
	Ogre::OverlayElement* mPhoto;
	OgreBites::ParamsPanel* help;
	status mStatus;
	float LogoTime;
	SinbadCharacterController* mChara;
	YesNoSlider* mQuitSlider;

	
};

#endif // #ifndef __HoleInTheWall_h_
		
	