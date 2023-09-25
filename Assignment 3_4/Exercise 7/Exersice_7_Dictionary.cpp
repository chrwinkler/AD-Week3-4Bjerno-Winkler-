#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;  // Use the std namespace for using standard lib

// Define a dictionary entry as a Pair of (key(word), value(meaning))
typedef pair<string, string> DictionaryEntry;

class Dictionary {
private:
    vector<DictionaryEntry> entries;

public:
    // Add a new entry to the dictionary
    void AddMeaning(const string& key, const string& value) {
        entries.push_back(make_pair(key, value));
    }

    // Lookup a word and return its meaning
    string GetMeaning(const string& key) {
        for (const auto& entry : entries) {
            if (entry.first == key) {
                return entry.second;
            }
        }
        return "Word not found in the dictionary.";
    }

    // Print all entries in the dictionary
    void PrintDictionary() {
        for (const auto& entry : entries) {
            cout << entry.first << ": " << entry.second << endl;
        }
    }
};

int main() {
    Dictionary TestDictionary;

    // Adding entries to the dictionary
    TestDictionary.AddMeaning("STL", "Standard Template Library");
    TestDictionary.AddMeaning("ADT", "Abstract Data Type");
    TestDictionary.AddMeaning("ATP", "Adenosine Transporter Protein");
      
    cout << "\n";
    // Look up and print the meaning of a word
    cout << "Meaning of 'STL': " << TestDictionary.GetMeaning("STL") << endl;
    cout << "\n";
    cout << "Meaning of 'ATP': " << TestDictionary.GetMeaning("ATP") << endl;
    cout << "\n";
    cout << "Meaning of 'Hash': " << TestDictionary.GetMeaning("Hash") << endl;

    // Print the entire dictionary
    cout << "\nDictionary Contents:\n";
    TestDictionary.PrintDictionary();

    return 0;
}
