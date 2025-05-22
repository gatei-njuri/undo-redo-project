#ifndef COMMAND_H
#define COMMAND_H

class Document;

// Base Command interface using modern C++ best practices
class Command {
public:
    virtual void execute(Document& doc) = 0;
    virtual void undo(Document& doc) = 0;
    virtual ~Command() = default;
};

#endif