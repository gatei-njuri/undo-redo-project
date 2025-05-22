#include "InsertTextCommand.h"
#include "Document.h"

InsertTextCommand::InsertTextCommand(std::string text, size_t position)
    : text_(std::move(text)), position_(position) {
}

void InsertTextCommand::execute(Document& doc) {
    doc.insert(position_, text_);
}

void InsertTextCommand::undo(Document& doc) {
    doc.remove(position_, text_.length());
}