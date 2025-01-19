# Single Perceptron with ReLU Activation and Gradient Descent

This project implements a single perceptron from scratch in C++, utilizing ReLU activation function and gradient descent for training. The perceptron is trained on an income dataset to predict outcomes based on input features.

## Overview
 
The project implements a basic single perceptron model with the following features:

- **Perceptron Class**: Implemented in C++, this class includes methods for initialization, prediction using ReLU activation, and training using gradient descent.
  
- **ReLU Activation**: Rectified Linear Unit (ReLU) activation function introduces non-linearity into the perceptron's output.

- **Gradient Descent**: The perceptron is trained using gradient descent, optimizing weights and biases to minimize the error between predicted and actual outcomes.

- **Dataset**: The perceptron is trained on an income dataset (`data.csv`), where the goal is to predict income levels based on input features.

## Implementation Details

The project includes the following key components:

- **`readCSV` Function**: Reads and parses the CSV file containing the dataset.
  
- **Perceptron Class**:
  - Initializes with random weights and biases.
  - Implements ReLU activation function for prediction.
  - Uses gradient descent to train on the dataset.

- **Main Function**:
  - Reads the dataset from `data.csv`.
  - Normalizes the data (if needed).
  - Initializes and trains the perceptron.
  - Prints RMS error during training epochs.


