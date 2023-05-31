#include "PrecompileHeader.h"
#include "Button.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>

Button::Button()
{
}

Button::~Button()
{
}


void Button::Update(float _DeltaTime)
{

}

void Button::Start()
{
	Render = CreateComponent<GameEngineSpriteRenderer>();
	Render->CameraCullingOn();
}