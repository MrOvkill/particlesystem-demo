#ifndef IPARTICLEENGINE_H
#define IPARTICLEENGINE_H

#include "Particle.hpp"
#include "Util.hpp"
#include <map>

namespace trillek {
    namespace particle {
        class IParticleEngine {
            public:
                int size;
                std::map<int, Particle> particles;
                void Init(int ns, float x, float y, float z);
                void Update();
                std::map<int, Particle> getParticles();
        };
    }
}

#endif
