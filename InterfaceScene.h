#pragma once
#include <Novice.h>
#include"InputManager.h"


enum SCENE {
	TITLE,
	STAGE,
	CLEAR
};

class InterfaceScene{
protected:
	//シーン番号を管理する変数
	static int SceneNumber;
	
public:
	//抽象クラスなので純粋仮想関数
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	//仮想デストラクタ
	virtual ~InterfaceScene();

	//シーン番号のゲッター
	static int GetSceneNumber() { return SceneNumber; }

};

