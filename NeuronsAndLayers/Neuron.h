#pragma once
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>

#include "../Functions/Sigmoid.cpp"

class Neuron {
    const std::size_t indegree_;
    double* input_weights_;
    double (*activation_function_) (double);
public:
    constexpr explicit Neuron(std::size_t Indegree) : indegree_(Indegree)
    , input_weights_(new double[indegree_]())
    , activation_function_([](double x){return x;}) { }


    constexpr explicit Neuron(std::size_t Indegree, double (*ActivationFunction) (double))
            : indegree_(Indegree)
            , input_weights_(new double[indegree_]())
            , activation_function_([](double x){return x;}) { }


    constexpr explicit Neuron(std::size_t Indegree, const double* InputWeights)
        : indegree_(Indegree)
        , input_weights_(new double[indegree_])
        , activation_function_([](double x){return x;}) {
        for (std::size_t i = 0; i < indegree_; i++) {
            input_weights_[i] = InputWeights[i];
        }
    }


    constexpr explicit Neuron(std::size_t Indegree, const double* InputWeights, double (*ActivationFunction) (double))
        : indegree_(Indegree)
        , input_weights_(new double[indegree_]())
        , activation_function_(ActivationFunction) {
        for (std::size_t i = 0; i < indegree_; i++) {
            input_weights_[i] = InputWeights[i];
        }
    }


    constexpr explicit Neuron(const Neuron& other) : indegree_(other.Indegree())
    , input_weights_(new double[indegree_]())
    , activation_function_([](double x){return x;}) {
        for (std::size_t i = 0; i < indegree_; i++) {
            input_weights_[i] = other.InputWeight(i);
        }
    }


    constexpr Neuron& operator=(const Neuron& other) {
        if (this == &other) {
            return *this;
        }
        for (std::size_t i = 0; i < indegree_; i++) {
            input_weights_[i] = other.InputWeight(i);
        }
        return *this;
    }


    constexpr ~Neuron() {
        delete[] input_weights_;
    }


    constexpr std::size_t Indegree() const {
        return indegree_;
    }


    constexpr double InputWeight(std::size_t pos) const {
        if (pos < indegree_)
            return input_weights_[pos];
        else
            throw std::out_of_range("index is not within the range");
    }


    constexpr double Result(const double* values, std::size_t size) const {
        double sum = 0;
        for (std::size_t i = 0; i < indegree_ && i < size; i++) {
            sum += values[i] * input_weights_[i];
        }
        return sigmoid(sum);
    }
};

