#include <iostream>
#include "Engine2D.h"

bool game_preload()
{
	// Display engine version in a message box
	g_engine->message( g_engine->getVersionText(), "Test Engine" );

	// return fail to terminate the applciation
	return false;
}

bool game_init( HWND hWnd )
{
	return 0;
}

void game_update()
{
}

void game_end()
{
}

void game_render3d()
{
}

void game_render2d()
{
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
