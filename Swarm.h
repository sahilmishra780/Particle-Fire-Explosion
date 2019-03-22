/*
 * Swarm.h
 *
 *  Created on: Feb 17, 2019
 *      Author: Sahil
 */

#ifndef SWARM_H_
#define SWARM_H_
#include "Particle.h"

namespace caveofprogramming {

class Swarm {
public:
	const static int NPARTICLES = 5000;
private:
	Particle * m_pParticles;
	int lastTime;

public:
	Swarm();
	const Particle * const getParticles() {
		return m_pParticles;
	} // Constant pointer to constant particle
	virtual ~Swarm();
	void update(int elapsed);
};

} /* namespace caveofprogramming */

#endif /* SWARM_H_ */
