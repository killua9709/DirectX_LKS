#pragma once
#include <GameEngineCore\GameEngineLevel.h>
#include <GameEngineCore/GameEngineTileMapRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineSound.h>
#include <GameEngineBase/GameEngineThread.h>

class MonsterData 
{
public:
	int Type = 0;
};

union TileIndex
{
public:
	struct 
	{
		int X;
		int Y;
	};
	__int64 Index;
};



// 설명 :
class TileMapLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	TileMapLevel();
	~TileMapLevel();

	// delete Function
	TileMapLevel(const TileMapLevel& _Other) = delete;
	TileMapLevel(TileMapLevel&& _Other) noexcept = delete;
	TileMapLevel& operator=(const TileMapLevel& _Other) = delete;
	TileMapLevel& operator=(TileMapLevel&& _Other) noexcept = delete;

	GameEngineSoundPlayer BgmPlayer;

	// 1Wave는 30초고 30마리가 나온다.
	// 6웨이브는 180초 180마리가 나온다.

	std::map<__int64, std::list<MonsterData>> MonsterWave;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	std::shared_ptr<GameEngineActor> TileMapPoint;
	std::shared_ptr<GameEngineTileMapRenderer> TileMap;
	std::shared_ptr<GameEngineSpriteRenderer> Sp;
	std::shared_ptr<GameEngineComponent> Pivot;
	std::shared_ptr<GameEngineComponent> Pivot2;
	std::shared_ptr<GameEngineRenderer> RollRender;
	std::shared_ptr<GameEngineRenderer> RollRender2;

	// 엔진자체가 쓰레드 대응할수 있게 만들어져있어
	// 쓰레드에서 안전하려면 무조건 락이 걸려있어야 합니다.
	// 락은 절대로 걸수 없다.
	// 느려지잖아. 
	// 쓰레드에서 액터만들기 => 자살행위
	GameEngineThread Thread;
};

