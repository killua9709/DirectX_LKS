#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Button : public GameEngineActor
{
public:
	// constrcuter destructer
	Button();
	~Button();

	// delete Function
	Button(const Button& _Other) = delete;
	Button(Button&& _Other) noexcept = delete;
	Button& operator=(const Button& _Other) = delete;
	Button& operator=(Button&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineSpriteRenderer> Render;

protected:
	void Start();
	void Update(float _Delta) override;

private:
};

