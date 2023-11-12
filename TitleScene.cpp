#include "TitleScene.h"
#include"ImGuiManager.h"

TitleScene::TitleScene(){
	inputmanager_ = InputManager::GetInstance();
}

void TitleScene::Initialize(){

}

void TitleScene::Update(){
	
	if (inputmanager_->TrigerKey(DIK_RETURN)) {
		SceneNumber = STAGE;
	}
}

void TitleScene::Draw(){
	DrawImgui();

	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x005555ff, kFillModeSolid);
}

void TitleScene::DrawImgui(){
	ImGui::Begin("Title tips");
	ImGui::Text("Push Enter key to go to next scene");
	ImGui::End();
}
