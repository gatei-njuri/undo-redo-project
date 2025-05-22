#include <iostream>
#include <memory>
#include <string>
#include <limits>

#include "InsertTextCommand.h"
#include "DeleteTextCommand.h"
#include "CommandManager.h"
#include "Document.h"
#include "HistoryTree.h"
#include "DocumentState.h"

void printMenu() {
    std::cout << "\n--- Document Editor ---\n";
    std::cout << "1. Insert Text\n";
    std::cout << "2. Delete Text\n";
    std::cout << "3. Undo\n";
    std::cout << "4. Redo\n";
    std::cout << "5. Show Document\n";
    std::cout << "6. View Branch History\n";  // fixed typo
    std::cout << "7. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Document doc;

    
    HistoryTree history;
    CommandManager manager(history);

    int choice;
    while (true) {
        printMenu();
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline

        switch (choice) {
        case 1: {
            std::string text;
            size_t pos = doc.getContent().size();
            std::cin.ignore();
            std::cout << "Enter text: ";
            std::getline(std::cin, text);

            auto cmd = std::make_unique<InsertTextCommand>(text, pos);
            manager.executeCommand(std::move(cmd), doc);
            break;
        }
        case 2: {
            size_t pos, len;
            std::cout << "Enter position to delete from: ";
            std::cin >> pos;
            std::cout << "Enter length to delete: ";
            std::cin >> len;
            std::cin.ignore();

            auto cmd = std::make_unique<DeleteTextCommand>(pos, len);
            manager.executeCommand(std::move(cmd), doc);
            break;
        }
        case 3:
            manager.undo(doc);
            break;
        case 4:
            manager.redo(doc);
            break;
        case 5:
            std::cout << "\nCurrent Document:\n" << doc.getContent() << "\n";
            break;
        case 6:
            history.printHistoryBranch();  
            break;
        case 7:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid option.\n";
        }
    }
}

