#include "FreePlayingCardCommand.h"
#include "RunSessionState.h"
#include <iostream>

FreePlayingCardCommand::FreePlayingCardCommand(RewardTiming t, std::string card)
    : timing(t), cardName(std::move(card)) {}

RewardTiming FreePlayingCardCommand::getTiming() const {
    return timing;
}

void FreePlayingCardCommand::execute(RunSessionState& state) {
    if (timing == RewardTiming::Start) {
        state.persistent.deck.push_back(cardName);
        std::cout << "[FreePlayingCardCommand] Kartu " << cardName
                  << " ditambahkan ke deck.\n";
    } else {
        state.persistent.pendingDeckReward.push_back(cardName);
        std::cout << "[FreePlayingCardCommand] Kartu " << cardName
                  << " masuk pending deck reward.\n";
    }
}

std::string FreePlayingCardCommand::getDescription() const {
    return "Free Playing Card: " + cardName;
}