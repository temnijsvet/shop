#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};

int main() {
    setlocale(LC_ALL, "Rus");// Локализация на Русский язык
    vector<Product> products = {
        {"Молоко      ", 60.0, 10},
        {"Хлеб        ", 30.0, 20},
        {"Яблоко      ", 15.5, 30},
        {"Сок         ", 100.0, 5},
        {"Сыр         ", 200.0, 7}
    };

    map<int, int> cart;
    while (true) {
        cout << "\nТовары в наличии:\n";
        cout << "№ | Наименование | Цена | В наличии\n";
        for (size_t i = 0; i < products.size(); ++i) {
            cout << i + 1 << " | " << products[i].name
                << " | " << fixed << setprecision(2) << products[i].price
                << " | " << products[i].quantity << "\n";
        }

        cout << "\nВведите номер товара для добавления в корзину (0 для завершения): ";
        int choice;
        cin >> choice;
        if (choice == 0) break;
        if (choice < 1 || choice >(int)products.size()) {
            cout << "Неверный номер товара, попробуйте снова.\n";
            continue;
        }

        int prodIndex = choice - 1;
        cout << "Введите количество: ";
        int count;
        cin >> count;
        if (count < 1) {
            cout << "Количество должно быть положительным.\n";
            continue;
        }

        if (count > products[prodIndex].quantity) {
            cout << "На складе недостаточно товара, доступно: " << products[prodIndex].quantity << "\n";
            continue;
        }

        cart[prodIndex] += count;
        products[prodIndex].quantity -= count;
        cout << "Добавлено в корзину: " << products[prodIndex].name << " x" << count << "\n";
    }

    cout << "\nВаш кассовый чек:\n";
    cout << "Наименование | Кол-во | Цена за ед. | Стоимость\n";
    double total = 0.0;
    for (const auto& item : cart) {
        int index = item.first;
        int quantity = item.second;
        double price = products[index].price;
        double cost = price * quantity;
        total += cost;
        cout << products[index].name << " | " << quantity << " | "
            << fixed << setprecision(2) << price << " | " << cost << "\n";
    }

    cout << "-------------------------\n";
    cout << "ИТОГО к оплате: " << fixed << setprecision(2) << total << " руб.\n";
    return 0;
}
