#include <iostream>
#include <string>
using namespace std;

class Record{
    public:
    string name;
    string utang[50];
    int price[50];
    
    // setter 

    void set_sizeOfUtang(int size) {
        sizeOfUtang = size;
    }

    void set_utang(int sum){
        totalUtang = sum;
    }

    //getter
    int get_utang(){
        return totalUtang;
    }


     void print() {
        cout << "Name: " << name << endl;
        cout << "Utang details:" << endl;
        for (int i = 0; i < sizeOfUtang; i++) {
            cout << "  Item " << i + 1 << ": " << utang[i] << " - " << price[i] << endl;
        }
        cout << "Total Utang: " << get_utang() << endl;
        cout << "----------------------" << endl;
    }

    private:
    int totalUtang;
    int sizeOfUtang;  
};


int main(){
    int size;

    cout << "Enter the number of people who have utang: ";
    cin >> size;

    Record list[size];
    //Record* list = (Record*)malloc(size * sizeof(Record));

    for(int i = 0; i < size; i++){
        cout << "\nEnter name "<< i + 1 <<": ";
        cin >> list[i].name;

        int sizeOfUtang = 0;
        cout << "Enter the number of utangs: ";
        cin >> sizeOfUtang;

        list[i].set_sizeOfUtang(sizeOfUtang); // Set the number of utangs for person i

        int sum = 0;
        for(int j = 0; j < sizeOfUtang; j++){
            cin.ignore();
            cout << "Enter the name of the item " << j+1 << ": ";
            getline(cin, list[i].utang[j]);

            cout << "Enter the price of the item " << j+1 << ": ";
            cin >> list[i].price[j];

            sum += list[i].price[j];
        }

        list[i].set_utang(sum);

    }

    cout << "\nMga Utang:\n";
    for (int i = 0; i < size; i++) {
        list[i].print();
    }

    return 0; 
}