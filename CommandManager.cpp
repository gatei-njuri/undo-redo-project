#include "CommandManager.h"
#include "Document.h"

CommandManager::CommandManager(HistoryTree& historyTree)
    : historyTree_(historyTree) {

}
void CommandManager::executeCommand(std::unique_ptr<Command> cmd, Document& doc) {
    cmd->execute(doc);
    std::string content = doc.getContent();
    std::unique_ptr<DocumentState> state = std::make_unique<DocumentState>(content);
    
    //Get operation name
    std::string operation = typeid(*cmd).name();

    historyTree_.addState(std::move(state), operation);

    undoStack_.push(std::move(cmd));
    while (!redoStack_.empty()) redoStack_.pop();
}

void CommandManager::undo(Document& doc) {
    if (undoStack_.empty()) return;

    auto cmd = std::move(undoStack_.top());
    undoStack_.pop();
    cmd->undo(doc);
    redoStack_.push(std::move(cmd));
}

void CommandManager::redo(Document& doc) {
    if (redoStack_.empty()) return;

    auto cmd = std::move(redoStack_.top());
    redoStack_.pop();
    cmd->execute(doc);
    undoStack_.push(std::move(cmd));
}

bool CommandManager::canUndo() const {
    return !undoStack_.empty();
}

bool CommandManager::canRedo() const {
    return !redoStack_.empty();
}
