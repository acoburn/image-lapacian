#include <string>
#include <vector>
#include <boost/gil/image.hpp>
#include <boost/gil/typedefs.hpp>
#include <boost/gil/extension/io/jpeg_io.hpp>
#include "boost/gil/extension/numeric/kernel.hpp"
#include "boost/gil/extension/numeric/convolve.hpp"

namespace laplacian {

    template<class T>
    class GaussianConvolve {
        
        public:
            GaussianConvolve<T>() {
            }

            void convolve(const std::string& input, const std::string& output) {
                T gaussian;
                boost::gil::rgb8_image_t img;

                boost::gil::jpeg_read_image(input, img);

                // Convolve the rows and the columns of the image with a fixed kernel
                boost::gil::rgb8_image_t convolved(img);

            boost::gil::kernel_1d<float> kernel_1d(gaussian.kernel, gaussian.size, gaussian.center);

            boost::gil::convolve_rows<boost::gil::rgb32f_pixel_t>(boost::gil::const_view(convolved), kernel_1d, boost::gil::view(convolved));
            boost::gil::convolve_cols<boost::gil::rgb32f_pixel_t>(boost::gil::const_view(convolved), kernel_1d, boost::gil::view(convolved));
            boost::gil::jpeg_write_view(output, boost::gil::view(convolved));
        }

    }; // GaussianConvolve

} // laplacian

