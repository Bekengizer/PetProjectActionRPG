// Fill out your copyright notice in the Description page of Project Settings.


#include "TestObject.h"
UTestObject::UTestObject() 
{

};
float UTestObject::GetHealth()
{
	return health;
}

void UTestObject::SetHealth(UPARAM(ref)float& newHealth)
{
	health = newHealth;
}
void  UTestObject::Test(UPARAM(ref)FBook& target, UObject* context)
{
	UKismetSystemLibrary::PrintString(context, "TestFuncCalled");
}
