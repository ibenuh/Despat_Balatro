#pragma once
#include <vector>
#include <string>
#include <memory>

// Forward declaration
class RewardCommand;

struct PersistentState {
    int ante = 1;
    int money = 4;
    int remainingHands = 4;
    int remainingDiscards = 3;
    std::vector<std::string> deck;
    std::vector<std::string> pendingDeckReward;
    std::vector<std::shared_ptr<RewardCommand>> pendingCommands;
};

struct BlindState {
    std::string name;
    bool isSkipped = false;
    bool isDefeated = false;
};

struct RunSessionState {
    PersistentState persistent;
    BlindState currentBlind;
    bool isRunActive = true;
    int currentBlindIndex = 0; // 0=Small, 1=Big, 2=Boss
};