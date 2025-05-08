#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string m_brand;
    string m_DriveMode;
    int m_year;
    int m_MaxSeating;
    int m_price;

    void m_UpdatePrice(int base = 500000) {
        m_price = m_MaxSeating * base;
    }

    void set_DriveModeByBrand(string brand) {
        if (brand == "BMW") m_DriveMode = "Rear-wheel";
        else if (brand == "AUDI" || brand == "BENZ") m_DriveMode = "Front-wheel";
        else m_DriveMode = "Unknown";
    }

public:
    Car(string brand, int year, int maxSeating)
        : m_brand(brand), m_year(year), m_MaxSeating(maxSeating) {
        set_DriveModeByBrand(brand);
        m_UpdatePrice();
        cout << "Constructing " << m_brand << " Car\n";
    }

    string get_DriveMode() const {
        return m_DriveMode;
    }

    string get_Brand() const {
        return m_brand;
    }

    int get_Year() const {
        return m_year;
    }

    int get_Seating() const {
        return m_MaxSeating;
    }

    int get_Price() const {
        return m_price;
    }
};

int main() {
    Car car1("BMW", 2023, 5);
    Car car2("AUDI", 2022, 4);
    Car car3("BENZ", 2024, 6);

    cout << car1.get_Brand() << ": Drive Mode = " << car1.get_DriveMode() << endl;
    cout << car2.get_Brand() << ": Drive Mode = " << car2.get_DriveMode() << endl;
    cout << car3.get_Brand() << ": Drive Mode = " << car3.get_DriveMode() << endl;

    return 0;
}
