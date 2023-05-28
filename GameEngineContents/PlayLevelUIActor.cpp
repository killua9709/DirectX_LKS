#include "PrecompileHeader.h"
#include "PlayLevelUIActor.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

PlayLevelUIActor::PlayLevelUIActor() 
{
}

PlayLevelUIActor::~PlayLevelUIActor() 
{
}

void PlayLevelUIActor::Start() 
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });

	{
		// HPBar
		std::shared_ptr<GameEngineUIRenderer> Render = CreateComponent<GameEngineUIRenderer>();
		Render->GetTransform()->SetLocalPosition({-500.0f, 300.0f});
		Render->GetTransform()->SetLocalScale({300.0f, 50.0f, 1.0f});
	}

	{
		// HPBar
		std::shared_ptr<GameEngineUIRenderer> Render = CreateComponent<GameEngineUIRenderer>();
		Render->GetTransform()->SetLocalPosition({ 500.0f, 300.0f });
		Render->GetTransform()->SetLocalScale({ 150.0f, 150.0f, 1.0f });
	}

}

void PlayLevelUIActor::Update(float _Delta) 
{

}