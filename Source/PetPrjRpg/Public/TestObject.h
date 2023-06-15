// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/KismetSystemLibrary.h" //Важная библиотека UE5, здесь для PrintString
#include "TestObject.generated.h"
/**
 * 
 */
UENUM(BlueprintType) //ue перечисление, BlueprintType значит что это будет тип видимый при выборе типа переменной в BP
enum FruitLust
{
	Apple UMETA(DisplayName = "Apple 1"),
	Mango UMETA(DisplayName = "Mango 1"),
	Banana UMETA(DisplayName = "Banana 1"),
};
USTRUCT(BlueprintType) //макрос для структур UE5
struct FBook // структура UE5
{
	GENERATED_USTRUCT_BODY() //макрос тела структуры
		UPROPERTY(BlueprintReadOnly, EditAnywhere) //это нужно чтобы разделить структуру в blueprint editor
		FString Name; // строки UE5
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int numOfPages;

};
UCLASS(Blueprintable)// макрос Класса UE5 // Изначает что можно создать блюпринт наследуясь от этого класса
class PETPRJRPG_API UTestObject : public UObject
{
	GENERATED_BODY()//Макрос тела Класса
private:
		UPROPERTY(BlueprintGetter = GetHealth, BlueprintSetter = SetHealth) // макрос для переменной UE5
		float health;
public:
	UTestObject();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)// макрос для переменной UE5, может быть считана и перезаписана и откуда угодно редактируктся
		int myPublicInt;
	UFUNCTION(BlueprintPure)// Макрос для функции UE5 // pure значит вызывает без входных pin
		float GetHealth();
	UFUNCTION(BlueprintCallable)//BlueprintCallable значит можно вызвать в BP правой кнопкой мыши
		void SetHealth(UPARAM(ref)float& newHealth);
	UFUNCTION(BlueprintCallable)
		void Test(UPARAM(ref)FBook& target, UObject* context);
};
