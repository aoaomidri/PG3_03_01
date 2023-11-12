#include "Player.h"
#include<Novice.h>
Player::Player() {
	inputmanager_ = InputManager::GetInstance();
}

Player::~Player(){
	for (PlayerBullet* bullet : bullets_) {
		delete bullet;
	}
}

void Player::Initialize(){
	bullets_.clear();

	position_ = { 640.0f,600.0f };
	radius_ = 25.0f;
	moveSpeed_ = 4.0f;
}

void Player::Update(){
	// デスフラグの立った球を削除
	bullets_.remove_if([](PlayerBullet* bullet) {
		if (bullet->IsDead()) {
			delete bullet;
			return true;
		}
		return false;
	});

	if (inputmanager_->PushKey(DIK_RIGHT)){
		position_.x += moveSpeed_;
	}
	if (inputmanager_->PushKey(DIK_LEFT)) {
		position_.x -= moveSpeed_;
	}
	if (inputmanager_->PushKey(DIK_UP)) {
		position_.y -= moveSpeed_;
	}
	if (inputmanager_->PushKey(DIK_DOWN)) {
		position_.y += moveSpeed_;
	}

	shot();

	for (PlayerBullet* bullet : bullets_) {
		bullet->Update();
	}

	DrawImgui();

}

void Player::shot(){
	//ALのをひっぱってきただけ
	if (inputmanager_->PushKey(DIK_SPACE)) {
		bulletTime += 1;
		if (bulletTime % bulletInterval == 1) {

			// 弾の速度
			const float kBulletSpeed = 10.0f;

			Vector2 velocity = { 0.0f,kBulletSpeed };
			// 弾を生成し、初期化
			PlayerBullet* newBullet = new PlayerBullet();
			newBullet->Initialize(position_,velocity);
			// 弾を登録する
			bullets_.push_back(newBullet);
		}
	}
	else {
		bulletTime = 0;
	}
}

void Player::Draw(){
	Novice::DrawEllipse(static_cast<int>(position_.x), static_cast<int>(position_.y), static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, 0xffffffff, kFillModeSolid);

	for (PlayerBullet* bullet : bullets_) {
		bullet->Draw();
	}
}

void Player::DrawImgui(){
	ImGui::Begin("Bullets");
	for (PlayerBullet* bullet : bullets_) {
		bullet->DrawImgui();
	}

	ImGui::End();
}
