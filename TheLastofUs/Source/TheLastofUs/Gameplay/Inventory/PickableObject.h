// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickableObject.generated.h"

UCLASS()
class THELASTOFUS_API APickableObject : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Initialize")
		void GetPickUpProps(FString & NameToSet, int32 & AmountToSet);

	UPROPERTY(EditAnywhere, Category = "Setup")
		FString Name = "";

	UPROPERTY(EditAnywhere, Category = "Setup")
		int32 Amount = 1;
};
