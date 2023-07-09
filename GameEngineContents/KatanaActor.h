#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

// Ư�� �����ӿ����� ���� �ؽ�ó
// ���� ��ġ�� ����� ���°� �Դϴ�.
// 1�ʿ� 200�� 300���� ���̴°�.
// �ð� ������ �Ѽ��� �ְ�.
class ReverseInfo 
{
public:
	TransformData ActorData;
	TransformData RendererData;
	SpriteInfo Info;
};

// 
// ���� :
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


