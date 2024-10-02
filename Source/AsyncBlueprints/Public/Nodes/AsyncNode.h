// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncNode.generated.h"

/**
 * @brief Enum defining various execution modes for asynchronous tasks.
 * 
 * @details This enum describes where the asynchronous task will be executed, including options for running 
 * the task on the main thread, in a separate thread, or in a global thread pool.
 */
UENUM(Blueprintable, BlueprintType)
enum class EBlueprintAsyncExecution : uint8
{
	/** Execute in Task Graph (for short running tasks). */
	TaskGraph,

	/** Execute in Task Graph on the main thread (for short running tasks). */
	TaskGraphMainThread,

	/** Execute in separate thread if supported (for long running tasks). */
	Thread,

	/** Execute in separate thread if supported or supported post fork (see FForkProcessHelper::CreateThreadIfForkSafe) (for long running tasks). */
	ThreadIfForkSafe,

	/** Execute in global queued thread pool. */
	ThreadPool
};

/**
 * @brief Dynamic multicast delegate used for signaling async node completion.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAsyncNodeDelegate);

/**
 * @brief Asynchronous blueprint node for executing tasks.
 *
 * @class UAsyncNode
 * @details This class represents an asynchronous blueprint node that can execute a task in various contexts 
 * (such as Task Graph or a separate thread). It uses a delegate system to notify when the async task starts 
 * and completes.
 */
UCLASS()
class ASYNCBLUEPRINTS_API UAsyncNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/**
	 * @brief Constructor for the UAsyncNode class.
	 * 
	 * @param ObjectInitializer Initialization object, default is the global object initializer.
	 */
	UAsyncNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/**
	 * @brief Static method to initiate an asynchronous execution in Blueprints.
	 * 
	 * @details Starts an asynchronous task using the specified execution context.
	 * 
	 * @param InWorldContextObject The context object in which the task is executed.
	 * @param InAsyncExecution The execution mode (task graph, thread, etc.).
	 * 
	 * @note The 'Completed' event will be executed in the same thread as specified by the 'Execution' parameter.
	 * 
	 * @return A UAsyncNode object.
	 */
	UFUNCTION(BlueprintCallable, Category="Async|Nodes",
		meta=(WorldContext="InWorldContextObject"), meta=(BlueprintInternalUseOnly="true"))
	static UAsyncNode* Async(UObject* InWorldContextObject,
	                         UPARAM(DisplayName="Execution") EBlueprintAsyncExecution InAsyncExecution);

public:
	/** Holds the execution mode for the async task. */
	EBlueprintAsyncExecution AsyncExecution;
public:
	virtual void Activate() override;

	/** @brief Delegate broadcast when the async is activated. */
	UPROPERTY(BlueprintAssignable, DisplayName="Async")
	FAsyncNodeDelegate OnAsync;

	/** @brief Delegate broadcast when the async is completed. */
	UPROPERTY(BlueprintAssignable, DisplayName="Completed")
	FAsyncNodeDelegate OnCompleted;
};
