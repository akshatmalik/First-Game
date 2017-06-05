// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterLastOfUs.h"
#include "InventoryComponent.h"



ACharacterLastOfUs::ACharacterLastOfUs()
{
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(FName("Pickup Components "));
}
