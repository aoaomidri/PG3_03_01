#pragma once
#include"InterfaceScene.h"

class StageScene :public InterfaceScene{
public:
	StageScene();

	void Initialize()override;
	void Update()override;
	void Draw()override;

private:
	InputManager* inputmanager_ = nullptr;
};

