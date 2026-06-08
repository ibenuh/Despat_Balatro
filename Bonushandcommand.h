#pragma once
#include "RewardCommand.h"

class BonusHandCommand : public RewardCommand {
private:
    RewardTiming timing;

public:
    explicit BonusHandCommand(RewardTiming t);
    RewardTiming getTiming() const override;
    void execute(RunSessionState& state) override;
    std::string getDescription() const override;
};