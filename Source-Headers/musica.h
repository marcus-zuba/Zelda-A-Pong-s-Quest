#ifndef MUSICA_H
#define MUSICA_H

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

Mix_Chunk * load_music(char const file[40]);
void play_music(Mix_Chunk * music, int channel, int loop);
void stop_music(int channel);
void play_SFX(Mix_Chunk * sfx);

#endif