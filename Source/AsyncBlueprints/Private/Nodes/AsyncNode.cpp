// Fill out your copyright notice in the Description page of Project Settings.


#include "Nodes/AsyncNode.h"

UAsyncNode::UAsyncNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer),
                                                                      AsyncExecution(EBlueprintAsyncExecution::Thread)
{
}

UAsyncNode* UAsyncNode::Async(UObject* InWorldContextObject, EBlueprintAsyncExecution InAsyncExecution)
{
	UWorld* world = GEngine->GetWorldFromContextObjectChecked(InWorldContextObject);
	UGameInstance* gi = world->GetGameInstance();
	UAsyncNode* node = NewObject<UAsyncNode>(gi);
	node->AsyncExecution = InAsyncExecution;
	return node;
}


void UAsyncNode::Activate()
{
	Super::Activate();
	uint8 byte = static_cast<uint8>(AsyncExecution);
	EAsyncExecution cppAsyncExecution = static_cast<EAsyncExecution>(byte);

	::Async(cppAsyncExecution,
	        [this]()
	        {
		        OnAsync.Broadcast();
	        }, [this]()
	        {
		        OnCompleted.Broadcast();
	        	SetReadyToDestroy();
	        });
}
