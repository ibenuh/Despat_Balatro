#include "BonusHandCommand.h"
#include "RunSessionState.h"
#include <iostream>

BonusHandCommand::BonusHandCommand(RewardTiming t) : timing(t) {}

RewardTiming BonusHandCommand::getTiming() const {
    return timing;
}

void BonusHandCommand::execute(RunSessionState& state) {
    state.persistent.remainingHands += 1;
    std::cout << "[BonusHandCommand] +1 hand. Total hands: "
              << state.persistent.remainingHands << "\n";
}

std::string BonusHandCommand::getDescription() const {
    return "+1 Remaining Hand";
}