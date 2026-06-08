#pragma once
#include "RewardCommand.h"
#include <string>

class FreePlayingCardCommand : public RewardCommand {
private:
    RewardTiming timing;
    std::string cardName;

public:
    FreePlayingCardCommand(RewardTiming t, std::string card);
    RewardTiming getTiming() const override;
    void execute(RunSessionState& state) override;
    std::string getDescription() const override;
};