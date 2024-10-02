// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "UObject/Object.h"
#include "AsyncTaskNode.generated.h"

/**
 * @brief Enum defining various named threads for executing asynchronous tasks.
 * 
 * @details This enum specifies different threads where the asynchronous task can be executed, 
 * including the RHI (Render Hardware Interface) thread, the Game thread, and more.
 */
UENUM(Blueprintable, BlueprintType)
enum class EBlueprintNamedThread : uint8
{
	/** Render Hardware Interface thread. */
	RHIThread,

	/** Game thread, usually the main thread. */
	GameThread,

	/** The actual rendering thread. */
	ActualRenderingThread,

	/** Execute on any available thread. */
	AnyThread,

	/** Local version of the game thread. */
	GameThread_Local,

	/** Local version of the rendering thread. */
	ActualRenderingThread_Local,

	/** Any high-priority thread for normal tasks. */
	AnyHiPriThreadNormalTask,

	/** Any high-priority thread for high-priority tasks. */
	AnyHiPriThreadHiPriTask,

	/** Any normal thread for normal tasks. */
	AnyNormalThreadNormalTask,

	/** Any normal thread for high-priority tasks. */
	AnyNormalThreadHiPriTask,

	/** Any background thread for normal tasks. */
	AnyBackgroundThreadNormalTask,

	/** Any background thread for high-priority tasks. */
	AnyBackgroundHiPriTask
};

/**
 * @brief Dynamic multicast delegate used for signaling async task node completion.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAsyncTaskNodeDelegate);

/**
 * @brief Asynchronous blueprint node for executing tasks on a named thread.
 *
 * @class UAsyncTaskNode
 * @details This class represents an asynchronous blueprint node that can execute a task 
 * on a specific named thread (such as the Game thread or the RHI thread). It uses a delegate 
 * system to notify when the async task starts and completes.
 */
UCLASS()
class ASYNCBLUEPRINTS_API UAsyncTaskNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/**
	 * @brief Constructor for the UAsyncTaskNode class.
	 * 
	 * @param ObjectInitializer Initialization object, default is the global object initializer.
	 */
	UAsyncTaskNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/**
	 * @brief Static method to initiate an asynchronous task on a specific named thread.
	 * 
	 * @details Starts an asynchronous task using the specified named thread for execution.
	 * 
	 * @param InWorldContextObject The context object in which the task is executed.
	 * @param InNamedThread The named thread where the task should execute (default is GameThread).
	 * 
	 * @note The 'Completed' event will be executed in the same thread as specified by the 'Thread' parameter.
	 * 
	 * @return A UAsyncTaskNode object.
	 */
	UFUNCTION(BlueprintCallable, Category="Async|Nodes",
		meta=(WorldContext="InWorldContextObject"), meta=(BlueprintInternalUseOnly="true"))
	static UAsyncTaskNode* AsyncTask(UObject* InWorldContextObject,
	                                 UPARAM(DisplayName="Thread") EBlueprintNamedThread InNamedThread =
		                                 EBlueprintNamedThread::GameThread);

public:
	/** Holds the named thread for the async task. */
	EBlueprintNamedThread NamedThread;

public:
	virtual void Activate() override;

	/** @brief Delegate broadcast when the async task is activated. */
	UPROPERTY(BlueprintAssignable, DisplayName="Async Task")
	FAsyncTaskNodeDelegate OnAsyncTask;

	/** @brief Delegate broadcast when the async task is completed. */
	UPROPERTY(BlueprintAssignable, DisplayName="Completed")
	FAsyncTaskNodeDelegate OnCompleted;
};
