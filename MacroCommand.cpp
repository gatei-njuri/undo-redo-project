#include "MacroCommand.h"

void MacroCommand::addCommand(std::unique_ptr<Command> command) {
    commands_.emplace_back(std::move(command));
}

void MacroCommand::execute(Document& doc) {
    for (auto& cmd : commands_) {
        cmd->execute(doc);
    }
}

void MacroCommand::undo(Document& doc) {
    for (auto it = commands_.rbegin(); it != commands_.rend(); ++it) {
        (*it)->undo(doc);
    }
}
