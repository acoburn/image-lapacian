namespace laplacian { namespace kernel { namespace gaussian {
    /**
     * These values can be computed in R with the following commands:
     *
     * dnorm(seq( - (N - 1) / 2, (N - 1) / 2, length=N), sd=X)
     *
     */

    // Sigma-1 Gaussian Kernel
    struct Sigma1 {
        static const int size = 9;
        static const int center = 4;
        static const float kernel[size];
    };

    const float Sigma1::kernel[Sigma1::size] = {
        0.0001338302f, 0.0044318484f, 0.0539909665f, 0.2419707245f,
        0.3989422804f,
        0.2419707245f, 0.0539909665f, 0.0044318484f, 0.0001338302f };


    // Sigma-2 Gaussian Kernel
    struct Sigma2 {
        static const int size = 15;
        static const int center = 8;
        static const float kernel[size];
    };

    const float Sigma2::kernel[Sigma2::size] = {
        0.0004363413f, 0.0022159242f, 0.0087641502f, 0.0269954833f,
        0.0647587978f, 0.1209853623f, 0.1760326634f,
        0.1994711402f,
        0.1760326634f, 0.1209853623f, 0.0647587978f,
        0.0269954833f, 0.0087641502f, 0.0022159242f, 0.0004363413f };


    // Sigma-3 Gaussian Kernel
    struct Sigma3 {
        static const int size = 23;
        static const int center = 11;
        static const float kernel[size];
    };

    const float Sigma3::kernel[Sigma3::size] = {
        0.0001600902f, 0.0005140930f, 0.0014772828f, 0.0037986620f, 0.0087406297f,
        0.0179969888f, 0.0331590463f, 0.0546700249f, 0.0806569082f,
        0.1064826685f, 0.1257944092f,
        0.1329807601f,
        0.1257944092f, 0.1064826685f,
        0.0806569082f, 0.0546700249f, 0.0331590463f, 0.0179969888f,
        0.0087406297f, 0.0037986620f, 0.0014772828f, 0.0005140930f, 0.0001600902f };


    // Sigma-4 Gaussian Kernel
    struct Sigma4 {
        static const int size = 29;
        static const int center = 15;
        static const float kernel[size];
    };

    const float Sigma4::kernel[Sigma4::size] = {
        0.0002181707f, 0.0005072620f, 0.0011079621f, 0.0022733906f, 0.0043820751f,
        0.0079349130f, 0.0134977416f, 0.0215693297f, 0.0323793989f,
        0.0456622713f, 0.0604926811f, 0.0752843580f,
        0.0880163317f, 0.0966670292f,
        0.0997355701f,
        0.0966670292f, 0.0880163317f,
        0.0752843580f, 0.0604926811f, 0.0456622713f,
        0.0323793989f, 0.0215693297f, 0.0134977416f, 0.0079349130f,
        0.0043820751f, 0.0022733906f, 0.0011079621f, 0.0005072620f, 0.0002181707f };

} } }

