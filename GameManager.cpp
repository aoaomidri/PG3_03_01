#include "GameManager.h"

GameManager::GameManager(){
	inputManager_ = std::make_unique<InputManager>();

	sceneArray_[TITLE] = std::make_unique<TitleScene>();
	sceneArray_[STAGE] = std::make_unique<StageScene>();
	sceneArray_[CLEAR] = std::make_unique<ClearStage>();


	currentSceneNumber_ = TITLE;
}

GameManager::~GameManager(){

}

void GameManager::Initialize(){
	const char kWindowTitle[] = "LE2A_23_ムラカミ_アオイ";

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
}

int GameManager::GameLoop(){

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		inputManager_->Update();

		//シーンのチェック
		preSceneNumber_ = currentSceneNumber_;
		currentSceneNumber_ = sceneArray_[currentSceneNumber_]->GetSceneNumber();

		//シーン変更チェック
		if (preSceneNumber_!=currentSceneNumber_){
			sceneArray_[currentSceneNumber_]->Initialize();
		}

		///
		/// ↓更新処理ここから
		///

		sceneArray_[currentSceneNumber_]->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		sceneArray_[currentSceneNumber_]->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (inputManager_->TrigerKey(DIK_ESCAPE)) {
			break;
		}
	}

	return 0;
}

void GameManager::Finalize(){
	// ライブラリの終了
	Novice::Finalize();
}
