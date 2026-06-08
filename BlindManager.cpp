#include "BlindManager.h"
#include <iostream>

BlindManager::BlindManager() {
    buildBlindsForAnte();
}

void BlindManager::buildBlindsForAnte() {
    blinds.clear();
    blinds.push_back(std::make_shared<Blind>("Small Blind", BlindType::Small));
    blinds.push_back(std::make_shared<Blind>("Big Blind",   BlindType::Big));
    blinds.push_back(std::make_shared<Blind>("Boss Blind",  BlindType::Boss));
}

void BlindManager::onRunStart(RunSessionState& state) {
    state.currentBlindIndex = 0;
    syncBlindState(state);
    executor.executeCommandsForTiming(state, RewardTiming::Start);
}

void BlindManager::playCurrentBlind(RunSessionState& state) {
    int idx = state.currentBlindIndex;
    if (idx >= (int)blinds.size()) return;

    auto& blind = blinds[idx];

    int score = scoringRule.scoreHand();
    bool win  = blind->checkScore(score);
    int money = rewardRule.earnMoney(win, score);

    state.persistent.money += money;
    std::cout << "[Play] " << blind->getName()
              << " | Score: " << score
              << " | Win: " << (win ? "YES" : "NO")
              << " | +Money: " << money
              << " | Total: " << state.persistent.money << "\n";

    if (win) {
        state.currentBlind.isDefeated = true;
        moveToNextBlind(state);
    }
}

void BlindManager::skipCurrentBlind(RunSessionState& state) {
    int idx = state.currentBlindIndex;
    if (idx >= (int)blinds.size()) return;

    auto& blind = blinds[idx];
    std::cout << "[Skip] " << blind->getName() << " di-skip.\n";

    auto reward = blind->createSkipReward();
    if (reward) {
        std::cout << "[Skip] Reward: " << reward->getDescription() << "\n";
        state.persistent.pendingCommands.push_back(reward);
    }

    state.currentBlind.isSkipped = true;
    moveToNextBlind(state);
}

void BlindManager::moveToNextBlind(RunSessionState& state) {
    state.currentBlindIndex++;

    if (state.currentBlindIndex >= (int)blinds.size()) {
        state.persistent.ante++;
        state.currentBlindIndex = 0;
        buildBlindsForAnte();
        std::cout << "[Ante] Naik ke Ante " << state.persistent.ante << "\n";
        executor.executeCommandsForTiming(state, RewardTiming::NextAnte);
    } else {
        executor.executeCommandsForTiming(state, RewardTiming::NextBlind);
    }

    syncBlindState(state);
}

void BlindManager::syncBlindState(RunSessionState& state) {
    int idx = state.currentBlindIndex;
    if (idx < (int)blinds.size()) {
        state.currentBlind.name       = blinds[idx]->getName();
        state.currentBlind.isSkipped  = false;
        state.currentBlind.isDefeated = false;
    }
}