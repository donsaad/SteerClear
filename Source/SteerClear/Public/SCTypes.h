
#pragma once

#include "SCTypes.generated.h"

UENUM()
enum class EObstacleType : uint8
{
	NONE = 0,
	Fence,
	Tire,
	FinishLine,
	MAX
};
