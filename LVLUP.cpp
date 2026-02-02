#include <iostream>
#include <string>
#include <vector>
#include <map>
struct Product {
    std::string name;
    int available;
};
void showProducts(const std::vector<Product>& products) {
    std::cout << "Список товаров:\n";
    for (size_t i = 0; i < products.size(); ++i) {
        std::cout << i + 1 << ". " << products[i].name << " (в наличии: " << products[i].available << ")\n";
    }
}
void showCart(const std::map<std::string, int>& cart) {
    std::cout << "\nВаша корзина:\n";
    if (cart.empty()) {
        std::cout << "Корзина пустая.\n";
        return;
    }
    for (const auto& item : cart) {
        std::cout << item.first << " - " << item.second << " шт.\n";
    }
    std::cout << std::endl;
}
int main() {
    setlocale(LC_ALL, "Rus");
    std::vector<Product> products = {
        {"Молоко", 10},
        {"Яблоко", 20},
        {"Хлеб", 15},
        {"Сыр", 5}
    };
    std::map<std::string, int> cart;
    while (true) {
        showProducts(products);
        std::cout << "\nВведите номер товара для добавления в корзину (0 - выход): ";
        int choice;
        std::cin >> choice;
        if (choice == 0) {
            break;
        }
        if (choice < 1 || choice >(int)products.size()) {
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            continue;
        }
        Product& selected = products[choice - 1];
        if (selected.available == 0) {
            std::cout << "Товара \"" << selected.name << "\" нет в наличии.\n";
            continue;
        }
        std::cout << "Введите количество для товара \"" << selected.name << "\": ";
        int qty;
        std::cin >> qty;
        if (qty < 1 || qty > selected.available) {
            std::cout << "Недопустимое количество. В наличии: " << selected.available << "\n";
            continue;
        }
        cart[selected.name] += qty;
        selected.available -= qty;
        std::cout << "Добавлено в корзину: " << selected.name << " - " << qty << " шт.\n";
        showCart(cart);
    }
    std::cout << "\nИтоговый чек:\n";
    showCart(cart);
    std::cout << "Спасибо за покупку!\n";
    return 0;
}