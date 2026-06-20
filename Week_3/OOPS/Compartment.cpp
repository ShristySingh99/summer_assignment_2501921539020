#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


class Compartment {
public:

    virtual std::string notice() = 0;    

    virtual ~Compartment() {}
};


class FirstClass : public Compartment {
public:
    std::string notice() override {
        return "First Class: Luxury travel. Please maintain silence and respect privacy.";
    }
};


class Ladies : public Compartment {
public:
    std::string notice() override {
        return "Ladies Compartment: Strictly reserved for female passengers.";
    }
};


class General : public Compartment {
public:
    std::string notice() override {
        return "General Compartment: Open seating. Please cooperate with fellow passengers.";
    }
};


class Luggage : public Compartment {
public:
    std::string notice() override {
        return "Luggage Compartment: For heavy baggage only. Passengers not allowed to travel here.";
    }
};


int main() {
   
    std::srand(static_cast<unsigned int>(std::time(0)));

   
    Compartment* train[10];

    std::cout << "--- Initializing Train Compartments Randomly ---\n\n";

   
    for (int i = 0; i < 10; ++i) {
       
        int randomType = (std::rand() % 4) + 1;

        switch (randomType) {
            case 1:
                train[i] = new FirstClass();
                break;
            case 2:
                train[i] = new Ladies();
                break;
            case 3:
                train[i] = new General();
                break;
            case 4:
                train[i] = new Luggage();
                break;
        }
    }

    
    for (int i = 0; i < 10; ++i) {
        std::cout << "Compartment [" << i + 1 << "] Notice: " << train[i]->notice() << "\n";
    }

    
    for (int i = 0; i < 10; ++i) {
        delete train[i];
    }

    return 0;
}
