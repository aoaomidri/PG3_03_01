#include "InputHandler.h"

ICommand* InputHandler::HandlerInput(){
	if (Novice::CheckHitKey(DIK_D)){
		return pressKeyD_;
	}
	else if (Novice::CheckHitKey(DIK_A)) {
		return pressKeyA_;
	}
	else if (Novice::CheckHitKey(DIK_W)) {
		return pressKeyW_;
	}
	else if (Novice::CheckHitKey(DIK_S)) {
		return pressKeyS_;
	}
	else if (Novice::CheckHitKey(DIK_SPACE)) {
		return pressKeySpace_;
	}


	return nullptr;
}

void InputHandler::AssignMoveLeftCommandtoPressKeyA(){
	ICommand* command = new MoveLeftCommand();
	this->pressKeyA_ = command;
}

void InputHandler::AssignMoveRightCommandtoPressKeyD(){
	ICommand* command = new MoveRightCommand();
	this->pressKeyD_ = command;
}

void InputHandler::AssignMoveUpCommandtoPressKeyW(){
	ICommand* command = new MoveUpCommand();
	this->pressKeyW_ = command;
}

void InputHandler::AssignMoveDownCommandtoPressKeyS(){
	ICommand* command = new MoveDownCommand();
	this->pressKeyS_ = command;
}

void InputHandler::AssigndShotCommandtoPressKeySpace(){
	ICommand* command = new ShotCommand();
	this->pressKeySpace_ = command;
}
