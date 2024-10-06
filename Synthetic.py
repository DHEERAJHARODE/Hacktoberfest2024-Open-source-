import numpy as np
import matplotlib.pyplot as plt

# 1. Generate a synthetic dataset
np.random.seed(42)  # For reproducibility

# Generate 10 uniform x values in range [0, 1]
x = np.random.uniform(0, 1, 10)

# Compute the corresponding y values: y = sin(2*pi*x) + Gaussian noise
noise = np.random.normal(0, 0.3, x.shape)
y = np.sin(2 * np.pi * x) + noise

# 2. Split the dataset into training (80%) and test sets (20%)
def train_test_split_manual(x, y, test_size=0.2):
    n = len(x)
    test_n = int(n * test_size)
    indices = np.random.permutation(n)
    test_indices = indices[:test_n]
    train_indices = indices[test_n:]
    x_train, x_test = x[train_indices], x[test_indices]
    y_train, y_test = y[train_indices], y[test_indices]
    return x_train, x_test, y_train, y_test

x_train, x_test, y_train, y_test = train_test_split_manual(x, y)

# 3. Curve fitting using gradient descent (simple linear regression)
class SimpleLinearRegression:
    def __init__(self, learning_rate=0.05, iterations=1000):
        self.learning_rate = learning_rate
        self.iterations = iterations
        self.m = 0  # slope
        self.b = 0  # intercept

    def fit(self, x, y):
        n = len(x)
        for _ in range(self.iterations):
            y_pred = self.m * x + self.b
            # Calculate gradients
            dm = (-2/n) * np.sum(x * (y - y_pred))
            db = (-2/n) * np.sum(y - y_pred)
            # Update parameters
            self.m -= self.learning_rate * dm
            self.b -= self.learning_rate * db

    def predict(self, x):
        return self.m * x + self.b

# Instantiate and fit the model to the training data
model = SimpleLinearRegression(learning_rate=0.05, iterations=1000)
model.fit(x_train, y_train)

# Predictions on the test set
y_pred = model.predict(x_test)

# Plotting the results
plt.scatter(x, y, color='blue', label='Data with Noise')
plt.plot(x_train, model.predict(x_train), color='green', label='Fitted Curve (Train)')
plt.scatter(x_test, y_test, color='red', label='Test Data')
plt.plot(x_test, y_pred, color='violet', linestyle='--', label='Predicted (Test)')
plt.legend()
plt.xlabel('x')
plt.ylabel('y')
plt.title('Curve Fitting with Gradient Descent')
plt.show()

# Print the slope and intercept
print(f"Model parameters: m (slope) = {model.m}, b (intercept) = {model.b}")
