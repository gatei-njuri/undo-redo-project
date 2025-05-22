#ifndef MACRO_COMMAND_H
#define MACRO_COMMAND_H

#include "Command.h"
#include <vector>
#include <memory>

class MacroCommand : public Command {
public:
    void addCommand(std::unique_ptr<Command> command);
    void execute(Document& doc) override;
    void undo(Document& doc) override;

private:
    std::vector<std::unique_ptr<Command>> commands_;
};

#endif 