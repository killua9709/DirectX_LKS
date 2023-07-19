#include "PrecompileHeader.h"
#include "TitleLevel.h"
#include <GameEngineBase\GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
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

	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Sound");

		GameEngineSound::Load(NewDir.GetPlusFileName("Main.mp3").GetFullPath());
		BgmPlayer = GameEngineSound::Play("Main.mp3");
	}

	FEffect = GetLastTarget()->CreateEffect<FadeEffect>();

	GetMainCamera()->SetSortType(0, SortType::ZSort);
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	Logo = CreateActor<TestObject>();
	Logo->Render->SetTexture("Logo2.png");
	Logo->GetTransform()->SetLocalPosition({ 0, 45, -10.0f });
	Logo->Render.get()->GetTransform()->SetWorldScale({ 242, 376 });
	Logo->Render->Off();

	Logo2 = CreateActor<TestObject>();
	Logo2->Render->SetTexture("Logo2.png");
	Logo2->GetTransform()->SetLocalPosition({ 610, -320, -10.0f });
	Logo2->Render.get()->GetTransform()->SetWorldScale({ 60.5f, 94 });
	Logo2->Render.get()->GetTransform()->AddLocalScale({ 1, 1, 0.0f });
	Logo2->Render->Off();

	Logo3 = CreateActor<TestObject>();
	Logo3->Render->SetTexture("키보드.png");
	Logo3->GetTransform()->SetLocalPosition({ 0, 150, -10.0f });
	Logo3->Render.get()->GetTransform()->SetWorldScale({ 1237.0f, 693 });
	Logo3->Render->Off();

	Logo4 = CreateActor<TestObject>();
	Logo4->Render->SetTexture("제작진2.png");
	Logo4->GetTransform()->SetLocalPosition({ 0, 0, -10.0f });
	Logo4->Render.get()->GetTransform()->SetWorldScale({ 250, 35 });
	Logo4->Render->Off();

	BackBlack = CreateActor<TestObject>();
	BackBlack->Render->SetTexture("Black.png");
	BackBlack->GetTransform()->SetLocalPosition({ 0.0f, 0.0f, 0.0f });
	BackBlack->Render->SetScaleToTexture("Black.png");

	BackGround = CreateActor<TestObject>();
	BackGround->Render->SetTexture("Titlebackground.png");
	BackGround->GetTransform()->SetLocalPosition({ 0.0f, 0.0f, -5.0f });
	BackGround->Render.get()->GetTransform()->SetWorldScale({ 1920, 1080 });
	BackGround->Render->Off();

	Button1 = CreateActor<GameEngineButton>();
	Button1->Render->SetTexture("게임시작.png");
	Button1->GetTransform()->SetLocalPosition({ 0.0f, -45.0f, -10.0f });
	Button1->Render.get()->GetTransform()->SetWorldScale({ 118, 28 });
	Button1->Off();


	Button2 = CreateActor<GameEngineButton>();
	Button2->Render->SetTexture("조작방법.png");
	Button2->GetTransform()->SetLocalPosition({ 0.0f, -135.0f, -10.0f });
	Button2->Render.get()->GetTransform()->SetWorldScale({ 118, 28 });
	Button2->SetEvent([&]() {Logo->Render->Off(); Logo4->Render->On(); Button1->Off(); Button2->Off(); Button3->Off(); Button4->Off(); Button5->On(); });
	Button2->Off();


	Button3 = CreateActor<GameEngineButton>();
	Button3->Render->SetTexture("제작진.png");
	Button3->GetTransform()->SetLocalPosition({ 0.0f, -225.0f, -10.0f });
	Button3->Render.get()->GetTransform()->SetWorldScale({ 118, 28 });
	Button3->SetEvent([&]() {Logo->Render->Off(); Logo3->Render->On(); Button1->Off(); Button2->Off(); Button3->Off(); Button4->Off(); Button5->On(); });
	Button3->Off();


	Button4 = CreateActor<GameEngineButton>();
	Button4->Render->SetTexture("게임종료.png");
	Button4->GetTransform()->SetLocalPosition({ 0.0f, -315.0f, -10.0f });
	Button4->Render.get()->GetTransform()->SetWorldScale({ 118, 28 });
	Button4->Off();


	Button5 = CreateActor<GameEngineButton>();
	Button5->Render->SetTexture("뒤로.png");
	Button5->GetTransform()->SetLocalPosition({ 0.0f, -315.0f, -10.0f });
	Button5->Render.get()->GetTransform()->SetWorldScale({ 118, 28 });
	Button5->SetEvent([&]() {Logo->Render->On(); Logo3->Render->Off(); Logo4->Render->Off(); Button1->On(); Button2->On(); Button3->On(); Button4->On(); Button5->Off(); });
	Button5->Off();

}

void TitleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("LevelChangeKey"))
	{
		GameEngineCore::ChangeLevel("TitleMapLevel");
	}

	if (LogoTime < 15.0f)
	{

		LogoTime += _DeltaTime;

	}


	if (LogoTime > 1.0f && First == false && LogoTime < 3.0f)
	{
		Logo->Render->On();
		FEffect->FadeOut();
		First = true;
	}

	if (LogoTime > 1.0f && First == true && LogoTime < 3.0f)
	{
		Logo->Render.get()->GetTransform()->AddLocalScale({ _DeltaTime * 20, _DeltaTime * 20, 0.0f });
	}

	if (LogoTime > 3.0f && First == true && LogoTime < 5.0f)
	{
		FEffect->FadeIn();
		First = false;
	}

	if (LogoTime > 5.0f && First == false && LogoTime < 9.0f)
	{
		Logo->Render->SetTexture("TitleText.png");
		Logo->GetTransform()->SetLocalPosition({ 0.0f, 0.0f, -10.0f });
		Logo->Render.get()->GetTransform()->SetWorldScale({ 948, 595 });
		BackGround->Render->On();
		FEffect->FadeOut();
		First = true;
	}

	if (LogoTime > 9.0f && First == true && LogoTime < 11.0f)
	{
		FEffect->FadeIn();
		First = false;
	}

	if (LogoTime > 11.2f && First == false && LogoTime < 12.2f)
	{
		Logo->Render->SetTexture("Logo4.png");
		Logo->GetTransform()->SetLocalPosition({ 0.0f, 215.0f, -10.0f });
		Logo->Render.get()->GetTransform()->SetWorldScale({ 905, 332 });
		BackGround->Render->Off();
		FEffect->FadeOut();
		First = true;
	}

	if (LogoTime > 12.2f && First == true && LogoTime < 13.2f)
	{
		First = false;
	}

	if (LogoTime > 13.2f && First == false && LogoTime < 14.2f)
	{
		Button1->On();
		Button2->On();
		Button3->On();
		Button4->On();
		BackGround->Render->On();
		Logo2->Render->On();
		First = true;
	}

}