#pragma once
#include"Vector2.h"
class Enemy{
public:
	void Initialize();
	void Update();
	void Draw();
public:
	float GetRadius()const { return Radius_; }

	Vector2 GetPosition()const { return Position_; }

private:
	Vector2 Position_;
	float Radius_;

	float moveSpeed_;

	const float moveMin = 0.0f;
	const float moveMax = 1280.0f;
};

