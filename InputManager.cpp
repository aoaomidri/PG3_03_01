#include "InputManager.h"
#include<Novice.h>

InputManager* InputManager::GetInstance(){
	static InputManager instance;
	return &instance;
}

void InputManager::Initialize(){
	for (int i = 0; i < 256; i++) {
		keys[i] = 0;
		preKeys[i] = 0;
	}
}

void InputManager::Update(){
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

}

bool InputManager::PushKey(BYTE keyNumber)const {
	if (keys[keyNumber]){
		return true;
	}
	else {
		return false;
	}
}

bool InputManager::TrigerKey(BYTE keyNumber)const {
	if (keys[keyNumber]&&!preKeys[keyNumber]) {
		return true;
	}
	else {
		return false;
	}
}

bool InputManager::ReleseKey(BYTE keyNumber)const {
	if (!keys[keyNumber] && preKeys[keyNumber]) {
		return true;
	}
	else {
		return false;
	}
}
