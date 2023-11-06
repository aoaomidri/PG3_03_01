﻿#pragma once
#include"InterfaceScene.h"

class ClearStage :public InterfaceScene {
public:
	ClearStage();

	void Initialize()override;
	void Update()override;
	void Draw()override;

private:
	InputManager* inputmanager_ = nullptr;
};

