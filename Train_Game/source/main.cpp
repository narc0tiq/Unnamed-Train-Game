#include <iostream>
#include "Engine2D.h"

using namespace Engine2D;

Sprite *testspr;
Script settings;
ParticleEmitter *pa;
Font *systemFont;

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

	g_engine->setMaximizeProcessor( true );

	systemFont = new Font();
	if( !systemFont->loadImage( "font.tga" ) )
	{
		g_engine->message( "Error loading system font." );
		return false;
	}
	systemFont->setColumns( 16 );
	systemFont->setCharSize( 15, 20 );
	systemFont->loadWidthData( "font.dat" );

	pa = new ParticleEmitter();

	pa->loadImage( "test_smoke.png" );
	pa->setPosition( 512, 144 );
	pa->setDirection( 0 );
	pa->setMax( 100 );
	pa->setAlphaRange( 0, 255 );
	pa->setColorRange( 254, 254, 254, 255, 255, 255 );
	pa->setSpread( 10 );
	pa->setVelocity( 1.0 );	
	pa->setLength( 250 );

	testspr = new Sprite;
	loadCheck = testspr->loadImage( "test_train.png" );

	if( loadCheck == false )
	{
		g_engine->message( "Error loading sprite" );
	}
	else
	{
		testspr->setTotalFrames( 1 );
		testspr->setColumns( 10 );
		testspr->setSize( 50, 34 );
		testspr->setFrameTimer( 40 );
		testspr->setPosition( 400, 300 );
		testspr->setScale( 1.0 );
		testspr->setVelocity( -2, 0 );
	}

	return loadCheck;
}

void game_update()
{
	int cx, cy;
	static double scl = 3.0;
	static double scc = 0.000005;
	Vector3 pos;

	pa->update();

	testspr->move();
	testspr->animate();

	if( scc > 0 )
		scc =    (float) g_engine->getFrameRate_real() / 100000.0f;
	else
		scc = -( (float) g_engine->getFrameRate_real() / 100000.0f );

	pos = testspr->getPosition();

	if( pos.getX() <= 100 )
	{
		cx = g_engine->getScreenWidth() - 100;
		cy = 300;
		testspr->setPosition( cx, cy );
	}

	pa->setPosition( pos.getX() + 4, pos.getY() - 20 );

	//testspr->setScale( scl );

	if( KEY_DOWN( VK_ESCAPE ) )
		g_engine->Close();
}

void game_end()
{
	delete systemFont;
	delete pa;
	delete testspr;
}

void game_render3d()
{
	g_engine->ClearScene( D3DCOLOR_XRGB( 0, 0, 80 ) );
}

void game_render2d()
{
	std::ostringstream os;

	pa->draw();
	testspr->draw();

	systemFont->setScale( 1.0f );

	os.str( "" );
	os << "FPS1: " << g_engine->getFrameRate_real();
	systemFont->Print( 1,  1, os.str() );

	os.str( "" );
	os << "FPS2: " << g_engine->getFrameRate_core();
	systemFont->Print( 1, 20, os.str() );

	systemFont->setScale( testspr->getScale() );
	systemFont->Print( 1, 40, "Testing the font" );
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
