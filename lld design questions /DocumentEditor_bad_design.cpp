#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class DocumentEditor {
    private:
        vector<string> documentElements;
    public:
        void addTextElement(const string &text) {
            documentElements.push_back(text);
        }
        void addImageElement(const string &imagePath) {
            documentElements.push_back(imagePath);
        }
        string renderDocument() {
            string ans = "";
            for (const auto &i : documentElements) {
                if (i.size() > 4 && (i.substr(i.size() - 4) == ".png" || i.substr(i.size() - 4) == ".jpg")) {
                    ans += "[Image: " + i + "]\n";
                } else {
                    ans += i + "\n";
                }
            }
            return ans;
        }
        void saveToFile() {
            ofstream file("document.txt");
            if (file.is_open()) {
                file << renderDocument();
                file.close();
            }
        }
};

int main() {
    DocumentEditor editor;
    editor.addTextElement("Hello, this is a sample document.");
    editor.addImageElement("image1.png");
    editor.addTextElement("This is another text element.");
    editor.addImageElement("photo.jpg");

    cout << "Rendered Document:\n" << editor.renderDocument();

    editor.saveToFile();
    cout << "Document saved to document.txt" << endl;

    return 0;
}