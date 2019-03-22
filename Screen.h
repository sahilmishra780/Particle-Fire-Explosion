/*
 * Screen.h
 *
 *  Created on: Feb 17, 2019
 *      Author: Sahil
 */

#ifndef SCREEN_H_
#define SCREEN_H_
#include<SDL.h>
#include<cstring>

namespace caveofprogramming {

class Screen {
public:
	const int static SCREEN_WIDTH = 800;
	const int static SCREEN_HEIGHT = 600;
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;
public:
	Screen();
	bool init();
	void update();
	void boxBlur();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	bool processEvents();
	void close();
};

} /* namespace caveofprogramming */

#endif /* SCREEN_H_ */
