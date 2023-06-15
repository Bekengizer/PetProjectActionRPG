// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Bot.h"

// Sets default values
ACPP_Bot::ACPP_Bot()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Bot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Bot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_Bot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
float ACPP_Bot::GetHealth()
{
	return health;
}

void ACPP_Bot::SetHealth(UPARAM(ref)float& newHealth)
{
	health = newHealth;
}

