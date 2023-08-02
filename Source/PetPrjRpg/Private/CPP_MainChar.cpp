// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MainChar.h"

// Sets default values
ACPP_MainChar::ACPP_MainChar()
{
	ourIntArray = { 25,79,6,7 };// инициализирую массив в конструкторе
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 100;
	
}

// Called when the game starts or when spawned
void ACPP_MainChar::BeginPlay()
{
	Super::BeginPlay();
	testBPFunc(100);
	ourIntArray.Add(50); //ћассив динамический и тут просто добавл€ем в конец
	ourIntArray.Emplace(4); // создает обьект сразу не использу€ копирование или перемещение
	ourIntArray.Remove(25); // ”даление сравнением
	ourIntArray.RemoveAt(0);// ”даление по индексу

	myMap.Emplace("First", 32);
	int32 TempInt = myMap["First"];
//	for (auto& ele : ourIntArray) 
	//{
	//	UKismetSystemLibrary::PrintString(this, FString::SanitizeFloat(ele)); // SanitizeFloat преобразует каждый элемент массива под string есть еще fromInt
	//}
}

// Called every frame
void ACPP_MainChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_MainChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPP_MainChar::RemovePickup()
{
	auto temp = UGameplayStatics::GetPlayerCameraManager(this, 0);
	
	auto EndTrace = temp->GetCameraLocation() + (temp->GetActorForwardVector() * 50000);
	TArray<AActor*> ignore;
	FHitResult hit;
	UKismetSystemLibrary::LineTraceSingle(this, temp->GetCameraLocation(), EndTrace,ETraceTypeQuery::TraceTypeQuery1,false, ignore,EDrawDebugTrace::ForDuration,hit,true);
	if (hit.GetActor()) 
	{
		if(Cast<IMyInterface>(hit.GetActor()))
		{
			Cast<IMyInterface>(hit.GetActor())->Destruct();
			UKismetSystemLibrary::PrintString(this, "Pickup Destroyed");
		}
	}
}

void ACPP_MainChar::testBPNativeFunc_Implementation(float x)
{
	UKismetSystemLibrary::PrintString(this, "C++ implementation called");
}









