#ifndef HISTORY_TREE_H
#define HISTORY_TREE_H

#include "HistoryNode.h"
#include <memory>
#include <stack>

class HistoryTree {
public:
    HistoryTree();
    ~HistoryTree();

    const HistoryNode* getRoot() const {
        return rootNode_.get();
    }

    void addState(std::unique_ptr<DocumentState> state, const std::string& operation);
    void undo();
    void redo();

    bool canUndo() const;
    bool canRedo() const;
    void printHistoryBranch() const;

    const DocumentState& getCurrentState() const;
    const HistoryNode* getCurrentNode() const {
        return currentNode_;
    }

private:
    void clearRedoHistory();

    void printNodeBranch(const HistoryNode* node, const std::string& indent) const;

    std::unique_ptr<HistoryNode> rootNode_; // Root node of the history tree
    HistoryNode* currentNode_;              // Current node representing the current document state
    std::stack<HistoryNode*> undoStack_;     // Stack to track undo history
    std::stack<HistoryNode*> redoStack_;     // Stack to track redo history


};

#endif 
