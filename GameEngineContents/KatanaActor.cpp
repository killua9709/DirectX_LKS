#include "PrecompileHeader.h"
#include "KatanaActor.h"

KatanaActor::KatanaActor() 
{
}

KatanaActor::~KatanaActor() 
{
}

// �� �����Ѱ�
// 

// ī�޶� ������ ������
// ī�޶� �� ����ī�޶�� �����̴ٰ��� �ٽ� ������� ���ƿü� �ְ� ������ ¥����.

// �Ųٷ� ������ ������ ������ ��ġ���� �̰� ȣ���ϸ�
void KatanaActor::Reverse(class GameEngineSpriteRenderer* _Renderer)
{
	if (true == Infos.empty())
	{
		return;
	}
	

	// �Ųٷ� ���.
	ReverseInfo& Info = *(Infos.rbegin());

	// ������ ��ġ
	// �������� ��ġ �������ְ�
	// �������� �ؽ�ó�� 
	// ��Ʋ�� ������ �������ָ�.

	Infos.pop_back();

}

// ������ ��ġ���� �̰� ȣ���ض�.
void KatanaActor::InfoSetting(class GameEngineSpriteRenderer* _Renderer)
{
	SpriteInfo Info;

	GameEngineTextureSetter* Tex = _Renderer->GetShaderResHelper().GetTextureSetter("DiffuseTex");
	Info.Texture = Tex->Res;
	Info.CutData = _Renderer->GetAtlasData();

	Infos.push_back({ _Renderer->GetActor()->GetTransform()->GetTransDataRef(), _Renderer->GetTransform()->GetTransDataRef(), Info});
}