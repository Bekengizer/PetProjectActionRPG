// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CPP_Pickup.h"
#include "CPP_MainChar.generated.h"

UCLASS()
class PETPRJRPG_API ACPP_MainChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_MainChar();
	UPROPERTY(BlueprintReadWrite, EditAnywhere) //создание массива в unreal как поле данных
		TArray<int> ourIntArray;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) //создание массива в unreal как поле данных
		TMap<FString,int32> myMap;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Health; //Хп игрока, 
//конечно же правильнее доступ через геттеры и сеттеры или вообще интерфейс, но для простоты вот так

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable)
	void RemovePickup();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent) 
		void testBPFunc(int x); //не требуется определение ивент который можно вызвать а реализация его в BP
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void testBPNativeFunc(float x);//Нативный ивент, реализацию которого можно описать здесь в с++
	void testBPNativeFunc_Implementation(float x);//реализция нативного ивента, логика вызывается отсюда если ты не прописываешь ивент в BP
};
