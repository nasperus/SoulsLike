


#include "Weapons/Items.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

AItems::AItems()
{

	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMehs"));
	RootComponent = StaticMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());

}


void AItems::BeginPlay()
{
	Super::BeginPlay();

}


void AItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

