#include "PrecompileHeader.h"
#include "TitleLevel.h"
#include <GameEngineBase\GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "FadeEffect.h"


#include "TestObject.h"

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}


void TitleLevel::Start()
{

	if (false == GameEngineInput::IsKey("LevelChangeKey"))
	{
		GameEngineInput::CreateKey("LevelChangeKey", 'I');
	}

	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("Title");

		std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });


		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineTexture::Load(File[i].GetFullPath());
		}
	}

	FEffect = GetLastTarget()->CreateEffect<FadeEffect>();

	GetMainCamera()->SetSortType(0, SortType::ZSort);
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	Logo = CreateActor<TestObject>();
	Logo->Render->SetTexture("Logo2.png");
	Logo->GetTransform()->SetLocalPosition({ 0, 45, -10.0f });
	Logo->GetTransform()->SetWorldScale({ 242, 376 });
	Logo->Render->Off();

	Logo2 = CreateActor<TestObject>();
	Logo2->Render->SetTexture("Logo2.png");
	Logo2->GetTransform()->SetLocalPosition({ 610, -320, -10.0f });
	Logo2->GetTransform()->SetWorldScale({ 60.5f, 94 });
	Logo2->Render->Off();

	BackBlack = CreateActor<TestObject>();
	BackBlack->Render->SetTexture("Black.png");
	BackBlack->GetTransform()->SetLocalPosition({ 0.0f, 0.0f, 0.0f });
	BackBlack->Render->SetScaleToTexture("Black.png");

	BackGround = CreateActor<TestObject>();
	BackGround->Render->SetTexture("Titlebackground.png");
	BackGround->GetTransform()->SetLocalPosition({ 0.0f, 0.0f, -5.0f });
	BackGround->GetTransform()->SetWorldScale({ 1920, 1080 });
	BackGround->Render->Off();

}

void TitleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("LevelChangeKey"))
	{
		GameEngineCore::ChangeLevel("TutoLevel");
	}

	LogoTime += _DeltaTime;


	//Logo2->Render->On();

	if (LogoTime > 1.0f && First == false && LogoTime < 3.0f)
	{
		Logo->Render->On();
		FEffect->FadeOut();
		First = true;
	}

	if (LogoTime > 1.0f && First == true && LogoTime < 3.0f)
	{
		Logo->GetTransform()->AddLocalScale({ _DeltaTime * 10, _DeltaTime * 10, 0.0f });
	}

	if (LogoTime > 3.0f && First == true && LogoTime < 4.0f)
	{
		FEffect->FadeIn();
		First = false;
	}

	if (LogoTime > 4.0f && First == false && LogoTime < 7.0f)
	{
		Logo->Render->SetTexture("TitleText.png");
		Logo->GetTransform()->SetLocalPosition({ 0.0f, 0.0f, -10.0f });
		Logo->GetTransform()->SetWorldScale({ 948, 595 });
		BackGround->Render->On();
		FEffect->FadeOut();
		First = true;
	}

	if (LogoTime > 7.0f && First == true && LogoTime < 8.0f)
	{
		FEffect->FadeIn();
		First = false;
	}

	if (LogoTime > 8.0f && First == false)
	{
		Logo->Render->SetTexture("Logo.png");
		Logo->GetTransform()->SetLocalPosition({ -4.0f, 215.0f, -10.0f });
		Logo->GetTransform()->SetWorldScale({ 1274, 521 });
		Logo2->Render->On();
		FEffect->FadeOut();
		First = true;

	}
}