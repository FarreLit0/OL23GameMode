// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TableActor.generated.h"

UCLASS()
class OL23_API ATableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Table")
	UStaticMeshComponent* TableTop;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Table")
	UStaticMeshComponent* TableLeg1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Table")
	UStaticMeshComponent* TableLeg2;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Table")
	UStaticMeshComponent* TableLeg3;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Table")
	UStaticMeshComponent* TableLeg4;

};
