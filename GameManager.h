#pragma once
#include<memory>
#include"TitleScene.h"
#include"StageScene.h"
#include"ClearStage.h"
#include"InputManager.h"

class GameManager{
public:
	GameManager();
	~GameManager();

	void Initialize();

	int GameLoop();

	void Finalize();

private:
	//シーンを保持するメンバ変数
	std::unique_ptr<InterfaceScene> sceneArray_[3];

	std::unique_ptr<InputManager> inputManager_;

	//どのステージを呼び出すかを管理する変数
	//現在のシーン
	int currentSceneNumber_;
	//前のシーン
	int preSceneNumber_;


};

