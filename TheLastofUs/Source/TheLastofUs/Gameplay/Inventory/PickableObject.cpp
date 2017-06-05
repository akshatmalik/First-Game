// Fill out your copyright notice in the Description page of Project Settings.

#include "PickableObject.h"


void APickableObject::GetPickUpProps(FString & NameToSet, int32 & AmountToSet)
{
	AmountToSet = Amount;
	NameToSet = Name;

	Destroy();
}
