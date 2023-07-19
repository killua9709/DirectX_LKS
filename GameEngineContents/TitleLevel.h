#pragma once
#include <GameEngineCore\GameEngineLevel.h>
#include <GameEngineCore/GameEngineButton.h>
#include <GameEnginePlatform/GameEngineSound.h>


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
	GameEngineSoundPlayer BgmPlayer;


protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:

	//������Ʈ
	std::shared_ptr<class TestObject> BackBlack;
	std::shared_ptr<class TestObject> Logo;
	std::shared_ptr<class TestObject> Logo2;
	std::shared_ptr<class TestObject> Logo3;
	std::shared_ptr<class TestObject> Logo4;
	std::shared_ptr<class TestObject> BackGround;

	//������Ʈ����
	float LogoTime = 0;
	bool First = false;

	//��ư ������Ʈ
	std::shared_ptr<class GameEngineButton> Button1;
	std::shared_ptr<class GameEngineButton> Button2;
	std::shared_ptr<class GameEngineButton> Button3;
	std::shared_ptr<class GameEngineButton> Button4;
	std::shared_ptr<class GameEngineButton> Button5;
};

