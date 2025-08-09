/*
 * PERCEPTRON
 * (AND Logic Gate Learning)
 * 
 * Author: Vincenzo Argese
 * Web: https://cr1s1um.github.io/
 * Date: 2025-08-09
 * Version: v1.0
 * Idea: Youtuber @Enkk video “come funziona: le reti neurali (pt.1)” https://www.youtube.com/watch?v=2UdQQA65jcM
 * 
 * Description:
 * This program implements a simple perceptron (single artificial neuron) that learns
 * to simulate an AND logic gate through supervised learning.
 * 
 * The perceptron receives two binary inputs (0 or 1) and learns to output:
 * - 1 only when both inputs are 1 (like an AND gate)
 * - 0 in all other cases
 * 
 * Training process:
 * 1. Initialize weights and bias with small random values
 * 2. For each training example, calculate prediction
 * 3. Compare prediction with expected output
 * 4. If wrong, adjust weights using perceptron learning rule
 * 5. Repeat until all predictions are correct or max epochs reached
 * 
 * This demonstrates fundamental neural network concepts: weights, bias, 
 * activation functions, training epochs, and supervised learning.
 */

#include <stdio.h>

#define EPOCHS 100  // Define constant: maximum number of training epochs

/* Forward declaration of activation function */
int activation_function(float sum);

int main(void)
{
    /* Training Dataset */
    int
        x[4][2]={  // Input matrix: 4 examples with 2 features each
            {0,0},  // First example: x1=0, x2=0 -> expected output: 0
            {1,0},  // Second example: x1=1, x2=0 -> expected output: 0
            {0,1},  // Third example: x1=0, x2=1 -> expected output: 0
            {1,1}   // Fourth example: x1=1, x2=1 -> expected output: 1
        },

        y[4]={0,0,0,1};  // Expected outputs: represents AND logic function

    /* Weights and Bias initialization */
    float
        w1 = 0.1,  // Weight for first input, initialized to 0.1
        w2 = 0.1,  // Weight for second input, initialized to 0.1
        b = 0.1;   // Bias term, initialized to 0.1

    // Learning rate parameter
    float learning_rate = 0.1;  // Controls how much weights are adjusted during learning

    /* Training Phase */
    for (int epoch=0; epoch < EPOCHS; epoch++){  // Main training loop: up to 100 epochs
        int errors = 0;  // Counter for errors in current epoch

        // Process all training examples
        for(int i=0; i<4; i++){  // Iterate through all 4 examples in dataset

            // DEBUG - Print current training state
            printf("TRAINING EPOCH: %d\n", epoch);  // Fixed typo: epoch instead of ephoc
            printf("Current errors: %d\n", errors);  // Print current error count
            printf("Input X1: %d - X2: %d\n", x[i][0], x[i][1]);  // Print current inputs
            printf("Expected output Y: %d\n", y[i]);  // Print expected output
            printf("w1: %.1f - w2: %.1f - Bias: %.1f\n", w1, w2, b);  // Print current weights and bias
            printf("Learning Rate: %.1f\n", learning_rate);  // Print learning rate

            // Forward pass: calculate weighted sum
            float weighted_sum = (x[i][0]*w1 + x[i][1]*w2) + b;  // Linear combination: x1*w1 + x2*w2 + bias
            int predicted_output = activation_function(weighted_sum);   // Apply activation function

            // DEBUG - Print forward pass results
            printf("Weighted sum: %.1f\n", weighted_sum);  // Print the weighted sum
            printf("Predicted output: %d\n", predicted_output);  // Print network's prediction

            // Calculate prediction error
            int error = y[i] - predicted_output;  // Error = expected - predicted

            // DEBUG - Print error information
            printf("Prediction error: %d\n", error);  // Print the error
            printf("---------------------------------------------\n");  // Separator line

            // Update weights if there's an error (perceptron learning rule)
            if (error != 0){  // Only update if prediction is wrong
                // Apply perceptron learning rule
                w1 += learning_rate * error * x[i][0];  // Update w1: w1 = w1 + η * error * x1
                w2 += learning_rate * error * x[i][1];  // Update w2: w2 = w2 + η * error * x2
                b += learning_rate * error;             // Update bias: b = b + η * error
                errors++;  // Increment error counter
            }
        }

        // Check convergence: stop if no errors occurred
        if(errors == 0){  // Perfect classification achieved
            printf("TRAINING COMPLETED - epoch: %d\n", epoch);  // Print completion message
            break;  // Exit training loop early
        }
    }

    // Print final results
    printf("\n\n");  // Print empty lines for readability
    printf("=== FINAL TRAINED PARAMETERS ===\n");  // Print results header
    printf("Final w1: %.1f - w2: %.1f - Bias: %.1f\n", w1, w2, b);  // Print final weights and bias

    // Test the trained perceptron
    printf("\n=== TESTING TRAINED PERCEPTRON ===\n");
    for(int i=0; i<4; i++){
        float test_sum = (x[i][0]*w1 + x[i][1]*w2) + b;
        int test_output = activation_function(test_sum);
        printf("Input (%d,%d) -> Output: %d (Expected: %d)\n", 
               x[i][0], x[i][1], test_output, y[i]);
    }

    return 0;
}

/* 
 * Activation Function
 * 
 * Purpose: Converts continuous weighted sum to binary output
 * Parameter: float sum - the weighted sum from perceptron
 * Returns: 1 if sum > 0, otherwise returns 0
 * 
 * This implements a threshold activation function commonly used in perceptrons
 */
int activation_function(float sum){
    return (sum > 0) ? 1 : 0;  // Ternary operator: if sum > 0 return 1, else return 0
}
