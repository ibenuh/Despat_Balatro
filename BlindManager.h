#pragma once
#include "Blind.h"
#include "RunSessionState.h"
#include "RewardCommandExecutor.h"
#include "ScoringRule.h"
#include "RewardRule.h"
#include <vector>
#include <memory>

class BlindManager {
private:
    std::vector<std::shared_ptr<Blind>> blinds;
    RewardCommandExecutor executor;
    ScoringRule scoringRule;
    RewardRule rewardRule;

    void buildBlindsForAnte();
    void moveToNextBlind(RunSessionState& state);
    void syncBlindState(RunSessionState& state);

public:
    BlindManager();
    void onRunStart(RunSessionState& state);
    void playCurrentBlind(RunSessionState& state);
    void skipCurrentBlind(RunSessionState& state);
};