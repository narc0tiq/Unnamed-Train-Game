#ifndef _MAP_BASE_H
#define _MAP_BASE_H

#include "Engine2D.h"

namespace Engine2D
{
	class SmokeParticle : public ParticleEmitter
	{
	public:
		SmokeParticle(void);
		~SmokeParticle(void);

        void update(int ms = 5);
	};
};

#endif