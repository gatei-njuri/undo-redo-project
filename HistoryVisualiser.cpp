#include "HistoryVisualiser.h"
#include <iostream>

HistoryVisualiser::HistoryVisualiser(HistoryTree& historyTree)
    : historyTree_(historyTree) {
}

void HistoryVisualiser::visualizeHistory() const {
    // Visualize the entire history starting from the root node
    std::cout << "History Tree:" << std::endl;

    const HistoryNode* root = historyTree_.getRoot();
    if (root != nullptr) {
        visualizeNode(root, 0);
    }
}


void HistoryVisualiser::visualizeCurrentState() const {
    // Visualize the current state of the document
    std::cout << "\nCurrent Document State:" << std::endl;
    const DocumentState& currentState = historyTree_.getCurrentState();
    std::cout << "State: " << currentState.getContent() << std::endl;
    const HistoryNode* currentNode = historyTree_.getCurrentNode();
    if (currentNode) {
        std::cout << "Operation:" << currentNode->getOperation() << std::endl;
    }
}

void HistoryVisualiser::visualizeHistoryTextually() const {
    // Textual representation of the history
    std::cout << "\nTextual History Representation:" << std::endl;
    const HistoryNode* rootNode = historyTree_.getCurrentNode();
    if (rootNode) {
        visualizeNode(rootNode, 0);
    }
}

void HistoryVisualiser::visualizeNode(const HistoryNode* node, int depth) const {
    // Visualize the current node with indentation based on depth
    printIndentation(depth);
    std::cout << "Operation: " << node->getOperation() << std::endl;
    printIndentation(depth);
    std::cout << "State: " << node->getState().getContent() << std::endl;

    // Recursively visualize branches of this node
    for (const auto& branch : node->getBranches()) {
        visualizeNode(branch.get(), depth + 1);
    }
}

void HistoryVisualiser::printIndentation(int depth) const {
    // Print spaces to create tree structure indentation
    for (int i = 0; i < depth; ++i) {
        std::cout << "  ";
    }
}
