/*Побудувати асоційований клас збереження
двох сутностей. В завданні створити клас, який представляє собою 
асоціативний масив між двома сутностями. Написати функцію створення 
набору асоціативних сутностей. Перевантажити операцію індексації [] –
функцію, яка звертається до об’єкта класу, за однією сутністю, якщо індекс, 
повертає асоціативну сутність, якщо відповідної сутності немає в встановлює 
код помилки у змінну CodeError, альтернативні звернення через 
перевантаження операції виклику функції(); перевантажити дружні операції 
введення та виведення.
Номер телефону та прізвище, ім’я, по-батькові.*/

#include <iostream>

using namespace std;

struct Contact{
    string phone, lastName, firstName, middleName;
};

class Phonebook{
private:
    Contact* data;
    int size;
    const char* CodeError = "Error: Entry not found.";

public:
    Phonebook() : data(nullptr), size(0) {}
    void add(const string& phone, const string& lastName, const string& firstName, const string& middleName){
        Contact* newData = new Contact[size + 1];
        for (int i = 0; i < size; i++){
            newData[i] = data[i];
        }
        newData[size].phone = phone;
        newData[size].lastName = lastName;
        newData[size].firstName = firstName;
        newData[size].middleName = middleName;
        delete[] data;
        data = newData;
        size++;
    }

    Contact& operator[](const string& phone){
        for (int i = 0; i < size; i++){
            if (data[i].phone == phone){
                return data[i];
            }
        }
        throw CodeError;
    }

    void print() const{
        for (int i = 0; i < size; i++) {
            cout << "Phone Number: " << data[i].phone << endl;
            cout << "Last Name: " << data[i].lastName << endl;
            cout << "First Name: " << data[i].firstName << endl;
            cout << "Middle Name: " << data[i].middleName << endl;
        }
    }

    friend ostream& operator<<(ostream& out, const Phonebook& contacts);
    friend istream& operator>>(istream& in, Phonebook& contacts);

    ~Phonebook(){
        delete[] data;
    }
};

ostream& operator<<(ostream& out, const Phonebook& contacts){
    for (int i = 0; i < contacts.size; i++) {
        out << "Phone Number: " << contacts.data[i].phone << endl;
        out << "Last Name: " << contacts.data[i].lastName << endl;
        out << "First Name: " << contacts.data[i].firstName << endl;
        out << "Middle Name: " << contacts.data[i].middleName << endl;
    }
    return out;
}

istream& operator>>(istream& in, Phonebook& contacts){
    string phone, lastName, firstName, middleName;
    cout << "Enter Phone Number: ";
    in >> phone;
    cout << "Enter Last Name: ";
    in >> lastName;
    cout << "Enter First Name: ";
    in >> firstName;
    cout << "Enter Middle Name: ";
    in >> middleName;
    contacts.add(phone, lastName, firstName, middleName);
    return in;
}

int main(){
    Phonebook contacts;
    cout << "Enter entry 1:" << endl;
    cin >> contacts;
    cout << "Enter entry 2:" << endl;
    cin >> contacts;
    cout << "Entries:" << endl;
    cout << contacts;

    try{
        Contact& info = contacts["12345"];
        cout << "Found: " << info.phone << " " << info.lastName << " " << info.firstName << " " << info.middleName << endl;
    } catch (const char* e){
        cout << e << endl;
    }

    return 0;
}

