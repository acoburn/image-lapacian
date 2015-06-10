#include <string>
#include <vector>
#include <boost/gil/algorithm.hpp>
#include <boost/gil/extension/io/jpeg_dynamic_io.hpp>
#include "boost/gil/extension/opencv/edge_detection.hpp"

namespace laplacian {

    template <typename Out>
    struct invert {
        template <typename T> Out operator()(const T& in) const {
            return Out(~in);
        }
    };

    //template <typename Out>
    //struct strengthener {
        //template <typename T> Out operator()(const T& in, const int threshold) const {
            //if (in > threshold) {
                //return 1;
            //} else {
                //return 0;
            //}
        //}
    //};

    //template <typename SrcView, typename DstView, typename F>
    //F transform(const SrcView& src const DstView& dst, F fun) {
        //typedef typename boost::gil::channel_type<DstView>::type dst_channel_t;
        //for (std::ptrdiff_t y=0; y<src.height(); ++y) {
            //typename SrcView::x_iterator srcIt=src.row_begin(y);
            //typename DstView::x_iterator dstIt=dst.row_begin(y);
            //for (std::ptrdiff_t x=0; x<src.width(); ++x) {
                //dstIt[x]=fun(srcIt[x]);
            //}
        //return fun;
    //}

    template <typename SrcView, typename DstView>
    void transform(const SrcView& src, DstView& dst) {
        typedef typename boost::gil::channel_type<DstView>::type dst_channel_t;
        for (int y=0; y < src.height(); ++y) {
            typename SrcView::x_iterator src_it = src.row_begin(y);
            typename DstView::x_iterator dst_it = dst.row_begin(y);
            for (int x=0; x < src.width(); ++x) {
                boost::gil::static_transform(src_it[x], dst_it[x], invert<dst_channel_t>());
            }
        }
    }

    class Edges {
        boost::gil::rgb8_image_t m_src;
        public:
            Edges(const std::string& input) {
                boost::gil::jpeg_read_image(input, m_src);
            }

            void canny(const std::string& output,
                       double threshold1,
                       double threshold2) {

                boost::gil::rgb8_image_t dst(m_src.dimensions());
                boost::gil::rgb8_image_t inverted(m_src.dimensions());

                boost::gil::opencv::canny(
                        boost::gil::view(m_src),
                        boost::gil::view(dst),
                        threshold1,
                        threshold2,
                        boost::gil::opencv::aperture5());

                laplacian::transform(
                        boost::gil::view(dst),
                        boost::gil::view(inverted));

                boost::gil::jpeg_write_view(output,
                        boost::gil::view(dst));
            }

            void laplace(const std::string& output) {

                boost::gil::rgb8_image_t dst(m_src.dimensions());
                boost::gil::rgb8_image_t inverted(m_src.dimensions());

                boost::gil::opencv::laplace(
                        boost::gil::view(m_src),
                        boost::gil::view(dst),
                        boost::gil::opencv::aperture5());

                laplacian::transform(
                        boost::gil::view(dst),
                        boost::gil::view(inverted));
                        //laplacian::invert<boost::gil::rgb8_pixel_t>());

                boost::gil::jpeg_write_view(output,
                        boost::gil::view(inverted));
            }

            void sobel(const std::string& output) {

                boost::gil::rgb8_image_t dst(m_src.dimensions());
                boost::gil::rgb8_image_t inverted(m_src.dimensions());

                boost::gil::opencv::sobel(
                        boost::gil::view(m_src),
                        boost::gil::view(dst),
                        boost::gil::opencv::aperture5());

                laplacian::transform(
                        boost::gil::view(dst),
                        boost::gil::view(inverted));

                boost::gil::jpeg_write_view(output,
                        boost::gil::view(inverted));
            }
    }; // Edges
} // laplacian


