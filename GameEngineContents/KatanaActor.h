#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

// 특정 프레임에서의 나의 텍스처
// 나의 위치를 기록해 놓는것 입니다.
// 1초에 200개 300개씩 쌓이는것.
// 시간 제한을 둘수도 있고.
class ReverseInfo 
{
public:
	TransformData ActorData;
	TransformData RendererData;
	SpriteInfo Info;
};

// 
// 설명 :
class KatanaActor : public GameEngineActor
{
public:
	// constrcuter destructer
	KatanaActor();
	~KatanaActor();

	// delete Function
	KatanaActor(const KatanaActor& _Other) = delete;
	KatanaActor(KatanaActor&& _Other) noexcept = delete;
	KatanaActor& operator=(const KatanaActor& _Other) = delete;
	KatanaActor& operator=(KatanaActor&& _Other) noexcept = delete;

protected:
	void Reverse(class GameEngineSpriteRenderer* _Renderer);
	void InfoSetting(class GameEngineSpriteRenderer* _Renderer);
	void ClearInfo() 
	{
		Infos.clear();
	}

private:
	std::list<ReverseInfo> Infos;

};


