#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include "Command.h"
#include "HistoryTree.h"
#include <stack>
#include <memory>

class Document;

class CommandManager {
public:
    CommandManager(HistoryTree& historyTree);// Passes history tree into a manager
    void executeCommand(std::unique_ptr<Command> cmd, Document& doc);
    void undo(Document& doc);
    void redo(Document& doc);
    bool canUndo() const;
    bool canRedo() const;
    

private:
    std::stack<std::unique_ptr<Command>> undoStack_;
    std::stack<std::unique_ptr<Command>> redoStack_;
    HistoryTree& historyTree_; //References the shared history tree

};

#endif