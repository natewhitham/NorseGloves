//
//  Particle.hpp
//  Particle Fire Explosion
//
//  Created by Nate on 7/13/18.
//  Copyright © 2018 Nate. All rights reserved.
//

#ifndef Swarm_hpp
#define Swarm_hpp
#include <SDL2/SDL.h>
#include <stdio.h>
#include "Particle.hpp"

namespace nrw {
    class Swarm{
    public:
        const static int NPARTICLES = 5000;
    private:
        Particle * m_pParticles;
        int lastTime;
    public:
        Swarm();
        virtual ~Swarm();
        void update(int elapsed);
        
    public:
        const Particle * const getParticles() {
            return m_pParticles;
        }
    };
    
} /* namespace nrw */

#endif /* Particle_hpp */
