#include "Blind.h"
 
std::string Blind::getName() const { return name; }
BlindType Blind::getType() const { return type; }
 
bool Blind::checkScore(int score) {
    return rule.checkBlind(score);
}
 
std::shared_ptr<RewardCommand> Blind::createSkipReward() const {
    switch (type) {
        case BlindType::Small:
            return std::make_shared<BonusHandCommand>(RewardTiming::NextBlind);
 
        case BlindType::Big:
            return std::make_shared<FreePlayingCardCommand>(
                RewardTiming::NextBlind, "Ace of Spades"
            );
 
        case BlindType::Boss:
            return std::make_shared<BonusHandCommand>(RewardTiming::NextAnte);
 
        default:
            return nullptr;
    }
}
 