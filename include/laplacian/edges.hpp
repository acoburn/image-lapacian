#include <string>
#include <vector>
#include <boost/gil/extension/io/jpeg_io.hpp>
#include "boost/gil/extension/opencv/edge_detection.hpp"

namespace laplacian {

    class Edges {
        public:
            Edges() { }

            void edges(const std::string& input, const std::string& output) {

                boost::gil::rgb8_image_t src;
                boost::gil::rgb8_image_t dst(src);

                boost::gil::jpeg_read_image(input, src);
                boost::gil::opencv::laplace(
                        boost::gil::view(src),
                        boost::gil::view(dst),
                        boost::gil::opencv::aperture3());

                boost::gil::jpeg_write_view(output,
                        boost::gil::view(dst));
            }
    }; // Edges
} // laplacian


