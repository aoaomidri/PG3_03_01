#pragma once
#include"Input.h"
class InputManager{
public:

	static InputManager* GetInstance();

	void Initialize();

	void Update();

	bool PushKey(BYTE keyNumber)const;

	bool TrigerKey(BYTE keyNumber)const;

	bool ReleseKey(BYTE keyNumber)const;

private:

	// キー入力結果を受け取る箱
	char keys[256];
	char preKeys[256];

};

