// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/KismetSystemLibrary.h" //������ ���������� UE5, ����� ��� PrintString
#include "TestObject.generated.h"
/**
 * 
 */
UENUM(BlueprintType) //ue ������������, BlueprintType ������ ��� ��� ����� ��� ������� ��� ������ ���� ���������� � BP
enum FruitLust
{
	Apple UMETA(DisplayName = "Apple 1"),
	Mango UMETA(DisplayName = "Mango 1"),
	Banana UMETA(DisplayName = "Banana 1"),
};
USTRUCT(BlueprintType) //������ ��� �������� UE5
struct FBook // ��������� UE5
{
	GENERATED_USTRUCT_BODY() //������ ���� ���������
		UPROPERTY(BlueprintReadOnly, EditAnywhere) //��� ����� ����� ��������� ��������� � blueprint editor
		FString Name; // ������ UE5
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int numOfPages;

};
UCLASS(Blueprintable)// ������ ������ UE5 // �������� ��� ����� ������� �������� ���������� �� ����� ������
class PETPRJRPG_API UTestObject : public UObject
{
	GENERATED_BODY()//������ ���� ������
private:
		UPROPERTY(BlueprintGetter = GetHealth, BlueprintSetter = SetHealth) // ������ ��� ���������� UE5
		float health;
public:
	UTestObject();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)// ������ ��� ���������� UE5, ����� ���� ������� � ������������ � ������ ������ �������������
		int myPublicInt;
	UFUNCTION(BlueprintPure)// ������ ��� ������� UE5 // pure ������ �������� ��� ������� pin
		float GetHealth();
	UFUNCTION(BlueprintCallable)//BlueprintCallable ������ ����� ������� � BP ������ ������� ����
		void SetHealth(UPARAM(ref)float& newHealth);
	UFUNCTION(BlueprintCallable)
		void Test(UPARAM(ref)FBook& target, UObject* context);
};
