#include "PrecompileHeader.h"
#include "KatanaActor.h"

KatanaActor::KatanaActor() 
{
}

KatanaActor::~KatanaActor() 
{
}

// 좀 위험한게
// 

// 카메라를 참고해 보세요
// 카메라가 막 프리카메라로 움직이다가도 다시 원래대로 돌아올수 있게 구조를 짜놨어.

// 거꾸로 돌리고 싶을때 적절한 위치에서 이걸 호출하면
void KatanaActor::Reverse(class GameEngineSpriteRenderer* _Renderer)
{
	if (true == Infos.empty())
	{
		return;
	}
	

	// 거꾸로 비긴.
	ReverseInfo& Info = *(Infos.rbegin());

	// 액터의 위치
	// 랜더러위 우치 세팅해주고
	// 랜더러의 텍스처와 
	// 아틀라스 데이터 세팅해주면.

	Infos.pop_back();

}

// 적절한 위치에서 이걸 호출해라.
void KatanaActor::InfoSetting(class GameEngineSpriteRenderer* _Renderer)
{
	SpriteInfo Info;

	GameEngineTextureSetter* Tex = _Renderer->GetShaderResHelper().GetTextureSetter("DiffuseTex");
	Info.Texture = Tex->Res;
	Info.CutData = _Renderer->GetAtlasData();

	Infos.push_back({ _Renderer->GetActor()->GetTransform()->GetTransDataRef(), _Renderer->GetTransform()->GetTransDataRef(), Info});
}