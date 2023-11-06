#include "TitleScene.h"
#include"ImGuiManager.h"

TitleScene::TitleScene(){
	inputmanager_ = InputManager::GetInstance();
}

void TitleScene::Initialize(){

}

void TitleScene::Update(){
	inputmanager_->Update();
	if (inputmanager_->TrigerKey(DIK_RETURN)) {
		SceneNumber = STAGE;
	}
}

void TitleScene::Draw(){
	ImGui::Begin("Test");
	ImGui::End();

	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x005555ff, kFillModeSolid);
}
