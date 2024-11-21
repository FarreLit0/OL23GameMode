// Fill out your copyright notice in the Description page of Project Settings.


#include "BallActor.h"

// Sets default values
ABallActor::ABallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	RootComponent = BallMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Engine/BasicShapes/Sphere"));
	if (SphereMeshAsset.Succeeded())
	{
		BallMesh->SetStaticMesh(SphereMeshAsset.Object);
	}

}

// Called when the game starts or when spawned
void ABallActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

