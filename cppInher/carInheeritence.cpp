#include <iostream>
#include <string>

class Car
{
protected:
    bool isSedan;
    std::string seats;

public:
    Car(bool a, std::string b) : isSedan(a), seats(b){};
    bool getIsSedan()
    {
        return isSedan;
    }
    std::string getSeats()
    {
        return seats;
    }
    virtual std::string getMileage() = 0;
    void printCar(std::string name){
        std::cout << "A " << name << " is "<< (this->getIsSedan()?"a":"not a")<< " sedan, is " << this->getSeats()<< " and has a mileage of around "<< this->getMileage() <<std::endl;
    }
};

class WagonR : public Car
{
    int mileage;
public:
    WagonR(int mileage) : Car(false, "4-seater"), mileage(mileage){};

    std::string getMileage()
    {
        return std::to_string(mileage) + " kmpl";
    }
};
class HondaCity : public Car
{
    int mileage;
public:
    HondaCity(int mileage) : Car(true, "4-seater"), mileage(mileage){};

    std::string getMileage()
    {
        return std::to_string(mileage) + " kmpl";
    }
};
class InnovaCrysta : public Car
{
    int mileage;
public:
    InnovaCrysta(int mileage) : Car(false, "6-seater"), mileage(mileage){};

    std::string getMileage()
    {
        return std::to_string(mileage) + " kmpl";
    }
};

int main()
{
    char choice;
    int mileage;
    //std::cout << "Enter the type of car: [0] for WagonR, [1] for HondaCity, and [2] for InnovaCrysta" << std::endl;
    std::cin >> choice ;
    std::cin >> mileage;
    //std::cout << "Enter the mileage of car:" << std::endl;
    Car *car;

    switch (choice){
        case '0':
            car = new WagonR(mileage);
            car->printCar("WagonR");
            break;
        case '1':
            car = new HondaCity(mileage);
            car->printCar("Honda City");
            break;
        case '2':
            car = new InnovaCrysta(mileage);
            car->printCar("Innova Crysta");
            break;
        default:
            car = new WagonR(mileage);
            std::cout << "\n INVALID CAR TYPE, ENTER AGAIN";
    }
    delete car;
    return 0;
}
