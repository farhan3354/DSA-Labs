#include <iostream>
#include <string>
using namespace std;

const int MAX_HISTORY = 100;

class TextEditor {
private:
    string text;
    string undoStack[MAX_HISTORY];
    string redoStack[MAX_HISTORY];
    int undoTop;
    int redoTop;
    
public:
    TextEditor() {
        text = "";
        undoTop = -1;
        redoTop = -1;
    }
    
    void saveToUndo() {
        if (undoTop < MAX_HISTORY - 1) {
            undoStack[++undoTop] = text;
        }
        redoTop = -1;
    }
    
    void typeChar(char ch) {
        saveToUndo();
        text += ch;
        cout << "Typed: " << ch << " | Current text: \"" << text << "\"" << endl;
    }
    
    void deleteChar() {
        if (text.empty()) {
            cout << "Nothing to delete! Text is empty." << endl;
            return;
        }
        saveToUndo();
        text.pop_back();
        cout << "Deleted last character | Current text: \"" << text << "\"" << endl;
    }
    
    void deleteChars(int count) {
        if (text.empty()) {
            cout << "Nothing to delete! Text is empty." << endl;
            return;
        }
        
        int deleteCount = (count > text.length()) ? text.length() : count;
        saveToUndo();
        
        for (int i = 0; i < deleteCount; i++) {
            text.pop_back();
        }
        
        cout << "Deleted " << deleteCount << " character(s) | Current text: \"" << text << "\"" << endl;
    }
    
    void undo() {
        if (undoTop == -1) {
            cout << "Nothing to undo!" << endl;
            return;
        }
        
        if (redoTop < MAX_HISTORY - 1) {
            redoStack[++redoTop] = text;
        }
        
        text = undoStack[undoTop--];
        cout << "Undo performed | Current text: \"" << text << "\"" << endl;
    }
    
    void redo() {
        if (redoTop == -1) {
            cout << "Nothing to redo!" << endl;
            return;
        }
        
        if (undoTop < MAX_HISTORY - 1) {
            undoStack[++undoTop] = text;
        }
        
        text = redoStack[redoTop--];
        cout << "Redo performed | Current text: \"" << text << "\"" << endl;
    }
    
    void displayText() {
        if (text.empty()) {
            cout << "Current text: (empty)" << endl;
        } else {
            cout << "Current text: \"" << text << "\"" << endl;
        }
        cout << "Text length: " << text.length() << " characters" << endl;
    }
    
    void clearText() {
        if (!text.empty()) {
            saveToUndo();
            text = "";
            cout << "Text cleared!" << endl;
        } else {
            cout << "Text is already empty!" << endl;
        }
    }
};

int main() {
    TextEditor editor;
    int choice, count;
    char ch;
    
    do {
        cout << "1. Type a character\n";
        cout << "2. Delete last character\n";
        cout << "3. Delete multiple characters\n";
        cout << "4. Undo\n";
        cout << "5. Redo\n";
        cout << "6. Display current text\n";
        cout << "7. Clear all text\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter character to type: ";
                cin >> ch;
                editor.typeChar(ch);
                break;
                
            case 2:
                editor.deleteChar();
                break;
                
            case 3:
                cout << "Enter number of characters to delete: ";
                cin >> count;
                editor.deleteChars(count);
                break;
                
            case 4:
                editor.undo();
                break;
                
            case 5:
                editor.redo();
                break;
                
            case 6:
                editor.displayText();
                break;
                
            case 7:
                editor.clearText();
                break;
                
            case 8:
                cout << "Exiting text editor. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while(choice != 8);
    
    return 0;
}