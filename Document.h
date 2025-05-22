#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <fstream>

class Document {
public:
    Document() = default;

    void insert(size_t position, const std::string& text) {
        if (position > content_.size()) position = content_.size();
        content_.insert(position, text);
    }

    void remove(size_t position, size_t length) {
        if (position >= content_.size()) return;
        content_.erase(position, length);
    }

    std::string getText(size_t position, size_t length) const {
        if (position >= content_.size()) return "";
        return content_.substr(position, length);
    }

    const std::string& getContent() const {
        return content_;
    }

    void setContent(const std::string& content) {
        content_ = content;
    }

    // Simple persistence methods
    bool saveToFile(const std::string& filename) const {
        std::ofstream out(filename);
        if (!out) return false;
        out << content_;
        return true;
    }

    bool loadFromFile(const std::string& filename) {
        std::ifstream in(filename);
        if (!in) return false;
        std::string line, loadedContent;
        while (std::getline(in, line)) {
            loadedContent += line + '\n';
        }
        if (!loadedContent.empty() && loadedContent.back() == '\n')
            loadedContent.pop_back(); // remove trailing newline
        content_ = std::move(loadedContent);
        return true;
    }

private:
    std::string content_;
};

#endif