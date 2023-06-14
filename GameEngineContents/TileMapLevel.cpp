#include "PrecompileHeader.h"
#include "TileMapLevel.h"
#include <GameEngineBase\GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>


TileMapLevel::TileMapLevel() 
{
}

TileMapLevel::~TileMapLevel() 
{
}


void TileMapLevel::Start() 
{
	if (false == GameEngineInput::IsKey("TilePointLeft"))
	{
		GameEngineInput::CreateKey("TilePointLeft", 'A');
		GameEngineInput::CreateKey("TilePointRight", 'D');
		GameEngineInput::CreateKey("TilePointUp", 'W');
		GameEngineInput::CreateKey("TilePointDown", 'S');
		GameEngineInput::CreateKey("TilePointChange", 'E');
	}

	if (nullptr == GameEngineSprite::Find("TileMap"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");

		// TestAnimation.png

		GameEngineSprite::LoadSheet(NewDir.GetPlusFileName("FOGWAR.png").GetFullPath(), 3, 1);

		// std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });
	}


	if (false == GameEngineInput::IsKey("LevelChangeKey"))
	{
		GameEngineInput::CreateKey("LevelChangeKey", 'I');
	}

	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });

	std::shared_ptr<GameEngineActor> NewGame = CreateActor<GameEngineActor>();
	TileMap = NewGame->CreateComponent<GameEngineTileMapRenderer>();

	TileMap->CreateTileMap(10, 10, { 100, 50 }, { 100 * 1.2f, 50 * 1.2f}, TileMapMode::Iso);

	for (size_t y = 0; y < TileMap->GetCount().y; y++)
	{
		for (size_t x = 0; x < TileMap->GetCount().x; x++)
		{
			TileMap->SetTile(x, y, "FOGWAR.png", 0);
		}
	}

	TileMapPoint = CreateActor<GameEngineActor>();
	std::shared_ptr<GameEngineSpriteRenderer> Sp = TileMapPoint->CreateComponent<GameEngineSpriteRenderer>();
	Sp->GetTransform()->SetLocalScale({10.0f, 10, 1.0f});
}

void TileMapLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("LevelChangeKey"))
	{
		GameEngineCore::ChangeLevel("PlayLevel");
	}

	float Speed = 100.f;

	if (true == GameEngineInput::IsPress("TilePointLeft"))
	{
		TileMapPoint->GetTransform()->AddLocalPosition(float4::Left * _DeltaTime * Speed);
	}

	if (true == GameEngineInput::IsPress("TilePointRight"))
	{
		TileMapPoint->GetTransform()->AddLocalPosition(float4::Right * _DeltaTime * Speed);
	}

	if (true == GameEngineInput::IsPress("TilePointUp"))
	{
		TileMapPoint->GetTransform()->AddLocalPosition(float4::Up * _DeltaTime * Speed);
	}

	if (true == GameEngineInput::IsPress("TilePointDown"))
	{
		TileMapPoint->GetTransform()->AddLocalPosition(float4::Down * _DeltaTime * Speed);
	}

	if (true == GameEngineInput::IsDown("TilePointChange"))
	{
		TileMap->SetTile(TileMapPoint->GetTransform()->GetWorldPosition(), "FOGWAR.png", 2);
	}

}