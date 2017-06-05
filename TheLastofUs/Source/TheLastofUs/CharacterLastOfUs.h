// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TheLastofUsCharacter.h"
#include "CharacterLastOfUs.generated.h"

/**
 * 
 */
UCLASS()
class THELASTOFUS_API ACharacterLastOfUs : public ATheLastofUsCharacter
{
	GENERATED_BODY()

	ACharacterLastOfUs();
	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
		class UInventoryComponent * InventoryComponent;
	
};
