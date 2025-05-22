#ifndef HISTORY_NODE_H
#define HISTORY_NODE_H

#include <memory>
#include <vector>
#include <string>
#include "DocumentState.h"  // Assuming DocumentState stores the state of the document

class HistoryNode {
public:
    HistoryNode(std::unique_ptr<DocumentState> state, std::string operation);

    void addBranch(std::unique_ptr<HistoryNode> branch);
    
    // Getters
    const DocumentState& getState() const;
    const std::string& getOperation() const;
    const std::vector<std::unique_ptr<HistoryNode>>& getBranches() const;

private:
    std::unique_ptr<DocumentState> state_;
    std::string operation_;  // The operation that created this state (e.g., "insert text", "delete text")
    std::vector<std::unique_ptr<HistoryNode>> branches_;  // Alternative paths from this node
};


#endif 
