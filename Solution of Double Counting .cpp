
#include <iostream>
using namespace std;

class ProductionStage {
private:
    string name;
    double cost;
    double valueAdded;

public:
    ProductionStage(string n) {
        name = n;
        cost = 0.0;
        valueAdded = 0.0;
    }

    void setCost(double c) {
        cost = c;
    }

    void calculateValueAdded(double previousCost) {
        valueAdded = cost - previousCost;
    }

    void displayInfo() {
        cout << name << ": Value Added = " << valueAdded << endl;
    }

    double getValueAdded() {
        return valueAdded;
    }
};

int main() {
  ProductionStage rawMaterials("Raw Materials");
    cout << "Enter the cost of raw materials: ";
    double rawMaterialCost;
    cin >> rawMaterialCost;
    rawMaterials.setCost(rawMaterialCost);
    rawMaterials.calculateValueAdded(0.0);

    ProductionStage manufacturing("Manufacturing");
    cout << "Enter the manufacturing cost: ";
    double manufacturingCost;
    cin >> manufacturingCost;
    manufacturing.setCost(manufacturingCost);
    manufacturing.calculateValueAdded(rawMaterialCost);

    ProductionStage consumer("Consumer");
    cout << "Enter the consumer price: ";
    double consumerPrice;
    cin >> consumerPrice;
    consumer.setCost(consumerPrice);
    consumer.calculateValueAdded(manufacturingCost);

    cout << endl << "Final Calculation:" << endl;
    rawMaterials.displayInfo();
    manufacturing.displayInfo();
    consumer.displayInfo();

    double totalValueAdded = rawMaterials.getValueAdded() + manufacturing.getValueAdded() + consumer.getValueAdded();
    cout << endl << "Total Value Added in Production to Consumer Phase: " << totalValueAdded << endl;

    return 0;
} 
