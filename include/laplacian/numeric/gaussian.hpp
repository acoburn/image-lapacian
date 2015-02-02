namespace laplacian { namespace numeric {

    // Radius-1 Gaussian Kernel
    struct Gaussian1 {
        static const int size = 9;
        static const int center = 4;
        static const float kernel[size];
    };

    const float Gaussian1::kernel[Gaussian1::size] = {
                0.00022923296f, 0.0059770769f, 0.060597949f,  0.24173197f,
                0.38292751f,
                0.24173197f,    0.060597949f,  0.0059770769f, 0.00022923296f };


    // Radius-2 Gaussian Kernel
    struct Gaussian2 {
        static const int size = 15;
        static const int center = 8;
        static const float kernel[size];
    };

    const float Gaussian2::kernel[Gaussian2::size] = {
                0.00048869418f, 0.0024031631f, 0.0092463447f, 0.027839607f,
                0.065602221f,   0.12099898f,   0.17469721f,
                0.19744757f,
                0.17469721f,  0.12099898f,     0.065602221f,
                0.027839607f, 0.0092463447f,   0.0024031631f, 0.00048869418f };


    // Radius-3 Gaussian Kernel
    struct Gaussian3 {
        static const int size = 23;
        static const int center = 11;
        static const float kernel[size];
    };

    const float Gaussian3::kernel[Gaussian3::size] = {
        0.00016944126f, 0.00053842377f, 0.0015324751f,  0.0039068931f,
        0.0089216027f,  0.018248675f,   0.033434924f,   0.054872241f,
        0.080666073f,   0.10622258f,    0.12529446f,
        0.13238440f,
        0.12529446f,    0.10622258f,    0.080666073f,
        0.054872241f,   0.033434924f,   0.018248675f,   0.0089216027f,
        0.0039068931f,  0.0015324751f,  0.00053842377f, 0.00016944126f };


    // Radius-4 Gaussian Kernel
    struct Gaussian4 {
        static const int size = 29;
        static const int center = 15;
        static const float kernel[size];
    };

    const float Gaussian4::kernel[Gaussian4::size] = {
        0.00022466264f, 0.00052009715f, 0.0011314391f,  0.0023129794f,
        0.0044433107f,  0.0080211498f,  0.013606987f,   0.021691186f,
        0.032493830f,   0.045742013f,   0.060509924f,   0.075220309f,
        0.087870099f,   0.096459411f,
        0.099505201f,
        0.096459411f,   0.087870099f,
        0.075220309f,   0.060509924f,   0.045742013f,   0.032493830f,
        0.021691186f,   0.013606987f,   0.0080211498f,  0.0044433107f,
        0.0023129794f,  0.0011314391f,  0.00052009715f, 0.00022466264f };
} }

