#pragma once
#include"Vector2.h"
class PlayerBullet{
public:
	~PlayerBullet();

	void Initialize(const Vector2& position, const Vector2& velocity);

	void Update();

	void Draw();

	bool IsDead() const { return isDead_; }

	Vector2 GetPosition() const { return position_; }

	float GetRadius() const { return radius_; }

	void DrawImgui();

	// 衝突したら呼び出す関数
	void OnCollision();
	
private:
	float radius_ = 10.0f;

	Vector2 position_;

	Vector2 velocity_;
	// デスフラグ
	bool isDead_ = false;
};

