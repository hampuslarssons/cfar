// Detection data struct. Defines output data of CFAR algorithms.

#pragma once
#include <cstddef>

namespace cfar {
    
    struct Detection {
        std::size_t index{}; // cell under test index
        double threshold{}; // Linear power threshold
        double noise_estimate{}; // linear power noise estimate

    };
} // namespace cfar