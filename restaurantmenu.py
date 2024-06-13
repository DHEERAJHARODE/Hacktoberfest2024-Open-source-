menu = {
    "Burger": 400,    # Price in INR
    "Pizza": 600,     # Price in INR
    "Pasta": 499,     # Price in INR
    "Salad": 299,     # Price in INR
    "Soda": 99        # Price in INR
}

order = []

print("Welcome to the Restaurant Menu:")
for item, price_inr in menu.items():
    print(f"{item}: ₹{price_inr}")

while True:
    user_input = input("Enter the item you'd like to order (or 'q' to quit): ").capitalize()

    if user_input == 'Q':
        break
    elif user_input in menu:
        order.append(user_input)
    else:
        print("Invalid item. Please choose from the menu.")

total_cost_inr = sum(menu[item] for item in order)

print("\nYour order:")
for item in order:
    print(item)
print(f"Total cost: ₹{total_cost_inr}")

