#include <iostream>
#include <vector>

class Product {
public:
	std::string name;
	double price;
	int productId;

	Product(const std::string& name, double price, int productId)
		: name(name), price(price), productId(productId) {}
};

class Customer {
public:
	std::string name;
	std::string email;
	int customerId;

	Customer(const std::string& name, const std::string& email, int customerId)
		: name(name), email(email), customerId(customerId) {}

	void placeOrder(const std::vector<Product>& products) {
    
  class Order {
public:
	Customer customer;
	std::vector<Product> products;
	int orderId;

	Order(const Customer& customer, const std::vector<Product>& products)
		: customer(customer), products(products), orderId(generateOrderId()) {}

	double calculateTotalCost() const {
		double total = 0.0;
		for (const auto& product : products) {
			total += product.price;
		}
		return total;
	}

private:
	static int generateOrderId() {
		static int orderIdCounter = 1;
		return orderIdCounter++;
	}
};
		Order order(*this, products);
		double totalCost = order.calculateTotalCost();
		std::cout << "Order placed successfully. Total cost: $" << totalCost << std::endl;
	}
};


int main() {
	Product product1("Product 1", 10.0, 1);
	Product product2("Product 2", 15.0, 2);
	Product product3("Product 3", 20.0, 3);

	Customer customer("John Smith", "john.smith@gmail.com", 1);

	std::vector<Product> products = { product1, product2, product3 };
	customer.placeOrder(products);

	return 0;
}
