#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Interface
class LibraryUser {
public:
    virtual void registerAccount() = 0;
    virtual void requestBook() = 0;
    virtual ~LibraryUser() {}
};

// KidUsers with private members (better encapsulation)
class KidUsers : public LibraryUser {
private:
    int age;
    string bookType;
    
public:
    KidUsers(int a = 0, string b = "") : age(a), bookType(b) {}
    
    // Setter methods (optional - for flexibility)
    void setAge(int a) { age = a; }
    void setBookType(string bt) { bookType = bt; }
    
    void registerAccount() override {
        if (age < 12) {
            cout << "You have successfully registered under a Kids Account" << endl;
        } else {
            cout << "Sorry, Age must be less than 12 to register as a kid" << endl;
        }
    }
    
    void requestBook() override {
        // Case-insensitive comparison
        string bt = bookType;
        transform(bt.begin(), bt.end(), bt.begin(), ::tolower);
        
        if (bt == "kids") {
            cout << "Book Issued successfully, please return the book within 10 days" << endl;
        } else {
            cout << "Oops, you are allowed to take only kids books" << endl;
        }
    }
};

// AdultUser with private members
class AdultUser : public LibraryUser {
private:
    int age;
    string bookType;
    
public:
    AdultUser(int a = 0, string b = "") : age(a), bookType(b) {}
    
    void setAge(int a) { age = a; }
    void setBookType(string bt) { bookType = bt; }
    
    void registerAccount() override {
        if (age > 12) {
            cout << "You have successfully registered under an Adult Account" << endl;
        } else {
            cout << "Sorry, Age must be greater than 12 to register as an adult" << endl;
        }
    }
    
    void requestBook() override {
        string bt = bookType;
        transform(bt.begin(), bt.end(), bt.begin(), ::tolower);
        
        if (bt == "fiction") {
            cout << "Book Issued successfully, please return the book within 7 days" << endl;
        } else {
            cout << "Oops, you are allowed to take only adult Fiction books" << endl;
        }
    }
};

// Your efficient way of testing (reusing objects)
int main() {
    cout << "========== TEST CASE #1: KidUser ==========" << endl;
    KidUsers kid;
    
    cout << "\n--- Register Account Tests ---" << endl;
    kid.setAge(10);
    cout << "Age 10: ";
    kid.registerAccount();
    
    kid.setAge(18);
    cout << "Age 18: ";
    kid.registerAccount();
    
    cout << "\n--- Request Book Tests ---" << endl;
    kid.setBookType("Kids");
    cout << "BookType 'Kids': ";
    kid.requestBook();
    
    kid.setBookType("Fiction");
    cout << "BookType 'Fiction': ";
    kid.requestBook();
    
    cout << "\n========== TEST CASE #2: AdultUser ==========" << endl;
    AdultUser adult;
    
    cout << "\n--- Register Account Tests ---" << endl;
    adult.setAge(5);
    cout << "Age 5: ";
    adult.registerAccount();
    
    adult.setAge(23);
    cout << "Age 23: ";
    adult.registerAccount();
    
    cout << "\n--- Request Book Tests ---" << endl;
    adult.setBookType("Kids");
    cout << "BookType 'Kids': ";
    adult.requestBook();
    
    adult.setBookType("Fiction");
    cout << "BookType 'Fiction': ";
    adult.requestBook();
    
    return 0;
}
