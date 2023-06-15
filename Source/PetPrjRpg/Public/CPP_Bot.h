// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h" 
#include "CPP_Bot.generated.h"


UCLASS(Blueprintable) 
class PETPRJRPG_API ACPP_Bot : public ACharacter
{
	GENERATED_BODY() //Макрос тела Класса
private: 
	UPROPERTY(BlueprintGetter=GetHealth,BlueprintSetter=SetHealth) 

	 float health;
public:
	// Sets default values for this character's properties
	ACPP_Bot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintPure)
	float GetHealth();
	UFUNCTION(BlueprintCallable)
		void SetHealth(UPARAM(ref)float& newHealth);
	
};
