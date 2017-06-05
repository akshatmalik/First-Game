// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"
#include "Gameplay/Inventory/PickableObject.h"

//
//// Sets default values for this component's properties
//UInventoryComponent::UInventoryComponent()
//{
//	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
//	// off to improve performance if you don't need them.
//	PrimaryComponentTick.bCanEverTick = true;
//
//	// ...
//}
//
//
//// Called when the game starts
//void UInventoryComponent::BeginPlay()
//{
//	Super::BeginPlay();
//
//	// ...
//	
//}
//
//
//// Called every frame
//void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}
//

void UInventoryComponent::AddToInventory(FString Name, int32 Amount)
{
	//#Implement add functionality that enable to add if not present and increase if present
	if (InventoryList.Contains(Name) == false)
	{
		InventoryList.Add(Name, Amount);
		UE_LOG(LogTemp, Warning, TEXT("%s is not in inventory, adding amount %i"), *Name, *InventoryList.Find(Name));
	}
	else
	{
		int32 * TempAmount = InventoryList.Find(Name);
		*TempAmount = *TempAmount + Amount;
		InventoryList.Add(Name, *TempAmount);
		UE_LOG(LogTemp, Warning, TEXT("%s is in inventory, amount %i"), *Name, *InventoryList.Find(Name));
	}
}

bool UInventoryComponent::FindAmount(FString Name, int32 & Amount)
{
	//#ErrorCheck 
	if (InventoryList.Contains(Name) == true)
	{
		Amount =  *InventoryList.Find(Name);
		return true;
	}
	else
	{
		Amount = NULL;
		return false;
	}
}

void UInventoryComponent::CheckSurrounding()
{
	FString Name;
	int32 Amount;
	TArray <AActor *> OverlappingActors;
	TSubclassOf<APickableObject> TypeOfOverlapped;
	GetOwner()->GetOverlappingActors(OverlappingActors, TypeOfOverlapped);
	for (int32 i=0;i<OverlappingActors.Num();i++)
	{
		APickableObject * CastedActor = Cast<APickableObject>(OverlappingActors[i]);
		//UE_LOG(LogTemp, Warning, TEXT("Overlapping actor found"));
		CastedActor->GetPickUpProps(Name, Amount);
		//UE_LOG(LogTemp, Warning, TEXT("%s has amount %i"), *Name, Amount);
		AddToInventory(Name, Amount);
	}
}