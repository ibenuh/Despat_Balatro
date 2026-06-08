#pragma once
#include <string>

struct RunSessionState;

enum class RewardTiming {
    Start,
    NextBlind,
    NextAnte
};

class RewardCommand {
public:
    virtual ~RewardCommand() = default;
    virtual RewardTiming getTiming() const = 0;
    virtual void execute(RunSessionState& state) = 0;
    virtual std::string getDescription() const = 0;
};