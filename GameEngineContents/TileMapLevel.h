#pragma once
#include <GameEngineCore\GameEngineLevel.h>
#include <GameEngineCore/GameEngineTileMapRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
// Ό³Έν :
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

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	std::shared_ptr<GameEngineActor> TileMapPoint;
	std::shared_ptr<GameEngineTileMapRenderer> TileMap;
};

