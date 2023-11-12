#pragma once
#include"InterfaceScene.h"
#include"ImGuiManager.h"


class ClearStage :public InterfaceScene {
public:
	ClearStage();

	void Initialize()override;
	void Update()override;
	void Draw()override;

	void DrawImgui();

private:
	InputManager* inputmanager_ = nullptr;
};

