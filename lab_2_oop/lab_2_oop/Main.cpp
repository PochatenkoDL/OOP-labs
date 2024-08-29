#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>

// ������� ���� ��� ������ � ������������� ��������
class AssociativeArray {
protected:
    std::map<std::string, int> data;  // ������������ std::map ��� ������������� ������

public:
    // ����������� �� �������������
    AssociativeArray() {}

    // ����������
    virtual ~AssociativeArray() {}

    // ����� ��������� ��������
    void addElement(const std::string& key, int value) {
        data[key] = value;
    }

    // ����� ��������� ��������
    void removeElement(const std::string& key) {
        data.erase(key);
    }

    // ³��������� ����� ��� ����������
    virtual void sortElements() = 0;

    // ����� ��� ��������� ��� ��������
    void displayElements() const {
        for (const auto& element : data) {
            std::cout << element.first << ": " << element.second << std::endl;
        }
    }

    // ����� ��� ���������� �������� � ����
    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& element : data) {
                file << element.first << ": " << element.second << std::endl;
            }
            file.close();
        }
        else {
            std::cout << "Unable to open file" << std::endl;
        }
    }

    // ����� ��� ��������� �������� �� ������
    int getElement(const std::string& key) const {
        auto it = data.find(key);
        if (it != data.end()) {
            return it->second;
        }
        else {
            std::cerr << "Key not found!" << std::endl;
            return -1; // ��������� -1, ���� ���� �� ��������
        }
    }
};

// �������� ����, �� ������ ���������� �������� �� ����������
class SortedAssociativeArray : public AssociativeArray {
public:
    // ��������� ���������� �� ����������
    void sortElements() override {
        // ������� ��� � ������ ��� ����������
        std::vector<std::pair<std::string, int>> elements(data.begin(), data.end());

        // ���������� ������� �� ����������
        std::sort(elements.begin(), elements.end(), [](const auto& a, const auto& b) {
            return a.second < b.second; // ���������� �� ���������
            });

        // ��������� ������������ ��������
        std::cout << "Elements sorted by value:\n";
        for (const auto& element : elements) {
            std::cout << element.first << ": " << element.second << std::endl;
        }
    }
};

int main() {
    SortedAssociativeArray arr; // ��������� ��'���� ��������� �����
    int choice;
    std::string key;
    int value;

    do {
        // ��������� ���� ��� �����������
        std::cout << "\nMenu:\n";
        std::cout << "1. Add an element\n";
        std::cout << "2. Remove an element\n";
        std::cout << "3. Display all elements\n";
        std::cout << "4. Save elements to file\n";
        std::cout << "5. Sort elements by value\n";
        std::cout << "6. Get element by key\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter key (string): ";
            std::cin >> key;
            std::cout << "Enter value (integer): ";
            std::cin >> value;
            arr.addElement(key, value);
            break;

        case 2:
            std::cout << "Enter key to remove: ";
            std::cin >> key;
            arr.removeElement(key);
            break;

        case 3:
            std::cout << "Elements in the array:\n";
            arr.displayElements();
            break;

        case 4:
            arr.saveToFile("output.txt");
            std::cout << "Elements saved to output.txt\n";
            break;

        case 5:
            arr.sortElements();
            break;

        case 6:
            std::cout << "Enter key to get the value: ";
            std::cin >> key;
            value = arr.getElement(key);
            if (value != -1) {
                std::cout << "The value for key '" << key << "' is: " << value << std::endl;
            }
            break;

        case 7:
            std::cout << "Exiting program...\n";
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
