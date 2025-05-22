#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "DocumentState.h"
#include <stack>
#include <memory>

class StateManager {
public:
    StateManager() = default;

    // Save the current state of the document
    void saveState(const std::string& content) {
        undoStack_.push(std::make_unique<DocumentState>(content));
        // Clear the redo stack when a new state is saved
        while (!redoStack_.empty()) {
            redoStack_.pop();
        }
    }

    // Undo the last operation
    bool undo(std::string& content) {
        if (undoStack_.empty()) {
            return false;  // No more states to undo
        }
        // Move the current state to the redo stack
        redoStack_.push(std::move(undoStack_.top()));
        undoStack_.pop();
        // Restore the previous state
        content = undoStack_.empty() ? "" : undoStack_.top()->getContent();
        return true;
    }

    // Redo the last undone operation
    bool redo(std::string& content) {
        if (redoStack_.empty()) {
            return false;  // No more states to redo
        }
        // Move the current state to the undo stack
        undoStack_.push(std::move(redoStack_.top()));
        redoStack_.pop();
        // Restore the redone state
        content = undoStack_.top()->getContent();
        return true;
    }

    // Check if there are undoable states
    bool canUndo() const {
        return !undoStack_.empty();
    }

    // Check if there are redoable states
    bool canRedo() const {
        return !redoStack_.empty();
    }

private:
    std::stack<std::unique_ptr<DocumentState>> undoStack_;
    std::stack<std::unique_ptr<DocumentState>> redoStack_;
};

#endif 
