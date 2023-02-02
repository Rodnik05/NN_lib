#include <cstdio>
#include <vector>

#include "Neuron.h"

using NeuronPtr = Neuron*;

class Layer {
    const std::size_t neurons_count_;
    NeuronPtr* neurons_;
public:
    Layer(double (*activation_function_) (double)
          , std::size_t NeuronsCount
          , const std::size_t Indegree) : neurons_count_(NeuronsCount) {
        neurons_ = new NeuronPtr[neurons_count_];
        for (std::size_t i = 0; i < neurons_count_; i++) {
            neurons_[i] = new Neuron(Indegree, activation_function_);
        }
    }


    ~Layer() {
        for (std::size_t i = 0; i < neurons_count_; i++) {
            delete[] neurons_[i];
        }
        delete[] neurons_;
    }


};