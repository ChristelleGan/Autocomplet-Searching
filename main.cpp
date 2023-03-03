#include <iostream>
#include<fstream>
#include<string>
using namespace std;

class Bag{
private:
    string name;
    string items[100];
    int count;
    
public:
    Bag() {
        this->count = 0;
        this->name = "";
    }
    
    void setName(string name) {
        this->name = name;
    };
    
    void addItem(string item) {
        this->items[count] = item;
        this->count++;
    }
    
    int getCount() {
        return this->count;
    }
    
    void displayAll() {
        for (int i = 0; i < this->count; i++){
            cout << this->items[i] << endl;
        }
    }
    //extra credit for searching keywords in the string
    void search(string keyword) {
        int totalMatch = 0;
        for (int i = 0; i < this->count; i++) {
            size_t found = this->items[i].find(keyword);
            if (found != string::npos) {
                cout << this->items[i] << endl;
                totalMatch ++;
            }
        }
        if (totalMatch == 0){
            cout << "No matching found..." << endl;
        }
    }
    //search the string which started with the keywords
    void match(string keyword){
        int totalMatch = 0;
        for (int i = 0; i < this->count; i++){
            bool isMatch = true;
            for (int j = 0; j < keyword.length(); j++){
                if (keyword.at(j) != this->items[i].at(j)){
                    isMatch = false;
                    break;
                }
            }
            if (isMatch){
                cout << this->items[i] << endl;
                totalMatch++;
            }
        }
        if (totalMatch == 0){
            cout << "No matching found..." << endl;
        }
    }
    
};

bool promptSearch(); // prompt the user whether to continuce to search or not

int main(){
    Bag myBag = Bag();
    //read from the file
    ifstream infile;
    infile.open("/Users/christellegan/Documents/CSI/CSC326/Labs/CSC326Lab1/SourceList.txt");
    if(!infile){
        cout << "There is an error to open the file." << endl;
    }
    //add the string which read from the file into the items array
    string line;
    while (getline(infile, line))
    {
        myBag.addItem(line);
    }
    //display all the items currently
    myBag.displayAll();
    //display the total number of the items, this extra output is for selfcheck
    cout << "Total: " << myBag.getCount() << endl;
    //read from the input instead of keyboard
    string input;
    bool isSearching = true;
    while (isSearching) {
        cout << "Search: ";
        cin >> input;
        //if less than 3 characters are entered, display the whole list
        if (input.length() < 3){
            myBag.displayAll();
        }else{
            myBag.search(input); // display the matching lists
        }
        cout << endl;
        isSearching = promptSearch();
    }
    return 0;
}

// prompt the user whether to continuce to search or not
bool promptSearch(){
    char isContinue;
    cout << "Continue? Please enter 'y' for yes; 'n' for no." << endl;
    cin >> isContinue;

    if (isContinue != 'y')
        return false;
    else{
        //clear the screen
        return true;
    }
}

