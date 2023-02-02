#include <gtest/gtest.h>
#include <sstream>

#include "../NeuronsAndLayers/Neuron.cpp"


TEST(NeuronTest, InputInitialization) {
    constexpr std::size_t res = Neuron(5).Indegree();
    ASSERT_EQ(res, 100);
}

TEST(NeuronTest, ArrayInit) {
    double arr[] = {1, 2, 3, 4, 5};
    ASSERT_EQ(Neuron(5, arr).InputWeight(3), 4);
}