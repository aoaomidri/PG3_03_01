#include "ICommand.h"
ICommand::~ICommand()
{
}


void MoveRightCommand::Exec(Player& player){
	player.MoveRight();
}

void MoveLeftCommand::Exec(Player& player){
	player.MoveLeft();
}

void MoveUpCommand::Exec(Player& player){
	player.MoveUp();
}

void MoveDownCommand::Exec(Player& player){
	player.MoveDown();
}

void ShotCommand::Exec(Player& player){
	player.shot();
}
