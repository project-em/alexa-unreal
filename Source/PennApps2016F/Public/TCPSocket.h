// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Networking.h"
#include "TCPSocket.generated.h"

class FSocketThread; // avoid repeated imports

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAlexaEvent, int32, event_id);
UCLASS()
class PENNAPPS2016F_API ATCPSocket : public AActor
{
	GENERATED_BODY()
	
private:
	FSocket* socket;
	FSocketThread* socketThread;
	FRunnableThread* Thread;
	FThreadSafeCounter StopTaskCounter;
public:	
	// Sets default values for this actor's properties
	ATCPSocket();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called when the game ends or when destroyed
	virtual void BeginDestroy() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category="Socket")
	void CreateSocket();

	UFUNCTION(BLueprintCallable, Category = "Socket")
	void AcceptClient();

	UFUNCTION(BLueprintCallable, Category = "Socket")
	void ShutdownSocket();
	
	UPROPERTY(BlueprintReadWrite, Category = "Socket")
	int32 port;

	UPROPERTY(BlueprintReadWrite, Category = "Socket")
	FString address;

	UPROPERTY(BlueprintAssignable)
	FAlexaEvent ReceivedAlexaEvent;
};
