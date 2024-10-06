import React, { useState, useEffect } from 'react';
import { Button } from "@/components/ui/button";
import { Card, CardContent, CardFooter, CardHeader, CardTitle } from "@/components/ui/card";
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from "@/components/ui/select";
import { motion } from "framer-motion";

const App = () => {
  const [darkMode, setDarkMode] = useState(false);
  const [selectedRestaurant, setSelectedRestaurant] = useState('');
  const [selectedFood, setSelectedFood] = useState('');
  const [quantity, setQuantity] = useState(1);
  const [order, setOrder] = useState({});
  const [showPayment, setShowPayment] = useState(false);
  const [amount, setAmount] = useState(0);
  const [paymentMethod, setPaymentMethod] = useState('');
  const [cardNumber, setCardNumber] = useState('');
  const [expiryDate, setExpiryDate] = useState('');
  const [cvv, setCvv] = useState('');

  const restaurants = [
    { name: 'Pizza Hut', id: 'pizza-hut' },
    { name: 'KFC', id: 'kfc' },
    { name: 'McDonalds', id: 'mcdonalds' },
    { name: 'Subway', id: 'subway' },
    { name: 'Taco Bell', id: 'taco-bell' },
  ];

  const foods = [
    { name: 'Margherita Pizza', id: 'margherita-pizza', price: 12.99 },
    { name: 'Pepperoni Pizza', id: 'pepperoni-pizza', price: 14.99 },
    { name: 'Chicken Burger', id: 'chicken-burger', price: 9.99 },
    { name: 'Beef Burger', id: 'beef-burger', price: 10.99 },
    { name: 'French Fries', id: 'fries', price: 4.99 },
    { name: 'Chicken Wings', id: 'chicken-wings', price: 8.99 },
    { name: 'Caesar Salad', id: 'caesar-salad', price: 7.99 },
    { name: 'Veggie Wrap', id: 'veggie-wrap', price: 8.99 },
    { name: 'Taco', id: 'taco', price: 3.99 },
    { name: 'Burrito', id: 'burrito', price: 9.99 },
  ];

  const handleOrder = () => {
    const food = foods.find((food) => food.id === selectedFood);
    if (!food) return;

    setOrder((prevOrder) => ({
      ...prevOrder,
      [selectedFood]: {
        quantity: prevOrder[selectedFood] 
          ? prevOrder[selectedFood].quantity + quantity 
          : quantity,
        price: food.price,
        name: food.name,
      },
    }));
  };

  const totalPrice = Object.values(order).reduce((total, item) => {
    return total + item.price * item.quantity;
  }, 0);

  useEffect(() => {
    setAmount(totalPrice);
  }, [totalPrice]);

  const handlePayment = () => {
    // Handle payment logic here
    console.log('Payment processed:', { amount, paymentMethod, cardNumber, expiryDate, cvv });
    // Reset order and show confirmation
    setOrder({});
    setShowPayment(false);
    alert('Payment successful! Your order is on its way.');
  };

  const PaymentPage = () => (
    <Card className="bg-white shadow-xl rounded-lg overflow-hidden">
      <CardHeader className="bg-gradient-to-r from-purple-500 to-indigo-500 text-white">
        <CardTitle className="text-2xl">Payment Details</CardTitle>
      </CardHeader>
      <CardContent className="p-6 space-y-4">
        <p className="text-lg font-semibold">Amount: ${amount.toFixed(2)}</p>
        <div>
          <Label htmlFor="payment-method" className="font-semibold mb-2 block">Payment Method</Label>
          <Select onValueChange={setPaymentMethod}>
            <SelectTrigger id="payment-method" className="w-full">
              <SelectValue placeholder="Select Payment Method" />
            </SelectTrigger>
            <SelectContent>
              <SelectItem value="credit-card">Credit Card</SelectItem>
              <SelectItem value="debit-card">Debit Card</SelectItem>
              <SelectItem value="paypal">PayPal</SelectItem>
            </SelectContent>
          </Select>
        </div>
        {(paymentMethod === 'credit-card' || paymentMethod === 'debit-card') && (
          <motion.div
            initial={{ opacity: 0, y: -20 }}
            animate={{ opacity: 1, y: 0 }}
            transition={{ duration: 0.3 }}
            className="space-y-4"
          >
            <div>
              <Label htmlFor="cardNumber" className="font-semibold mb-2 block">Card Number</Label>
              <Input
                type="text"
                id="cardNumber"
                value={cardNumber}
                onChange={(e) => setCardNumber(e.target.value)}
                placeholder="1234 5678 9012 3456"
              />
            </div>
            <div className="flex space-x-4">
              <div className="flex-1">
                <Label htmlFor="expiryDate" className="font-semibold mb-2 block">Expiry Date</Label>
                <Input
                  type="text"
                  id="expiryDate"
                  value={expiryDate}
                  onChange={(e) => setExpiryDate(e.target.value)}
                  placeholder="MM/YY"
                />
              </div>
              <div className="flex-1">
                <Label htmlFor="cvv" className="font-semibold mb-2 block">CVV</Label>
                <Input
                  type="text"
                  id="cvv"
                  value={cvv}
                  onChange={(e) => setCvv(e.target.value)}
                  placeholder="123"
                />
              </div>
            </div>
          </motion.div>
        )}
      </CardContent>
      <CardFooter className="bg-gray-50 p-4">
        <Button
          className="w-full bg-gradient-to-r from-green-500 to-teal-500 text-white hover:from-green-600 hover:to-teal-600 transition-all duration-200"
          onClick={handlePayment}
        >
          Make Payment
        </Button>
      </CardFooter>
    </Card>
  );

  return (
    <div className={`min-h-screen ${darkMode ? 'bg-gray-900 text-gray-200' : 'bg-gradient-to-r from-blue-100 via-purple-100 to-pink-100 text-gray-900'}`}>
      <div className="container mx-auto px-4 py-8">
        <div className="flex justify-between items-center mb-8">
          <h1 className="text-4xl font-bold tracking-wide">FoodieDelights</h1>
          <Button
            variant="outline"
            onClick={() => setDarkMode(!darkMode)}
            className="transition-colors duration-200"
          >
            {darkMode ? '🌞 Light Mode' : '🌙 Dark Mode'}
          </Button>
        </div>

        {!showPayment ? (
          <div className="grid grid-cols-1 md:grid-cols-2 gap-8">
            <Card className="bg-white shadow-xl rounded-lg overflow-hidden">
              <CardHeader className="bg-gradient-to-r from-purple-500 to-indigo-500 text-white">
                <CardTitle className="text-2xl">Place Your Order</CardTitle>
              </CardHeader>
              <CardContent className="p-6">
                <div className="space-y-4">
                  <div>
                    <Label htmlFor="restaurant" className="font-semibold mb-2 block">Select Restaurant</Label>
                    <Select onValueChange={setSelectedRestaurant}>
                      <SelectTrigger id="restaurant" className="w-full">
                        <SelectValue placeholder="Choose a restaurant" />
                      </SelectTrigger>
                      <SelectContent>
                        {restaurants.map((restaurant) => (
                          <SelectItem key={restaurant.id} value={restaurant.id}>
                            {restaurant.name}
                          </SelectItem>
                        ))}
                      </SelectContent>
                    </Select>
                  </div>

                  <div>
                    <Label htmlFor="food" className="font-semibold mb-2 block">Select Food</Label>
                    <Select onValueChange={setSelectedFood}>
                      <SelectTrigger id="food" className="w-full">
                        <SelectValue placeholder="Choose your meal" />
                      </SelectTrigger>
                      <SelectContent>
                        {foods.map((food) => (
                          <SelectItem key={food.id} value={food.id}>
                            {food.name} - ${food.price.toFixed(2)}
                          </SelectItem>
                        ))}
                      </SelectContent>
                    </Select>
                  </div>

                  <div>
                    <Label htmlFor="quantity" className="font-semibold mb-2 block">Quantity</Label>
                    <Input
                      type="number"
                      id="quantity"
                      value={quantity}
                      onChange={(e) => setQuantity(Math.max(1, parseInt(e.target.value) || 1))}
                      className="w-full"
                      min="1"
                    />
                  </div>

                  <Button
                    className="w-full bg-gradient-to-r from-purple-500 to-indigo-500 text-white"
                    onClick={handleOrder}
                  >
                    Add to Order
                  </Button>
                </div>
              </CardContent>
            </Card>

            <Card className="bg-white shadow-xl rounded-lg overflow-hidden">
              <CardHeader className="bg-gradient-to-r from-pink-500 to-orange-500 text-white">
                <CardTitle className="text-2xl">Order Summary</CardTitle>
              </CardHeader>
              <CardContent className="p-6">
                {Object.keys(order).length === 0 ? (
                  <p className="text-center text-gray-500">Your order is empty. Add some delicious items!</p>
                ) : (
                  <motion.div className="space-y-4">
                    {Object.entries(order).map(([foodId, item]) => (
                      <motion.div
                        key={foodId}
                        className="flex justify-between items-center border-b border-gray-200 py-2"
                        initial={{ opacity: 0, y: -20 }}
                        animate={{ opacity: 1, y: 0 }}
                        transition={{ duration: 0.3 }}
                      >
                        <div>
                          <p className="font-semibold">{item.name}</p>
                          <p className="text-sm text-gray-600">Quantity: {item.quantity}</p>
                        </div>
                        <p className="font-semibold">${(item.price * item.quantity).toFixed(2)}</p>
                      </motion.div>
                    ))}
                  </motion.div>
                )}
              </CardContent>
              <CardFooter className="bg-gray-50 p-4">
                <div className="w-full flex justify-between items-center">
                  <p className="font-bold text-lg">Total:</p>
                  <p className="font-bold text-lg">${totalPrice.toFixed(2)}</p>
                </div>
              </CardFooter>
              <div className="p-4">
                <Button
                  className="w-full bg-gradient-to-r from-green-500 to-teal-500 text-white hover:from-green-600 hover:to-teal-600 transition-all duration-200"
                  onClick={() => setShowPayment(true)}
                  disabled={Object.keys(order).length === 0}
                >
                  Proceed to Payment
                </Button>
              </div>
            </Card>
          </div>
        ) : (
          <PaymentPage />
        )}
      </div>

      <footer className="text-center p-4 mt-8 text-gray-500">
        © 2024 FoodieDelights. All rights reserved.
      </footer>
    </div>
  );
};

export default App;