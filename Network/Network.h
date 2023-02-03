#include "../NeuronsAndLayers/Neuron.h"
#include "../NeuronsAndLayers/Layer.h"

class Network {
    const std::size_t layersCount_;
    Layer* layers;
public:
    Network(std::size_t LayersCount) : layersCount_(LayersCount) {}
};
