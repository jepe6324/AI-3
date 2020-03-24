// Player.h

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include"Vector.h"

struct Tile;
struct SDL_Color;

struct Player
{
   Vector2 mousePos_;

   void Update();
   void UpdateMouse();

};

#endif // !PLAYER_H_INCLUDED
