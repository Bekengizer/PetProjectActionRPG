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
	UPROPERTY(BlueprintReadWrite, EditAnywhere) //�������� ������� � unreal ��� ���� ������
		TArray<int> ourIntArray;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) //�������� ������� � unreal ��� ���� ������
		TMap<FString,int32> myMap;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Health; //�� ������, 
//������� �� ���������� ������ ����� ������� � ������� ��� ������ ���������, �� ��� �������� ��� ���

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
		void testBPFunc(int x); //�� ��������� ����������� ����� ������� ����� ������� � ���������� ��� � BP
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void testBPNativeFunc(float x);//�������� �����, ���������� �������� ����� ������� ����� � �++
	void testBPNativeFunc_Implementation(float x);//��������� ��������� ������, ������ ���������� ������ ���� �� �� ������������ ����� � BP
};
