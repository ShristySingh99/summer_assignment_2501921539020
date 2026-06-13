
#include <iostream>
#include <memory>

using namespace std;

namespace music {
    class Playable {
    public:
        virtual void play() = 0;
        virtual ~Playable() {}
    };
    
  
    namespace string {
        class Veena : public Playable {
        public:
            void play() override {
                cout << "Veena is being played. Its strings produce melodious classical music!" << endl;
            }
        };
    }
    
    
    namespace wind {
        class Saxophone : public Playable {
        public:
            void play() override {
                cout << "Saxophone is being played. Its wind produces smooth jazz music!" << endl;
            }
        };
    }
}

namespace live {
    class Test {
    public:
        static void run() {
            cout << " MUSICAL INSTRUMENT TEST\n" << endl;
            
          
            cout << " Veena " << endl;
            music::string::Veena veena;
            veena.play();
            
        
            cout << "\nSaxophone " << endl;
            music::wind::Saxophone saxophone;
            saxophone.play();
            
            
            cout << "\nPolymorphism " << endl;
            
            music::Playable* p1 = new music::string::Veena();
            music::Playable* p2 = new music::wind::Saxophone();
            
            cout << "Playable reference to Veena: ";
            p1->play();
            
            cout << "Playable reference to Saxophone: ";
            p2->play();
            
            delete p1;
            delete p2;
        }
    };
}

int main() {
    live::Test::run();
    return 0;
}
