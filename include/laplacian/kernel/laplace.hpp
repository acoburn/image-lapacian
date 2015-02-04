namespace laplacian { namespace kernel { namespace laplace {
    /*
     * These distributions were generated in R with the included `laplace` package
     * by running:
     *     x <- seq(-N+1), N-1, length=N)
     *     dlaplace(x, mean=0, scale=B)
     */

    // Scale-1 Lapl Kernel
    struct Scale1 {
        static const int size = 9;
        static const int center = 4;
        static const float kernel[size];
    };

    const float Scale1::kernel[Scale1::size] = {
        0.0001677313f, 0.0012393761f, 0.0091578194f, 0.0676676416f,
        0.5000000000f,
        0.0676676416f, 0.0091578194f, 0.0012393761f, 0.0001677313f };


    // Scale-2 Laplace Kernel
    struct Scale2 {
        static const int size = 15;
        static const int center = 8;
        static const float kernel[size];
    };

    const float Scale2::kernel[Scale2::size] = {
        0.0002279705f, 0.0006196880f, 0.0016844867f, 0.0045789097f,
        0.0124467671f, 0.0338338208f, 0.0919698603f,
        0.2500000000f,
        0.0919698603f, 0.0338338208f, 0.0124467671f,
        0.0045789097f, 0.0016844867f, 0.0006196880f, 0.0002279705f };

    // Scale-3 Laplace Kernel
    struct Scale3 {
        static const int size = 23;
        static const int center = 11;
        static const float kernel[size];
    };

    const float Scale3::kernel[Scale3::size] = {
        0.0001088987f, 0.0002121056f, 0.0004131254f, 0.0008046583f, 0.0015672604f,
        0.0030526065f, 0.0059456656f, 0.0115805752f, 0.0225558805f,
        0.0439328564f, 0.0855695198f,
        0.1666666667f,
        0.0855695198f, 0.0439328564f,
        0.0225558805f, 0.0115805752f, 0.0059456656f, 0.0030526065f,
        0.0015672604f, 0.0008046583f, 0.0004131254f, 0.0002121056f, 0.0001088987f };

    // Scale-4 Laplace Kernel
    struct Scale4 {
        static const int size = 29;
        static const int center = 15;
        static const float kernel[size];
    };

    const float Scale4::kernel[Scale4::size] = {
        0.0001139852f, 0.0001879299f, 0.0003098440f, 0.0005108464f, 0.0008422434f,
        0.0013886246f, 0.0022894549f, 0.0037746729f, 0.0062233835f,
        0.0102606248f, 0.0169169104f, 0.0278912700f,
        0.0459849301f, 0.0758163325f,
        0.1250000000f,
        0.0758163325f, 0.0459849301f,
        0.0278912700f, 0.0169169104f, 0.0102606248f,
        0.0062233835f, 0.0037746729f, 0.0022894549f, 0.0013886246f,
        0.0008422434f, 0.0005108464f, 0.0003098440f, 0.0001879299f, 0.0001139852f };
} } }

