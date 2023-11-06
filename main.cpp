#include"GameManager.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {	
	std::unique_ptr<GameManager> gameManager_ = std::make_unique<GameManager>();
	gameManager_->Initialize();

	gameManager_->GameLoop();

	gameManager_->Finalize();
	return 0;
}
