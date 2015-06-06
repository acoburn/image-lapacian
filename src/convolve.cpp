#include <iostream>
#include <string>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
#include <laplacian/version.hpp>
#include <laplacian/convolve.hpp>
#include <laplacian/kernel/gaussian.hpp>
#include <laplacian/kernel/laplace.hpp>
#include <laplacian/laplacian.hpp>

#define usage() \
    std::cerr << "Usage: " << argv[0] << " [options] input output" << std::endl << std::endl; \
    std::cerr << "Options: " << std::endl; \
    std::cerr << opts << std::endl; \
    return 0; \


namespace po = boost::program_options;

template<typename T>
void convolve(const std::string& input, const std::string& output) {
    laplacian::GaussianConvolve<T> smoother;
    smoother.convolve(input, output);
}

int main(int argc, char* argv[]) {

    po::variables_map vm;

    po::options_description opts;
    opts.add_options()
        ("help", "produce this help message")
        ("version", "print version information")
        ("input",  po::value<std::string>(), "input file")
        ("output", po::value<std::string>(), "output file")
        ("l1", "laplacian scale=1")
        ("l2", "laplacian scale=2")
        ("l3", "laplacian scale=3")
        ("l4", "laplacian scale=4")
        ("g1", "gaussian sigma=1")
        ("g2", "gaussian sigma=2")
        ("g3", "gaussian sigma=3")
        ("g4", "gaussian sigma=4")
        ;

    po::positional_options_description positional_opts;
    positional_opts.add("input", 1);
    positional_opts.add("output",  2);
    po::store(po::command_line_parser(argc, argv).options(opts).positional(positional_opts).run(), vm);

    try {
        po::notify(vm);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        usage();
    }


    if (vm.count("help")){
        usage();
    }

    if (vm.count("version")) {
        std::cerr << std::endl;
        laplacian::print_version_info(std::cerr);
        std::cerr << std::endl;
        return 0;
    }

    if (vm.count("input")) {

        const std::string input(vm["input"].as<std::string>());
        std::string output;
        if (vm.count("output")) {
            output = vm["output"].as<std::string>();
        } else {
            output = "output_" + vm["input"].as<std::string>();
            std::cerr << "Using " << output << " as the output file." << std::endl;
        }

        if (vm.count("l1")) {
            std::cerr << "Using laplacian (scale=1) convolution" << std::endl;
            convolve<laplacian::kernel::laplace::Scale1>(input, output);
        } else if (vm.count("l2")) { 
            std::cerr << "Using laplacian (scale=2) convolution" << std::endl;
            convolve<laplacian::kernel::laplace::Scale2>(input, output);
        } else if (vm.count("l3")) {
            std::cerr << "Using laplacian (scale=3) convolution" << std::endl;
            convolve<laplacian::kernel::laplace::Scale3>(input, output);
        } else if (vm.count("l4")) {
            std::cerr << "Using laplacian (scale=4) convolution" << std::endl;
            convolve<laplacian::kernel::laplace::Scale4>(input, output);
        } else if (vm.count("g1")) {
            std::cerr << "Using gaussian (sigma=1) convolution" << std::endl;
            convolve<laplacian::kernel::gaussian::Sigma1>(input, output);
        } else if (vm.count("g2")) {
            std::cerr << "Using gaussian (sigma=2) convolution" << std::endl;
            convolve<laplacian::kernel::gaussian::Sigma2>(input, output);
        } else if (vm.count("g3")) {
            std::cerr << "Using gaussian (sigma=3) convolution" << std::endl;
            convolve<laplacian::kernel::gaussian::Sigma3>(input, output);
        } else if (vm.count("g4")) {
            std::cerr << "Using gaussian (sigma=4) convolution" << std::endl;
            convolve<laplacian::kernel::gaussian::Sigma4>(input, output);
        }
    } else {
        std::cerr << "Missing input file" << std::endl;
        usage();
    }
}


