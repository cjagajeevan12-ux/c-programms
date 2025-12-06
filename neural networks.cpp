#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// ------------------ NEURAL NETWORK SETTINGS ------------------
#define INPUT_NEURONS 2
#define HIDDEN_NEURONS 4
#define OUTPUT_NEURONS 1
#define LEARNING_RATE 0.1
#define EPOCHS 5000

// ------------------ WEIGHTS & BIASES -------------------------
double w1[INPUT_NEURONS][HIDDEN_NEURONS];
double b1[HIDDEN_NEURONS];
double w2[HIDDEN_NEURONS][OUTPUT_NEURONS];
double b2[OUTPUT_NEURONS];

// ------------------ ACTIVATION FUNCTIONS ---------------------
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double dsigmoid(double x) {
    return x * (1.0 - x);
}

// ------------------ FORWARD PASS -----------------------------
void forward(double input[], double hidden[], double output[]) {
    for (int i = 0; i < HIDDEN_NEURONS; i++) {
        hidden[i] = 0;
        for (int j = 0; j < INPUT_NEURONS; j++) {
            hidden[i] += input[j] * w1[j][i];
        }
        hidden[i] += b1[i];
        hidden[i] = sigmoid(hidden[i]);
    }

    for (int i = 0; i < OUTPUT_NEURONS; i++) {
        output[i] = 0;
        for (int j = 0; j < HIDDEN_NEURONS; j++) {
            output[i] += hidden[j] * w2[j][i];
        }
        output[i] += b2[i];
        output[i] = sigmoid(output[i]);
    }
}

// ------------------ TRAINING (BACKPROP) ----------------------
void train(double input[], double target) {
    double hidden[HIDDEN_NEURONS];
    double output[OUTPUT_NEURONS];

    forward(input, hidden, output);

    double output_error = target - output[0];
    double output_delta = output_error * dsigmoid(output[0]);

    double hidden_delta[HIDDEN_NEURONS];
    for (int i = 0; i < HIDDEN_NEURONS; i++) {
        hidden_delta[i] = (output_delta * w2[i][0]) * dsigmoid(hidden[i]);
    }

    for (int i = 0; i < HIDDEN_NEURONS; i++) {
        w2[i][0] += hidden[i] * output_delta * LEARNING_RATE;
    }
    b2[0] += output_delta * LEARNING_RATE;

    for (int i = 0; i < HIDDEN_NEURONS; i++) {
        for (int j = 0; j < INPUT_NEURONS; j++) {
            w1[j][i] += input[j] * hidden_delta[i] * LEARNING_RATE;
        }
        b1[i] += hidden_delta[i] * LEARNING_RATE;
    }
}

// ------------------ RANDOM INIT ------------------------------
void init() {
    srand(time(0));
    for (int i = 0; i < INPUT_NEURONS; i++)
        for (int j = 0; j < HIDDEN_NEURONS; j++)
            w1[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;

    for (int i = 0; i < HIDDEN_NEURONS; i++)
        b1[i] = ((double)rand() / RAND_MAX) * 2 - 1;

    for (int i = 0; i < HIDDEN_NEURONS; i++)
        w2[i][0] = ((double)rand() / RAND_MAX) * 2 - 1;

    for (int i = 0; i < OUTPUT_NEURONS; i++)
        b2[i] = ((double)rand() / RAND_MAX) * 2 - 1;
}

// ------------------ MAIN ------------------------------
int main() {
    init();

    // XOR Training Data
    double data[4][2] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };
    double target[4] = {0, 1, 1, 0};

    printf("Training Neural Network...\n");

    // Train NN
    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        for (int i = 0; i < 4; i++) {
            train(data[i], target[i]);
        }
    }

    printf("Training completed.\n");

    while (1) {
        double x, y;
        printf("\nEnter two inputs (0 or 1): ");
        scanf("%lf %lf", &x, &y);

        double input[2] = {x, y};
        double hidden[HIDDEN_NEURONS];
        double output[OUTPUT_NEURONS];

        forward(input, hidden, output);

        printf("Prediction: %.4f\n", output[0]);
    }

    return 0;
}

