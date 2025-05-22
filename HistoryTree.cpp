/*#include "HistoryTree.h"
#include <iostream>
#include <string>

HistoryTree::HistoryTree()
    : rootNode_(nullptr), currentNode_(nullptr) {
}

HistoryTree::~HistoryTree() {
    // Memory management is handled by unique_ptr and HistoryNode destructor
}

void HistoryTree::addState(std::unique_ptr<DocumentState> state, const std::string& operation) {
    if (currentNode_) {
        // Create a new branch from the current node
        auto newNode = std::make_unique<HistoryNode>(std::move(state), operation);
        currentNode_->addBranch(std::move(newNode));
        currentNode_ = currentNode_->getBranches().back().get(); // Move to the new node (branch)
    }
    else {
        // If no history exists, create the root node
        rootNode_ = std::make_unique<HistoryNode>(std::move(state), operation);
        currentNode_ = rootNode_.get();
    }

    // Clear redo stack as we're creating a new branch
    clearRedoHistory();
}

void HistoryTree::undo() {
    if (canUndo()) {
        undoStack_.push(currentNode_);
        currentNode_ = undoStack_.top()->getBranches().back().get();  // Undo to the last branch
        undoStack_.pop();
    }
}

void HistoryTree::redo() {
    if (canRedo()) {
        redoStack_.push(currentNode_);
        currentNode_ = redoStack_.top();  // Redo to the last state
        redoStack_.pop();
    }
}

void HistoryTree::printHistoryBranch() const {
    // Start from the root node and print the tree
    printNodeBranch(rootNode_.get(), "");
}

void HistoryTree::printNodeBranch(const HistoryNode* node, const std::string& indent) const {
    if (node == nullptr) return;

    // Print the current node's operation/label
    std::cout << indent << node->getOperation() << std::endl;

    // Recursively print all branches (children) of the current node
    for (const auto& child : node->getBranches()) {
        printNodeBranch(child.get(), indent + "  ");  // Indentation for child branches
    }
}

bool HistoryTree::canUndo() const {
    return !undoStack_.empty();
}

bool HistoryTree::canRedo() const {
    return !redoStack_.empty();
}

const DocumentState& HistoryTree::getCurrentState() const {
    return currentNode_->getState();
}

void HistoryTree::clearRedoHistory() {
    while (!redoStack_.empty()) {
        redoStack_.pop();
    }
}
*/

#include "HistoryTree.h"
#include <iostream>
#include <string>

HistoryTree::HistoryTree()
    : rootNode_(nullptr), currentNode_(nullptr) {
}

HistoryTree::~HistoryTree() {
    // Memory management is handled by unique_ptr and HistoryNode destructor
}

void HistoryTree::addState(std::unique_ptr<DocumentState> state, const std::string& operation) {
    if (currentNode_) {
        // Create a new branch from the current node
        auto newNode = std::make_unique<HistoryNode>(std::move(state), operation);
        currentNode_->addBranch(std::move(newNode));
        currentNode_ = currentNode_->getBranches().back().get(); // Move to the new node (branch)
    }
    else {
        // If no history exists, create the root node
        rootNode_ = std::make_unique<HistoryNode>(std::move(state), operation);
        currentNode_ = rootNode_.get();
    }

    // Clear redo stack as we're creating a new branch
    clearRedoHistory();
}

void HistoryTree::undo() {
    if (canUndo()) {
        undoStack_.push(currentNode_);
        currentNode_ = undoStack_.top()->getBranches().back().get();  // Undo to the last branch
        undoStack_.pop();
    }
}

void HistoryTree::redo() {
    if (canRedo()) {
        redoStack_.push(currentNode_);
        currentNode_ = redoStack_.top();  // Redo to the last state
        redoStack_.pop();
    }
}

void HistoryTree::printHistoryBranch() const {
    std::cout << "\n--- Document History Tree ---\n";
    if (!rootNode_) {
        std::cout << "No history available.\n";
        return;
    }
    printNodeBranch(rootNode_.get(), "");
}

void HistoryTree::printNodeBranch(const HistoryNode* node, const std::string& indent) const {
    if (node == nullptr) return;

    // Print the current node's operation/label
    std::cout << indent << "- " << node->getOperation() << std::endl;

    // Recursively print all branches (children) of the current node
    for (const auto& child : node->getBranches()) {
        printNodeBranch(child.get(), indent + "  ");  // Indentation for child branches
    }
}

bool HistoryTree::canUndo() const {
    return !undoStack_.empty();
}

bool HistoryTree::canRedo() const {
    return !redoStack_.empty();
}

const DocumentState& HistoryTree::getCurrentState() const {
    return currentNode_->getState();
}

void HistoryTree::clearRedoHistory() {
    while (!redoStack_.empty()) {
        redoStack_.pop();
    }
}

