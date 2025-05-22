#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <string>
#include <fstream>
#include <sstream>
#include <memory>

class DocumentState;

class Serializer {
public:
    // Save the current document state to a file
    static bool save(const std::string& filename, const DocumentState& state) {
        std::ofstream outFile(filename);
        if (!outFile.is_open()) {
            return false;  // Error opening file
        }

        // Write the document content to the file
        outFile << state.getContent();

        return true;
    }

    // Load a document state from a file
    static std::unique_ptr<DocumentState> load(const std::string& filename) {
        std::ifstream inFile(filename);
        if (!inFile.is_open()) {
            return nullptr;  // Error opening file or file doesn't exist
        }

        // Read the entire content from the file
        std::ostringstream contentStream;
        contentStream << inFile.rdbuf();
        std::string content = contentStream.str();

        // Return a new DocumentState with the content loaded
        return std::make_unique<DocumentState>(content);
    }
};

#endif 
