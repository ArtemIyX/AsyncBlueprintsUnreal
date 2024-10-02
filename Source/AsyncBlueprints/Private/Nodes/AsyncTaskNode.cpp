// Fill out your copyright notice in the Description page of Project Settings.


#include "Nodes/AsyncTaskNode.h"

UAsyncTaskNode::UAsyncTaskNode(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer),
                                                                             NamedThread(
	                                                                             EBlueprintNamedThread::GameThread)
{
}

UAsyncTaskNode* UAsyncTaskNode::AsyncTask(UObject* InWorldContextObject, EBlueprintNamedThread InNamedThread)
{
	UWorld* world = GEngine->GetWorldFromContextObjectChecked(InWorldContextObject);
	UGameInstance* gi = world->GetGameInstance();
	UAsyncTaskNode* node = NewObject<UAsyncTaskNode>(gi);
	node->NamedThread = InNamedThread;
	return node;
}

void UAsyncTaskNode::Activate()
{
	Super::Activate();
	int32 cppNamedThread = ENamedThreads::Type::AnyThread;
	switch (NamedThread)
	{
	case EBlueprintNamedThread::RHIThread:
		cppNamedThread = ENamedThreads::Type::AnyThread;
		break;
	case EBlueprintNamedThread::GameThread:
		cppNamedThread = ENamedThreads::Type::GameThread;
		break;
	case EBlueprintNamedThread::ActualRenderingThread:
		cppNamedThread = ENamedThreads::Type::ActualRenderingThread;
		break;
	case EBlueprintNamedThread::AnyThread:
		cppNamedThread = ENamedThreads::Type::AnyThread;
		break;
	case EBlueprintNamedThread::GameThread_Local:
		cppNamedThread = ENamedThreads::Type::GameThread_Local;
		break;
	case EBlueprintNamedThread::ActualRenderingThread_Local:
		cppNamedThread = ENamedThreads::Type::ActualRenderingThread_Local;
		break;
	case EBlueprintNamedThread::AnyHiPriThreadNormalTask:
		cppNamedThread = ENamedThreads::Type::AnyHiPriThreadNormalTask;
		break;
	case EBlueprintNamedThread::AnyHiPriThreadHiPriTask:
		cppNamedThread = ENamedThreads::Type::AnyBackgroundHiPriTask;
		break;
	case EBlueprintNamedThread::AnyNormalThreadNormalTask:
		cppNamedThread = ENamedThreads::Type::AnyNormalThreadNormalTask;
		break;
	case EBlueprintNamedThread::AnyNormalThreadHiPriTask:
		cppNamedThread = ENamedThreads::Type::AnyNormalThreadHiPriTask;
		break;
	case EBlueprintNamedThread::AnyBackgroundThreadNormalTask:
		cppNamedThread = ENamedThreads::Type::AnyBackgroundThreadNormalTask;
		break;
	case EBlueprintNamedThread::AnyBackgroundHiPriTask:
		cppNamedThread = ENamedThreads::Type::AnyBackgroundHiPriTask;
		break;
	default: ;
	}
	::AsyncTask(static_cast<ENamedThreads::Type>(cppNamedThread), [this]()
	{
		OnAsyncTask.Broadcast();
		OnCompleted.Broadcast();
		SetReadyToDestroy();
	});
}
