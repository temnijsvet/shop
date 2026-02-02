#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
struct Product {
    std::string name;
    double price;
    int quantity;
};
int main() {
    setlocale(LC_ALL, "Rus");
    std::vector<Product> products = {
        {"Молоко", 60.0, 10},
        {"Хлеб", 30.0, 20},
        {"Яблоко", 15.5, 30},
        {"Сок", 100.0, 5},
        {"Сыр", 200.0, 7}
    };
    std::map<int, int> cart;
    while (true) {
        std::cout << "\nТовары в наличии:\n";
        std::cout << "№ | Наименование | Цена | В наличии\n";
        for (size_t i = 0; i < products.size(); ++i) {
            std::cout << i + 1 << " | " << products[i].name
                << " | " << std::fixed << std::setprecision(2) << products[i].price
                << " | " << products[i].quantity << "\n";
        }
        std::cout << "\nВведите номер товара для добавления в корзину (0 для завершения): ";
        int choice;
        std::cin >> choice;
        if (choice == 0) break;
        if (choice < 1 || choice >(int)products.size()) {
            std::cout << "Неверный номер товара, попробуйте снова.\n";
            continue;
        }
        int prodIndex = choice - 1;
        std::cout << "Введите количество: ";
        int count;
        std::cin >> count;
        if (count < 1) {
            std::cout << "Количество должно быть положительным.\n";
            continue;
        }
        if (count > products[prodIndex].quantity) {
            std::cout << "На складе недостаточно товара, доступно: " << products[prodIndex].quantity << "\n";
            continue;
        }
        cart[prodIndex] += count;
        products[prodIndex].quantity -= count;
        std::cout << "Добавлено в корзину: " << products[prodIndex].name << " x" << count << "\n";
    }
    std::cout << "\nВаш кассовый чек:\n";
    std::cout << "Наименование | Кол-во | Цена за ед. | Стоимость\n";
    double total = 0.0;
    for (const auto& item : cart) {
        int index = item.first;
        int quantity = item.second;
        double price = products[index].price;
        double cost = price * quantity;
        total += cost;
        std::cout << products[index].name << " | " << quantity << " | "
            << std::fixed << std::setprecision(2) << price << " | " << cost << "\n";
    }
    std::cout << "-------------------------\n";
    std::cout << "ИТОГО к оплате: " << std::fixed << std::setprecision(2) << total << " руб.\n";
    return 0;
}