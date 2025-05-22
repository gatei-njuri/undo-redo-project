#ifndef DOCUMENT_STATE_H
#define DOCUMENT_STATE_H

#include <string>

class DocumentState {
public:
    explicit DocumentState(std::string content)
        : content_(std::move(content)) {
    }

    const std::string& getContent() const {
        return content_;
    }

private:
    std::string content_;
};

#endif 
