#pragma once
#include <GameEngineCore\GameEngineLevel.h>

// ���� :
class TitleLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	TitleLevel();
	~TitleLevel();

	// delete Function
	TitleLevel(const TitleLevel& _Other) = delete;
	TitleLevel(TitleLevel&& _Other) noexcept = delete;
	TitleLevel& operator=(const TitleLevel& _Other) = delete;
	TitleLevel& operator=(TitleLevel&& _Other) noexcept = delete;

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

