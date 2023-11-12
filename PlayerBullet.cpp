#include "PlayerBullet.h"
#include<Novice.h>
#include"ImGuiManager.h"

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Initialize(const Vector2& position, const Vector2& velocity)
{
	position_ = position;
	velocity_ = velocity;
}

void PlayerBullet::Update(){
	if (position_.y < -10) {
		isDead_ = true;
	}

	position_.y -= velocity_.y;
}

void PlayerBullet::Draw(){
	Novice::DrawEllipse(static_cast<int>(position_.x), static_cast<int>(position_.y), static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, 0xffffffff, kFillModeSolid);
}


void PlayerBullet::DrawImgui(){
	
	ImGui::DragFloat2("Position", &position_.x, 0.1f);
	
}

void PlayerBullet::OnCollision()
{
	isDead_ = true;
}
