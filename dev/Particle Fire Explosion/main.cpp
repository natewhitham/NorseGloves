//
//  main.cpp
//  SDL Window
//
//  Created by Nate on 7/13/18.
//  Copyright © 2018 Nate. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.hpp"
#include <stdlib.h>
#include <time.h>
#include "Swarm.hpp"

using namespace std;
using namespace nrw;

int main() {
    // insert code here...
    srand(time(NULL));
    
    Screen screen;
    if(screen.init() == false){
        cout << "Error initialising SDL." << endl;
    }
 
    Swarm swarm;
    
    while(true) {
        //Update particles
        
        //draw particles
        int elapsed = SDL_GetTicks();
        
        
        swarm.update(elapsed);
        
        unsigned char green = (unsigned char)((1 + cos(elapsed* 0.001)) * 128);
        unsigned char red = (unsigned char)((1 + cos(elapsed* 0.002)) * 128);
        unsigned char blue = (unsigned char)((1 + cos(elapsed* 0.003)) * 128);
        
        const Particle * const  pParticle = swarm.getParticles();
        for(int i=0; i<Swarm::NPARTICLES; i++) {
            Particle particle = pParticle[i];
            
            int x = (particle.m_xPosition + 1) * Screen::SCREEN_WIDTH / 2;
            int y = particle.m_yPosition * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;
            
            screen.setPixel(x, y, red, green, blue);
        }
        
        screen.boxBlur();

        //Draw the Screen
        screen.update();
        
        //check for messages/events
        if(screen.processEvents() == false){
            break;
        }
    }
    
    screen.close();
    
    return 0;
}

