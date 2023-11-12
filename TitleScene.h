#pragma once
#include"InterfaceScene.h"

class TitleScene :public InterfaceScene {
public:
	TitleScene();

	void Initialize()override;
	void Update()override;
	void Draw()override;

	void DrawImgui();

private:
	InputManager* inputmanager_ = nullptr;
};

