#include "StageScene.h"

StageScene::StageScene(){
	inputmanager_ = InputManager::GetInstance();
	player_ = std::make_unique<Player>();
	enemy_ = std::make_unique<Enemy>();
}

void StageScene::Initialize(){
	player_->Initialize();
	enemy_->Initialize();
}

void StageScene::Update(){
	player_->Update();
	enemy_->Update();

	DrawImgui();

	CollisionChack();
}

void StageScene::Draw(){
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x0055aaff, kFillModeSolid);

	player_->Draw();
	enemy_->Draw();
}

void StageScene::CollisionChack(){
	const std::list<PlayerBullet*>& playerBullets = player_->GetBullets();

	for (PlayerBullet* bullet : playerBullets) {
		float a = bullet->GetPosition().x - enemy_->GetPosition().x;
		float b = bullet->GetPosition().y - enemy_->GetPosition().y;

		float distance = sqrtf(a * a + b * b);
		float totalRadius = bullet->GetRadius() + enemy_->GetRadius();

		if (distance <= totalRadius){
			bullet->OnCollision();
			SceneNumber = CLEAR;
		}
	}

}

void StageScene::DrawImgui(){
	ImGui::Begin("collision");
	const std::list<PlayerBullet*>& playerBullets = player_->GetBullets();
	for (PlayerBullet* bullet : playerBullets) {
		float a = bullet->GetPosition().x - enemy_->GetPosition().x;
		float b = bullet->GetPosition().y - enemy_->GetPosition().y;
		float distance = sqrtf(a * a + b * b);
		float totalRadius = bullet->GetRadius() + enemy_->GetRadius();
		
		ImGui::DragFloat("distance", &distance, 0.1f);
		ImGui::DragFloat("radius", &totalRadius, 0.1f);
	}
	ImGui::End();
}
