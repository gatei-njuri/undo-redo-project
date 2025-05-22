#include "HistoryNode.h"

HistoryNode::HistoryNode(std::unique_ptr<DocumentState> state, std::string operation)
    : state_(std::move(state)), operation_(std::move(operation)) {
}

void HistoryNode::addBranch(std::unique_ptr<HistoryNode> branch) {
    branches_.push_back(std::move(branch));
}

const DocumentState& HistoryNode::getState() const {
    return *state_;
}

const std::string& HistoryNode::getOperation() const {
    return operation_;
}

const std::vector<std::unique_ptr<HistoryNode>>& HistoryNode::getBranches() const {
    return branches_;
}
