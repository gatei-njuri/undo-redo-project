#include "DeleteTextCommand.h"
#include "Document.h"

DeleteTextCommand::DeleteTextCommand(size_t position, size_t length)
    : position_(position), length_(length) {
}

void DeleteTextCommand::execute(Document& doc) {
    deletedText_ = doc.getText(position_, length_);
    doc.remove(position_, length_);
}

void DeleteTextCommand::undo(Document& doc) {
    doc.insert(position_, deletedText_);
}