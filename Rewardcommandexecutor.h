#pragma once
#include "RewardCommand.h"

struct RunSessionState;

class RewardCommandExecutor {
public:
    void executeCommandsForTiming(RunSessionState& state, RewardTiming timing);
};