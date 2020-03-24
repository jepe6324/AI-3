#include "..\Include\Player.h"

#include "Tile.h"
#include "Config.h"

#include "Service.h"
#include "InputHandler.h"
#include "TEST_STATE_1.h"

void Player::Update()
{
   UpdateMouse();
}

void Player::UpdateMouse()
{
   mousePos_.x_ = Service<InputHandler>::Get()->GetMousePositionX();
   mousePos_.y_ = Service<InputHandler>::Get()->GetMousePositionY();

   mousePos_ = mousePos_ / Config::TILE_SIZE;
   mousePos_.x_ /= Config::SCALE_WIDTH;
   mousePos_.y_ /= Config::SCALE_HEIGHT;
}


