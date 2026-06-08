#pragma once
#include <string>
#include <memory>
#include "RewardCommand.h"
#include "BonusHandCommand.h"
#include "FreePlayingCardCommand.h"
#include "BlindRule.h"
 
enum class BlindType {
    Small,
    Big,
    Boss
};
 
class Blind {
private:
    std::string name;
    BlindType type;
    BlindRule rule;
 
public:
    Blind(std::string n, BlindType t) : name(std::move(n)), type(t) {}
 
    std::string getName() const;
    BlindType getType() const;
    bool checkScore(int score);
    std::shared_ptr<RewardCommand> createSkipReward() const;
};
 