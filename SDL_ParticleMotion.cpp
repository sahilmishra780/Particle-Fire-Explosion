#define SDL_MAIN_HANDLED
#include <iostream>
#include <cstring>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"
using namespace caveofprogramming;
using namespace std;

int main() {

	srand(time(NULL));
	// time(NULL): returns the time in milliseconds
	// seeding the random number with a number. So that everytime a different
	// sequence of random numbers are created.

	Screen screen;

	if (screen.init() == false) {
		cout << "Error in SDL initialization" << endl;
	}

	Swarm swarm; //Create a swarm of particles

	while (true) {
		// Update Particles
		// Draw Particles
		int elapsed = SDL_GetTicks();	// Ticks since the loop started

		swarm.update(elapsed);
		unsigned char green = (unsigned char) ((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128);

		const Particle * const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];// copy that into temporary particle

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2; // access x coord of particle
			int y = particle.m_y* Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2; // access y coord of particle
			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		//Draw the screen
		screen.update();

		// Check for messages/events
		if (screen.processEvents() == false) {
			break;
		}

	}

	screen.close();
	return 0;
}
