// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AsyncBlueprintsLib.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ASYNCBLUEPRINTS_API UAsyncBlueprintsLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, DisplayName="Is In Game Thread", Category="Async")
	static bool BP_IsInGameThread();

	UFUNCTION(BlueprintCallable, DisplayName="Is In Parallel Game Thread", Category="Async")
	static bool BP_IsInParallelGameThread();

	UFUNCTION(BlueprintCallable, DisplayName="Is Audio Thread Running", Category="Async")
	static bool BP_IsAudioThreadRunning();

	UFUNCTION(BlueprintCallable, DisplayName="Is In Audio Thread", Category="Async")
	static bool BP_IsInAudioThread();

	UFUNCTION(BlueprintCallable, DisplayName="Is In Slate Thread", Category="Async")
	static bool BP_IsInSlateThread();

	UFUNCTION(BlueprintCallable, DisplayName="Is In Rendering Thread", Category="Async")
	static bool BP_IsInRenderingThread();

	UFUNCTION(BlueprintCallable, DisplayName="Is In Parallel Rendering Thread", Category="Async")
	static bool BP_IsInParallelRenderingThread();

	UFUNCTION(BlueprintCallable, DisplayName="Is In Actual Rendering Thread", Category="Async")
	static bool BP_IsInActualRenderingThread();

	UFUNCTION(BlueprintCallable, DisplayName="Is In Async Loading Thread", Category="Async")
	static bool BP_IsInAsyncLoadingThread();

	UFUNCTION(BlueprintCallable, DisplayName="Is RHI Thread Running", Category="Async")
	static bool BP_IsRHIThreadRunning();

	UFUNCTION(BlueprintCallable, DisplayName="Is In RHI Thread", Category="Async")
	static bool BP_IsInRHIThread();

	UFUNCTION(BlueprintCallable, DisplayName="Is In Parallel RHI Thread", Category="Async")
	static bool BP_IsInParallelRHIThread();
};
