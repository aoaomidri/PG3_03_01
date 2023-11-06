#include "StageScene.h"

StageScene::StageScene(){
	inputmanager_ = InputManager::GetInstance();
}

void StageScene::Initialize(){

}

void StageScene::Update(){
	inputmanager_->Update();
	if (inputmanager_->TrigerKey(DIK_RETURN)) {
		SceneNumber = CLEAR;
	}
}

void StageScene::Draw(){
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x0055ffff, kFillModeSolid);
}
