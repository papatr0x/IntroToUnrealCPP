#include <iostream>
#include <map>
#include <string>

class PhoneDirectory {
private:
    std::map<std::string, std::string> contacts;

public:
    // Add a new contact or update existing contact
    void addContact(const std::string& name, const std::string& phoneNumber) {
        contacts[name] = phoneNumber;
        std::cout << "Contact added successfully!\n";
    }

    // Find a contact by name
    bool findContact(const std::string& name) const {
        auto it = contacts.find(name);
        if (it != contacts.end()) {
            std::cout << "Name: " << it->first << "\nPhone: " << it->second << "\n";
            return true;
        }
        std::cout << "Contact not found!\n";
        return false;
    }

    // Delete a contact by name
    bool deleteContact(const std::string& name) {
        auto it = contacts.find(name);
        if (it != contacts.end()) {
            contacts.erase(it);
            std::cout << "Contact deleted successfully!\n";
            return true;
        }
        std::cout << "Contact not found!\n";
        return false;
    }

    // List all contacts
    void listAllContacts() const {
        if (contacts.empty()) {
            std::cout << "Phone directory is empty!\n";
            return;
        }

        std::cout << "\n===== CONTACTS =====\n";
        for (const auto& [name, phone] : contacts) {
            std::cout << "Name: " << name << "\nPhone: " << phone << "\n-----------------\n";
        }
    }

    // Get the number of contacts
    size_t size() const {
        return contacts.size();
    }
};

// Clear input buffer
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Get user input with validation
std::string getInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

int main() {
    PhoneDirectory directory;
    int choice = 0;
    std::string name, phoneNumber;

    std::cout << "===== PHONE DIRECTORY PROGRAM =====\n";

    while (true) {
        std::cout << "\nPhone Directory Menu:\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Find Contact\n";
        std::cout << "3. Delete Contact\n";
        std::cout << "4. List All Contacts\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice (1-5): ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();  // Clear input buffer after reading choice

        switch (choice) {
            case 1:  // Add Contact
                name = getInput("Enter name: ");
                phoneNumber = getInput("Enter phone number: ");
                directory.addContact(name, phoneNumber);
                break;

            case 2:  // Find Contact
                name = getInput("Enter name to search: ");
                directory.findContact(name);
                break;

            case 3:  // Delete Contact
                name = getInput("Enter name to delete: ");
                directory.deleteContact(name);
                break;

            case 4:  // List All Contacts
                directory.listAllContacts();
                break;

            case 5:  // Exit
                std::cout << "Thank you for using the Phone Directory. Goodbye!\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
                break;
        }
    }

    return 0;
}