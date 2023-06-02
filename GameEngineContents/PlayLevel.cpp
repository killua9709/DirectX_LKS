#include "PrecompileHeader.h"
#include "PlayLevel.h"
#include "Player.h"
#include "TestObject.h"
#include "PlayLevelUIActor.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineVideo.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
#include "FadeEffect.h"

#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineSprite.h>

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Start()
{
	if (false == GameEngineInput::IsKey("FadeIn"))
	{
		GameEngineInput::CreateKey("FadeIn", '1');
		GameEngineInput::CreateKey("FadeOut", '2');
	}

	if (false == GameEngineInput::IsKey("LevelChangeKey"))
	{
		GameEngineInput::CreateKey("LevelChangeKey", 'I');
	}

	{
		/*GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Texture");
		NewDir.Move("BackGround");

		std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });


		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineTexture::Load(File[i].GetFullPath());
		}*/

		
	}

	GetMainCamera()->SetSortType(0, SortType::ZSort);
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->GetTransform()->SetLocalPosition({0, 0, -1000.0f});

	FEffect = GetLastTarget()->CreateEffect<FadeEffect>();

	std::shared_ptr<GameEngineCoreWindow> Window = GameEngineGUI::FindGUIWindowConvert<GameEngineCoreWindow>("CoreWindow");

	{
		Window->Test = std::bind(&PlayLevel::PlayerCreate, this);

		Object0 = CreateActorToName<Player>("fasdfdsa");
		Object0->GetTransform()->SetLocalPosition({ -100.0f, 0.0f, 0.0f });

		Object1 = CreateActor<TestObject>(-20);
		Object1->GetTransform()->SetLocalPosition({150.0f, 0.0f, 0.0f});
		Object1->Render->GetTransform()->SetLocalScale({100.0f, 100.0f, 100.0f});

		// RenderTest = Object1->CreateComponent<GameEngineSpriteRenderer>();

		//RenderTest->GetTransform()->SetLocalPosition({ 100.0f, 0.0f, 0.0f });
		//RenderTest->GetTransform()->SetLocalScale({ 100.0f, 100.0f, 100.0f });

		Object1->GetTransform()->SetParent(Object0->GetTransform());


		//std::shared_ptr<TestObject> Object2 = CreateActor<TestObject>(-20);
		//Object2->GetTransform()->SetLocalPosition({ 400.0f, 0.0f, 0.0f });
		//Object2->Render->GetTransform()->SetLocalScale({ 100.0f, 100.0f, 100.0f });

		//Object2->GetTransform()->SetParent(Object1->GetTransform());

		{
			Object3 = CreateActor<TestObject>(-20);
			Object3->GetTransform()->SetLocalPosition({ 000.0f, 200.0f, 0.0f });
			Object3->Render->GetTransform()->SetLocalScale({ 1000.0f, 1000.0f, 100.0f });

			std::shared_ptr<GameEngineCollision> Col = Object3->CreateComponent<GameEngineCollision>(2000);
			Col->GetTransform()->SetLocalScale({ 100.0f, 100.0f, 100.0f });
		}

		{
			Object3 = CreateActor<TestObject>(-20);
			Object3->GetTransform()->SetLocalPosition({ -100.0f, 200.0f, 0.0f });
			Object3->Render->GetTransform()->SetLocalScale({ 100.0f, 100.0f, 100.0f });

			std::shared_ptr<GameEngineCollision> Col = Object3->CreateComponent<GameEngineCollision>(2000);
			Col->GetTransform()->SetLocalScale({ 100.0f, 100.0f, 100.0f });
		}
	}


	std::shared_ptr<PlayLevelUIActor> Object = CreateActor<PlayLevelUIActor>(1000);

	//{
	//	std::shared_ptr<TestObject> Object = CreateActor<TestObject>(-20);
	//	Object->GetTransform()->SetLocalScale({ 1000, 1000, 1000 });
	//	Object->GetTransform()->SetLocalPosition({ 0, 0, 100.0f });
	//}


}

void PlayLevel::Update(float _DeltaTime)
{
	if (Object3->Render->GetTransform()->Collision({ Object1->Render->GetTransform(), ColType::OBBBOX3D, ColType::OBBBOX3D }))
	{
		int a = 0;
	}

	if (true == GameEngineInput::IsDown("LevelChangeKey"))
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}

	if (true == GameEngineInput::IsPress("FadeIn"))
	{
		std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(0);

		//Camera->AddZoomRatio(-_DeltaTime);

		 FEffect->FadeIn();
	}

	if (true == GameEngineInput::IsPress("FadeOut"))
	{
		/*std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(0);
		Camera->AddZoomRatio(_DeltaTime);*/
		 FEffect->FadeOut();
	}



	//if (nullptr != Object1 && 1.0f <= Object1->GetLiveTime())
	//{
	//	if (nullptr == Object1)
	//	{
	//		return;
	//	}
	//	// RenderTest->Death();
	//	Object1->Death();
	//	Object1 = nullptr;
	//}
}

void PlayLevel::LevelChangeStart()
{
	GameEngineLevel::LevelChangeStart();
	int a = 0;
}

void PlayLevel::LevelChangeEnd() 
{
	GameEngineLevel::LevelChangeEnd();
	int a = 0;
}

void PlayLevel::PlayerCreate(/*Playlevel* this*/)
{
	if (nullptr != Object1)
	{
		RenderTest->GetTransform()->SetParent(Object3->GetTransform());
	}

}