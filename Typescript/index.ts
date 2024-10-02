/**
 * Challenge: Create a Pizza object type. It should include a `name`
 * and a `price` property.
 */

const menu = [
  { name: 'Margherita', price: 8 },
  { name: 'Pepperoni', price: 10 },
  { name: 'Hawaiian', price: 10 },
  { name: 'Veggie', price: 9 },
];

 type Pizza = {
  name: string;
  price: number;
};
 type Order = {
  id: number;
  status: string;
  pizza:Pizza
};
let cashInRegister = 100;
let nextOrderId = 1;
const orderQueue: Order[] = [];

function addNewPizza(pizzaObj: Pizza) {
  menu.push(pizzaObj);
}

function placeOrder(pizzaName: string) {
  const selectedPizza = menu.find((pizzaObj) => pizzaObj.name === pizzaName);
  if (!selectedPizza) {
    console.error(`${pizzaName} does not exist in the menu`);
    return;
  }
  cashInRegister += selectedPizza.price;
  const newOrder = {
    id: nextOrderId++,
    pizza: selectedPizza,
    status: 'ordered',
  };
  orderQueue.push(newOrder);
  return newOrder;
}

function completeOrder(orderId: number) {
  const order = orderQueue.find((order) => order.id === orderId);
  if (order) {
    order.status = 'completed';
  }
  return order;
}

addNewPizza({
  name: 'Chicken Bacon Ranch',
  price: 12,
});
addNewPizza({
  name: 'BBQ Chicken',
  price: 12,
});
addNewPizza({
  name: 'Spicy Sausage',
  price: 11,
});

placeOrder('Chicken Bacon Ranch');
completeOrder(1);

console.log('Menu:', menu);
console.log('Cash in register:', cashInRegister);
console.log('Order queue:', orderQueue);
