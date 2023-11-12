#include "ClearStage.h"

ClearStage::ClearStage(){
	inputmanager_ = InputManager::GetInstance();
}

void ClearStage::Initialize(){

}

void ClearStage::Update(){
	
	if (inputmanager_->TrigerKey(DIK_RETURN)) {
		SceneNumber = TITLE;
	}
}

void ClearStage::Draw(){
	DrawImgui();
}

void ClearStage::DrawImgui(){
	ImGui::Begin("Clear tips");
	ImGui::Text("Push Enter key to go to next scene");
	ImGui::End();
}
