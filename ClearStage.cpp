#include "ClearStage.h"

ClearStage::ClearStage(){
	inputmanager_ = InputManager::GetInstance();
}

void ClearStage::Initialize(){

}

void ClearStage::Update(){
	inputmanager_->Update();
	if (inputmanager_->TrigerKey(DIK_RETURN)) {
		SceneNumber = TITLE;
	}
}

void ClearStage::Draw(){

}
