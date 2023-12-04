#pragma once
#include"ICommand.h"
#include<Novice.h>
class InputHandler{
public:
	ICommand* HandlerInput();

	void AssignMoveLeftCommandtoPressKeyA();
	void AssignMoveRightCommandtoPressKeyD();
	void AssignMoveUpCommandtoPressKeyW();
	void AssignMoveDownCommandtoPressKeyS();
	void AssigndShotCommandtoPressKeySpace();

private:
	ICommand* pressKeyD_;
	ICommand* pressKeyA_;
	ICommand* pressKeyW_;
	ICommand* pressKeyS_;
	ICommand* pressKeySpace_;
	
};

