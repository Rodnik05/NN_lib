#include <cmath>

constexpr double sigmoid(double x) {
    return 1 / (1 + std::exp(-x));
}