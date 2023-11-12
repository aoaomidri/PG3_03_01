#include "Enemy.h"
#include<Novice.h>
void Enemy::Initialize(){
	Position_ = { 640.0f,100.0f };
	Radius_ = 50.0f;

	moveSpeed_ = 5.0f;
}

void Enemy::Update(){
	//Position_.x += moveSpeed_;
	if (Position_.x > moveMax) {
		moveSpeed_ *= -1;
	}
	else if (Position_.x < moveMin) {
		moveSpeed_ *= -1;
	}
}

void Enemy::Draw(){
	Novice::DrawEllipse(static_cast<int>(Position_.x), static_cast<int>(Position_.y), static_cast<int>(Radius_), static_cast<int>(Radius_), 0.0f, 0xffffffff, kFillModeSolid);

}
