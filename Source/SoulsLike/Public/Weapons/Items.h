

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.generated.h"

class UStaticMeshComponent;
class USphereComponent;
UCLASS()
class SOULSLIKE_API AItems : public AActor
{
	GENERATED_BODY()

public:

	AItems();
	virtual void Tick(float DeltaTime) override;
protected:

	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere)
		USphereComponent* Sphere;

public:



};
