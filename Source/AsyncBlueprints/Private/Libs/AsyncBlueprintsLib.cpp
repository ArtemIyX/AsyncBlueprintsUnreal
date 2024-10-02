// Fill out your copyright notice in the Description page of Project Settings.


#include "Libs/AsyncBlueprintsLib.h"

bool UAsyncBlueprintsLib::BP_IsInGameThread()
{
	return IsInGameThread();
}


bool UAsyncBlueprintsLib::BP_IsInParallelGameThread()
{
	return IsInParallelGameThread();
}

bool UAsyncBlueprintsLib::BP_IsAudioThreadRunning()
{
	return IsAudioThreadRunning();
}

bool UAsyncBlueprintsLib::BP_IsInAudioThread()
{
	return IsInAudioThread();
}

bool UAsyncBlueprintsLib::BP_IsInSlateThread()
{
	return IsInSlateThread();
}

bool UAsyncBlueprintsLib::BP_IsInRenderingThread()
{
	return IsInRenderingThread();
}

bool UAsyncBlueprintsLib::BP_IsInParallelRenderingThread()
{
	return IsInParallelRenderingThread();
}

bool UAsyncBlueprintsLib::BP_IsInActualRenderingThread()
{
	return IsInActualRenderingThread();
}

bool UAsyncBlueprintsLib::BP_IsInAsyncLoadingThread()
{
	return IsInAsyncLoadingThread();
}

bool UAsyncBlueprintsLib::BP_IsRHIThreadRunning()
{
	return IsRHIThreadRunning();
}

bool UAsyncBlueprintsLib::BP_IsInRHIThread()
{
	return IsInRHIThread();
}

bool UAsyncBlueprintsLib::BP_IsInParallelRHIThread()
{
	return IsInParallelRHIThread();
}
