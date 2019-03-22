/*
 * Particle.h
 *
 *  Created on: Feb 17, 2019
 *      Author: Sahil
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace caveofprogramming {
// In a struct by default variables are public if you don't specify an access modifier like private
// In a class by default variables are private if you don't specify an access modifier like public
// That is the only difference between a class and a struct.
struct Particle {

	double m_x;
	double m_y;
private:
	double m_speed;
	double m_direction;
private:
	void init();

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

} /* namespace caveofprogramming */

#endif /* PARTICLE_H_ */
