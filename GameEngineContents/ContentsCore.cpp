#include "PrecompileHeader.h"
#include "ContentsCore.h"
#include <GameEngineCore\GameEngineCore.h>
#include "PlayLevel.h"
#include "TitleLevel.h"
#include "TutoLevel.h"
#include <GameEngineCore/GameEngineCoreWindow.h>



ContentsCore::ContentsCore() 
{
}

ContentsCore::~ContentsCore() 
{
}


void ContentsCore::GameStart() 
{


	GameEngineGUI::GUIWindowCreate<GameEngineCoreWindow>("CoreWindow");


	ContentsResourcesCreate();

	GameEngineCore::CreateLevel<TitleLevel>();
	GameEngineCore::CreateLevel<TutoLevel>();
	GameEngineCore::CreateLevel<PlayLevel>();
	GameEngineCore::ChangeLevel("TitleLevel");
}

void ContentsCore::GameEnd() 
{

}