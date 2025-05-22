#ifndef DELETE_TEXT_COMMAND_H
#define DELETE_TEXT_COMMAND_H

#include "Command.h"
#include <string>

class DeleteTextCommand : public Command {
public:
    DeleteTextCommand(size_t position, size_t length);
    void execute(Document& doc) override;
    void undo(Document& doc) override;

private:
    size_t position_;
    size_t length_;
    std::string deletedText_;
};

#endif // DELETE_TEXT_COMMAND_H