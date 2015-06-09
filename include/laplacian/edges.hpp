#include <string>
#include <vector>
#include <boost/gil/extension/io/jpeg_io.hpp>
#include "boost/gil/extension/opencv/edge_detection.hpp"

namespace laplacian {

    boost::gil::rgb8_image_t m_src;
    
    class Edges {
        public:
            Edges(const std::string& input) {
                boost::gil::jpeg_read_image(input, m_src);
            }

            void canny(const std::string& output,
                       double threshold1,
                       double threshold2) {

                boost::gil::rgb8_image_t dst(m_src);
                
                boost::gil::opencv::canny(
                        boost::gil::view(m_src),
                        boost::gil::view(dst),
                        threshold1,
                        threshold2,
                        boost::gil::opencv::aperture3());

                boost::gil::jpeg_write_view(output,
                        boost::gil::view(dst));
            }

            void laplace(const std::string& output) {

                boost::gil::rgb8_image_t dst(m_src);

                boost::gil::opencv::laplace(
                        boost::gil::view(m_src),
                        boost::gil::view(dst),
                        boost::gil::opencv::aperture3());

                boost::gil::jpeg_write_view(output,
                        boost::gil::view(dst));
            }

            void sobel(const std::string& output) {

                boost::gil::rgb8_image_t dst(m_src);

                boost::gil::opencv::sobel(
                        boost::gil::view(m_src),
                        boost::gil::view(dst),
                        boost::gil::opencv::aperture3());

                boost::gil::jpeg_write_view(output,
                        boost::gil::view(dst));
            }
    }; // Edges
} // laplacian


