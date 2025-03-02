//CREATE A C++ APPLICATION TO READ,
 //WRITE, AND APPEND DATA TO TEXT
 //FILES..
#include <iostream>
#include <fstream>
#include <string>

class FileManager {
private:
    std::string filename;

public:
    FileManager(const std::string& fname) : filename(fname) {}

    bool writeToFile(const std::string& content) {
        std::ofstream outFile(filename);
        
        if (!outFile) {
            std::cerr << "Error: Unable to open file for writing: " << filename << std::endl;
            return false;
        }
        
        outFile << content;
        outFile.close();
        
        std::cout << "Content successfully written to " << filename << std::endl;
        return true;
    }

    bool appendToFile(const std::string& content) {
        std::ofstream outFile(filename, std::ios::app);
        
        if (!outFile) {
            std::cerr << "Error: Unable to open file for appending: " << filename << std::endl;
            return false;
        }
        
        outFile << content;
        outFile.close();
        
        std::cout << "Content successfully appended to " << filename << std::endl;
        return true;
    }

    bool readFromFile(std::string& content) {
        std::ifstream inFile(filename);
        
        if (!inFile) {
            std::cerr << "Error: Unable to open file for reading: " << filename << std::endl;
            return false;
        }
        
        std::string line;
        content.clear();
        
        while (std::getline(inFile, line)) {
            content += line + "\n";
        }
        
        inFile.close();
        return true;
    }
};

int main() {
    std::string filename;
    int choice;
    std::string content;
    
    std::cout << "=== File Operations Application ===" << std::endl;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    
    // Create FileManager instance
    FileManager fileManager(filename);
    
    do {
        // Display menu
        std::cout << "\nChoose an operation:" << std::endl;
        std::cout << "1. Write to file (overwrite existing content)" << std::endl;
        std::cout << "2. Append to file" << std::endl;
        std::cout << "3. Read from file" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter choice (1-4): ";
        std::cin >> choice;
        
        // Clear the input buffer
        std::cin.ignore();
        
        switch (choice) {
            case 1: // Write
                std::cout << "Enter content to write (end with a line containing only 'END'):" << std::endl;
                content.clear();
                while (true) {
                    std::string line;
                    std::getline(std::cin, line);
                    if (line == "END") break;
                    content += line + "\n";
                }
                fileManager.writeToFile(content);
                break;
                
            case 2: // Append
                std::cout << "Enter content to append (end with a line containing only 'END'):" << std::endl;
                content.clear();
                while (true) {
                    std::string line;
                    std::getline(std::cin, line);
                    if (line == "END") break;
                    content += line + "\n";
                }
                fileManager.appendToFile(content);
                break;
                
            case 3: // Read
                if (fileManager.readFromFile(content)) {
                    std::cout << "\n=== File Content ===\n" << content << "=== End of File ===\n";
                }
                break;
                
            case 4: // Exit
                std::cout << "Exiting application. Goodbye!" << std::endl;
                break;
                
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
        
    } while (choice != 4);
    
    return 0;
}
