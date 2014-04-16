#include "SimpleParticleEngine.hpp"
#include "Particle.hpp"

using namespace trillek::util;

namespace trillek {
    namespace particle {
        void SimpleParticleEngine::Init(int ns, float x, float y, float z) {
            size = ns;
            Particle part;
            sizeXMin = -10.f;
            sizeYMin = -10.f;
            sizeZMin = -10.f;
            sizeXMax = 10.f;
            sizeYMax = 10.f;
            sizeZMax = 10.f;
            lifeMin = 5.f;
            lifeMax = 10.f;
            lifeLength = 0.1f;
            gravX = 0.f;
            gravY = 0.f;
            gravZ = 0.f;
            for(int i = 0; i < size; i++)
            {
                part.x = x;
                part.sx = x;
                part.y = y;
                part.sy = y;
                part.z = z;
                part.sz = z;
                part.vx = Util::RandFloat(sizeXMin, sizeXMax);
                part.vy = Util::RandFloat(sizeYMin, sizeYMax);
                part.vz = Util::RandFloat(sizeZMin, sizeZMax);
                part.life = Util::RandFloat(lifeMin, lifeMax);
                particles[i] = part;
            }
        }
        void SimpleParticleEngine::Update() {
            Particle part;
            for(int i = 0; i < size; i++)
            {
                part = particles[i];
                part.x += part.vx;
                part.y += part.vy;
                part.z += part.vz;
                part.vx += gravX;
                part.vy += gravY;
                part.vz += gravZ;
                part.life -= lifeLength;
                if(part.life <= 0)
                {
                    part.x = part.sx;
                    part.y = part.sy;
                    part.z = part.sz;
                    part.vx = Util::RandFloat(sizeXMin, sizeXMax);
                    part.vy = Util::RandFloat(sizeYMin, sizeYMax);
                    part.vz = Util::RandFloat(sizeZMin, sizeZMax);
                    part.life = Util::RandFloat(lifeMin, lifeMax);
                }
                particles[i] = part;
            }
        }
    }
}
