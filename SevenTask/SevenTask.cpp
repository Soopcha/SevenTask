#include <iostream>
#include <string>
using namespace std;

struct Dessert {
    string name;
    double price;
    int calories;
    Dessert* next; //ссылка на след эл в сипске десертов
};

/*Стрелка -> в языке программирования C++ используется для доступа к членам структуры или класса, 
через указатель на экземпляр структуры или класса. 
Например, если есть указатель ptr на структуру dessert, чтобы получить доступ к члену name структуры, 
нужно использовать стрелку ->:ptr->name.
Это аналогично операции доступа через точку ., которая используется для доступа к членам структуры или класса, 
когда мы имеем сам объект, а не указатель на него.
*/

void addDessert(Dessert*& head) {
    Dessert* dessert = new Dessert;
    cout << "Enter dessert name: ";
    cin >> dessert->name;
    cout << "Enter dessert price: ";
    cin >> dessert->price;
    cout << "Enter dessert calories: ";
    cin >> dessert->calories;
    dessert->next = head;
    head = dessert;         //дессерты добавляются с начала( те каждая новая структура
    //добавляется в начало списка (список растет "назад"))
    cout << "Dessert added to database." << endl;
}

void removeDessert(Dessert*& head) {
    if (head == nullptr) {
        cout << "Error: database is empty." << endl;
        return;
    }

    string name;
    cout << "Enter dessert name to remove: ";
    cin >> name;

    if (head->name == name) {
        Dessert* temp = head;
        head = head->next;
        delete temp;
        cout << "Dessert removed from database." << endl;
        return;
    }

    Dessert* current = head;
    while (current->next != nullptr) {
        if (current->next->name == name) {
            Dessert* temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << "Dessert removed from database." << endl;
            return;
        }
        current = current->next;
    }

    cout << "Error: dessert not found in database." << endl;
}

void printDesserts(Dessert* head) {
    if (head == nullptr) {
        cout << "Database is empty." << endl;
        return;
    }

    cout << "Name  Price  Calories" << endl;
    Dessert* current = head;
    while (current != nullptr) {
        cout << current->name << "   " << current->price << "   " << current->calories << endl;
        current = current->next;
    }
}

int main() {
    Dessert* head = nullptr;

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Add dessert" << endl;
        cout << "2. Remove dessert" << endl;
        cout << "3. Print desserts" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addDessert(head);
            cout << endl;
            break;
        case 2:
            removeDessert(head);
            cout << endl;
            break;
        case 3:
            printDesserts(head);
            cout << endl;
            break;
        case 4:
            cout << "Exiting program." << endl;
            cout << endl;
            break;
        default:
            cout << "Error: invalid choice." << endl;
            cout << endl;
            break;
        }
    } while (choice != 4);

    // Free memory
    Dessert* current = head;
    while (current != nullptr) {  // nullptr - это ключ слово, которое используется для представления нулевого указателя. (вместо null)
        Dessert* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
