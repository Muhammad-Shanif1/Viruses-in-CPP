#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
int main() {
    // Replace "C:\\path\\to\\your\\file\\example.exe" with the full path to your .exe file
    ifstream inputFile(R"(C:\Users\Muhammad Shanif\Desktop\scan)",ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Error opening file\n";
        return 1;
    }
    string targetWord = "helloTalha"; // Replace "specific_word" with your target word
    vector<char> buffer(targetWord.begin(), targetWord.end());
    size_t bufferSize = buffer.size();

    vector<char> fileContent(istreambuf_iterator<char>(inputFile), {});

    for (size_t i = 0; i < fileContent.size() - bufferSize + 1; ++i) {
        if (memcmp(&fileContent[i], buffer.data(), bufferSize) == 0) {
            cout << "Found the word '" << targetWord << "' at offset " << i << "\n";
        }
    }

    inputFile.close();
    return 0;
}