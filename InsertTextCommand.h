#ifndef INSERT_TEXT_COMMAND_H
#define INSERT_TEXT_COMMAND_H

#include "Command.h"
#include <string>

class InsertTextCommand : public Command {
public:
    InsertTextCommand(std::string text, size_t position);
    void execute(Document& doc) override;
    void undo(Document& doc) override;

private:
    std::string text_;
    size_t position_;
};

#endif