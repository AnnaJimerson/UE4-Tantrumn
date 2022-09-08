// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret_enm.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATurret_enm::ATurret_enm()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATurret_enm::BeginPlay()
{
	Super::BeginPlay();
	
	// default target is player
	if(!m_target)
		m_target = Cast<AMyCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

// Called every frame
void ATurret_enm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATurret_enm::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATurret_enm::shootTarget()
{
	if (!m_target) return;

	FHitResult Hit;

	// Get our trace coords
	FVector TraceStart = GetActorLocation() + GetActorForwardVector() * 80.f;
	FVector TraceEnd = m_target->GetActorLocation();

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	// Line trace for any pawns
	GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Pawn, QueryParams);

	// Draw the line we used to trace
	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, Hit.bBlockingHit ? FColor::Blue : FColor::Red, false, 5.0f, 0, 10.0f);
	UE_LOG(LogTemp, Log, TEXT("Tracing line: %s to %s"), *TraceStart.ToCompactString(), *TraceEnd.ToCompactString());

	// Do stuff with the actor
	if (Hit.bBlockingHit && IsValid(Hit.GetActor())){
		UE_LOG(LogTemp, Log, TEXT("Trace hit actor: %s"), *Hit.GetActor()->GetName());

		AMyCharacter* hitTarget = Cast<AMyCharacter>(Hit.GetActor());

		if (hitTarget) {
			hitTarget->GetHealthComponent()->TakeDamage(damageDealt);
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleSystem, hitTarget->GetActorTransform());
		}
	}
}

void ATurret_enm::beginShootTarget()
{
	// Call shootTarget once per second, starting 1.5 seconds from now.
	GetWorldTimerManager().SetTimer(shootTimer, this, &ATurret_enm::shootTarget, 1.0f, true, 1.5f);
}

void ATurret_enm::endShootTarget()
{
	// Stop shootTarget repeating calls
	GetWorldTimerManager().SetTimer(shootTimer, this, &ATurret_enm::shootTarget, 0.f, false, 0.f);
}

