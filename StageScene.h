#pragma once
#include"InterfaceScene.h"
#include"Player.h"
#include"Enemy.h"
#include"InputHandler.h"
#include"ICommand.h"

class StageScene :public InterfaceScene{
public:
	StageScene();
	~StageScene();

	void Initialize()override;
	void Update()override;
	void Draw()override;

	void CollisionChack();

	void DrawImgui();

private:
	InputManager* inputmanager_ = nullptr;

	std::unique_ptr<Player> player_;

	std::unique_ptr<Enemy> enemy_;

	InputHandler* inputHandler_ = nullptr;

	ICommand* iCommand_ = nullptr;
};

