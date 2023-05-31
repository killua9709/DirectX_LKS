#pragma once
#include <GameEngineCore\GameEngineLevel.h>

// Ό³Έν :
class TutoLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	TutoLevel();
	~TutoLevel();

	// delete Function
	TutoLevel(const TutoLevel& _Other) = delete;
	TutoLevel(TutoLevel&& _Other) noexcept = delete;
	TutoLevel& operator=(const TutoLevel& _Other) = delete;
	TutoLevel& operator=(TutoLevel&& _Other) noexcept = delete;

	std::shared_ptr<class FadeEffect> FEffect;


protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	std::shared_ptr<class TestObject> BackBlack;
	std::shared_ptr<class TestObject> Logo;
	std::shared_ptr<class TestObject> Logo2;
	std::shared_ptr<class TestObject> BackGround;

	float LogoTime = 0;
	bool First = false;

};

