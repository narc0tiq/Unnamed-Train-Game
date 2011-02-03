#include "SmokeParticle.h"

namespace Engine2D
{
	SmokeParticle::SmokeParticle() : ParticleEmitter()
	{
		scale = 0.1f;
	}

	SmokeParticle::~SmokeParticle()
	{
	}

    void SmokeParticle::update( int ms )
    {
        static Timer timer;
		Vector3 vel;
        
        //do we need to add a new particle?
        if ((int)particles.size() < max) 
        {
            //trivial but necessary slowdown
            if( timer.stopwatch( ms ) )
				add();
        }
        
        for (iter i = particles.begin(); i != particles.end(); ++i)
        {
            //has lifetime expired?
            if ((*i)->getLifetime() > 0)
			{
                if ((*i)->lifetimeExpired())
					i = particles.erase(i);
            }

            //update particle's position
			vel = (*i)->getVelocity();
			vel.setY( vel.getY() + 0.00005f );
			if( vel.getY() > -0.01 )
				vel.setY( 0.0f );
			(*i)->setVelocity( vel );
			if( (*i)->getScale() < 1.0f )
				(*i)->setScale( (*i)->getScale() + 0.00005f );
			(*i)->move();

            //is particle beyond the emitter's range?
            if ( (*i)->getPosition().Distance(this->position) > length)
            {
                //reset particle to the origin
                (*i)->setX(position.getX());
                (*i)->setY(position.getY());
            }
        }
    }};