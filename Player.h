#pragma once
#include"InputManager.h"
#include"PlayerBullet.h"
#include"ImGuiManager.h"
#include<list>

class Player{
	
public:
	Player();
	~Player();

	void Initialize();
	void Update();
	void shot();
	void Draw();

public:
	// 弾リストを取得
	const std::list<PlayerBullet*>& GetBullets() { return bullets_; }

private:
	Vector2 position_;
	float radius_;

	float moveSpeed_;

	std::list<PlayerBullet*> bullets_;

	// 発射の時間
	int bulletTime = 0;

	// 自機の弾の発射間隔
	int bulletInterval = 10;
	
	InputManager* inputmanager_ = nullptr;

private:
	void DrawImgui();
};

