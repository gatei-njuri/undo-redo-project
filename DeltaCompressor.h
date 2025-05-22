#ifndef DELTA_COMPRESSOR_H
#define DELTA_COMPRESSOR_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>

// Forward declaration to avoid circular dependencies
class DocumentState;

class DeltaCompressor {
public:
    // Compress the document state into a delta (difference)
    static std::string compress(const DocumentState& original, const DocumentState& modified) {
        // Simple implementation: compare two document states and return only the delta
        std::string originalContent = original.getContent();
        std::string modifiedContent = modified.getContent();

        // Calculate the difference between original and modified content
        size_t minLength = std::min(originalContent.length(), modifiedContent.length());
        size_t i = 0;

        // Find the first difference
        while (i < minLength && originalContent[i] == modifiedContent[i]) {
            ++i;
        }

        // Return the remaining portion of the modified content as the delta
        return modifiedContent.substr(i);
    }

    // Apply a delta to a document state to produce the modified state
    static std::unique_ptr<DocumentState> applyDelta(const DocumentState& original, const std::string& delta) {
        std::string originalContent = original.getContent();
        std::string modifiedContent = originalContent + delta;  // Append the delta to the original content

        // Return a new DocumentState with the modified content
        return std::make_unique<DocumentState>(modifiedContent);
    }
};

#endif 
