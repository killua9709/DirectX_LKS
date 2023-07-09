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



// ���� :
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

	// 1Wave�� 30�ʰ� 30������ ���´�.
	// 6���̺�� 180�� 180������ ���´�.

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

	// ������ü�� ������ �����Ҽ� �ְ� ��������־�
	// �����忡�� �����Ϸ��� ������ ���� �ɷ��־�� �մϴ�.
	// ���� ����� �ɼ� ����.
	// �������ݾ�. 
	// �����忡�� ���͸���� => �ڻ�����
	GameEngineThread Thread;
};

