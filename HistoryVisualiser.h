#ifndef HISTORY_VISUALISER_H
#define HISTORY_VISUALISER_H

#include <string>
#include <vector>
#include "HistoryTree.h"

class HistoryVisualiser {
public:
    explicit HistoryVisualiser(HistoryTree& historyTree);

    // Visualize the history as a tree structure
    void visualizeHistory() const;

    // Visualize the current state in the history tree
    void visualizeCurrentState() const;

    // Optionally, visualize the history in a textual format
    void visualizeHistoryTextually() const;

private:
    HistoryTree& historyTree_;  // Reference to the HistoryTree object
    void visualizeNode(const HistoryNode* node, int depth) const;  // Recursive function to visualize nodes
    void printIndentation(int depth) const;  // Helper function to manage indentation
};

#endif // HISTORY_VISUALISER_H
