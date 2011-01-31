#include <iostream>
#include "Engine2D.h"

using namespace Engine2D;

Sprite *testspr;
Script settings;

bool game_preload()
{
	settings.loadScript( "settings.lua" );

	g_engine->setAppTitle( "Unnamed Train Game ALPHA v0.0.1" );
	g_engine->setFullscreen( settings.getGlobalBoolean( "FULLSCREEN" )  );
	g_engine->setScreenWidth( (int) settings.getGlobalNumber( "SCREENWIDTH" ) );
	g_engine->setScreenHeight( (int) settings.getGlobalNumber( "SCREENHEIGHT" ) );
	g_engine->setColorDepth( (int) settings.getGlobalNumber( "COLOURDEPTH" )  );

	// return fail to terminate the applciation
	return true;
}

bool game_init( HWND hWnd )
{
	bool loadCheck;

	testspr = new Sprite;
	loadCheck = testspr->loadImage( "testgrfx.png" );

	if( loadCheck == false )
	{
		g_engine->message( "Error loading sprite" );
	}
	else
	{
		testspr->setTotalFrames( 10 );
		testspr->setColumns( 10 );
		testspr->setSize( 32, 32 );
		testspr->setFrameTimer( 40 );
		testspr->setPosition( 400, 300 );
		testspr->setScale( 3.0 );
	}

	return loadCheck;
}

void game_update()
{
	int cx, cy;
	static double scl = 3.0;
	static double scc = 0.000005;

	testspr->animate();

	if( testspr->getCurrentFrame() == testspr->getTotalFrames() )
	{
		cx = 400 - 16;
		cy = 300 - 16;
		testspr->setPosition( cx, cy );
	}

	if( scl <= 0.5 )
		scc = -scc;

	if( scl >= 6.0 )
		scc = -scc;

	scl += scc;

	testspr->setScale( scl );

	if( KEY_DOWN( VK_ESCAPE ) )
		g_engine->Close();
}

void game_end()
{
	delete testspr;
}

void game_render3d()
{
	g_engine->ClearScene( D3DCOLOR_XRGB( 0, 0, 0 ) );
}

void game_render2d()
{
	testspr->draw();
}

void game_keyPress( int key )
{
}

void game_keyRelease( int key )
{
}

void game_mouseButton( int button )
{
}

void game_mouseMotion( int x, int y )
{
}

void game_mouseMove( int x,int y )
{
}

void game_mouseWheel( int wheel )
{
}

void game_entityUpdate( Engine2D::Entity *entity )
{
}

void game_entityRender( Engine2D::Entity *entity )
{
}

void game_entityCollision( Engine2D::Entity *entity1, Engine2D::Entity *entity2 )
{
}
