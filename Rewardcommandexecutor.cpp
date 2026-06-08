#include "RewardCommandExecutor.h"
#include "RunSessionState.h"
#include <vector>
#include <memory>
#include <iostream>

void RewardCommandExecutor::executeCommandsForTiming(RunSessionState& state, RewardTiming timing) {
    auto& commands = state.persistent.pendingCommands;
    if (commands.empty()) return;

    std::vector<std::shared_ptr<RewardCommand>> remaining;

    for (const auto& cmd : commands) {
        if (cmd->getTiming() == timing) {
            std::cout << "[Executor] Menjalankan: " << cmd->getDescription() << "\n";
            cmd->execute(state);
        } else {
            remaining.emplace_back(cmd);
        }
    }

    commands = std::move(remaining);
}