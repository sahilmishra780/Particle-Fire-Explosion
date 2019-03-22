/*
 * Swarm.cpp
 *
 *  Created on: Feb 17, 2019
 *      Author: Sahil
 */

#include "Swarm.h"

namespace caveofprogramming {

Swarm::Swarm() {
	m_pParticles = new Particle[NPARTICLES];
	lastTime = 0;

}

Swarm::~Swarm() {
	delete[] m_pParticles;
}
void Swarm::update(int elapsed) {
	int interval = elapsed - lastTime;
	for (int i = 0; i < Swarm::NPARTICLES; i++) {
		m_pParticles[i].update(interval);
	}
	lastTime = elapsed;
}

} /* namespace caveofprogramming */
