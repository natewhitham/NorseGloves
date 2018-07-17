//
//  Particle.hpp
//  Particle Fire Explosion
//
//  Created by Nate on 7/13/18.
//  Copyright © 2018 Nate. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp
#include <SDL2/SDL.h>
#include <stdio.h>

namespace nrw {
    struct Particle{
        double m_xPosition;
        double m_yPosition;
        
    private:
        double m_Speed;
        double m_Direction;

    private:
        void init();

    public:
        Particle();
        virtual ~Particle();
        void update(int interval);
    };
    
} /* namespace nrw */

#endif /* Particle_hpp */
