#ifndef __LAPLACIAN_VERSION_HPP__
#define __LAPLACIAN_VERSION_HPP__

#include <iostream>

#define LAPLACIAN_VERSION_STRING "1.0.0"
#define LAPLACIAN_VERSION_NUMBER 10000 // format Mmmrr (M = Major, m = minor, r = revision)
#define LAPLACIAN_PACKAGE_NAME "Laplacian Image Processing"

#define LAPLACIAN_COPY_YEAR "2015"
#define LAPLACIAN_COPY_HOLDERS "Amherst College"

namespace laplacian
{
    template <class O>
    inline void
    print_version_info(O &o) {
        o << "Version: " << LAPLACIAN_PACKAGE_NAME << " v" << LAPLACIAN_VERSION_STRING << std::endl << std::endl;

        o << "Copyright: (c) " << LAPLACIAN_COPY_YEAR << " " << LAPLACIAN_COPY_HOLDERS << std::endl << std::endl;
    }
} // namespace laplacian
#endif
