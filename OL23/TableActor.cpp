// Fill out your copyright notice in the Description page of Project Settings.


#include "TableActor.h"

// Sets default values
ATableActor::ATableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TableTop = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TableTop"));
	RootComponent = TableTop;


    static ConstructorHelpers::FObjectFinder<UStaticMesh> TableTopMesh(TEXT("/Engine/BasicShapes/Cube"));
    if (TableTopMesh.Succeeded())
    {
        TableTop->SetStaticMesh(TableTopMesh.Object);
        TableTop->SetRelativeScale3D(FVector(3.0f, 2.0f, 0.2f)); // Scale for the table top
    }


    TableLeg1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TableLeg1"));
    TableLeg1->SetupAttachment(TableTop);
    TableLeg1->SetRelativeLocation(FVector(-100.f, -50.f, -100.f));
    TableLeg1->SetRelativeScale3D(FVector(0.2f, 0.2f, 1.0f));

    TableLeg2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TableLeg2"));
    TableLeg2->SetupAttachment(TableTop);
    TableLeg2->SetRelativeLocation(FVector(100.f, -50.f, -100.f));
    TableLeg2->SetRelativeScale3D(FVector(0.2f, 0.2f, 1.0f));

    TableLeg3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TableLeg3"));
    TableLeg3->SetupAttachment(TableTop);
    TableLeg3->SetRelativeLocation(FVector(-100.f, 50.f, -100.f));
    TableLeg3->SetRelativeScale3D(FVector(0.2f, 0.2f, 1.0f));

    TableLeg4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TableLeg4"));
    TableLeg4->SetupAttachment(TableTop);
    TableLeg4->SetRelativeLocation(FVector(100.f, 50.f, -100.f));
    TableLeg4->SetRelativeScale3D(FVector(0.2f, 0.2f, 1.0f));

}

// Called when the game starts or when spawned
void ATableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

