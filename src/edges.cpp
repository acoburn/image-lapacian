#include <iostream>
#include <string>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
#include <laplacian/version.hpp>
#include <laplacian/convolve.hpp>
#include <laplacian/edges.hpp>
#include <laplacian/kernel/gaussian.hpp>
#include <laplacian/kernel/laplace.hpp>
#include <laplacian/laplacian.hpp>

#define usage() \
    std::cerr << "Usage: " << argv[0] << " [options] input output" << std::endl << std::endl; \
    std::cerr << "Options: " << std::endl; \
    std::cerr << opts << std::endl; \


namespace po = boost::program_options;

template<typename T>
int convolve(const std::string& input, const std::string& output) {
    try {
        laplacian::Convolution<T> smoother;
        smoother.convolve(input, output);
        return EXIT_SUCCESS;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}

int main(int argc, char* argv[]) {

    po::variables_map vm;

    po::options_description opts;
    opts.add_options()
        ("help", "produce this help message")
        ("version", "print version information")
        ("laplace,l", "laplacian edge detector")
        ("input,i",  po::value<std::string>(), "input file")
        ("output,o", po::value<std::string>(), "output file")
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
        return EXIT_FAILURE;
    }

    if (vm.count("help")){
        usage();
        return EXIT_SUCCESS;
    }

    if (vm.count("version")) {
        std::cerr << std::endl;
        laplacian::print_version_info(std::cerr);
        std::cerr << std::endl;
        return EXIT_SUCCESS;
    }

    if (vm.count("input") && vm.count("output")) {

        const std::string input(vm["input"].as<std::string>());
        const std::string output(vm["output"].as<std::string>());

        if (vm.count("laplace")) {
            std::cerr << "Using laplace edge detector" << std::endl;

            laplacian::Edges detector;
            detector.edges(input, output);

        } else {
            std::cerr << "Invalid algorithm specified!" << std::endl;
            usage();
            return EXIT_FAILURE;
        }
    } else {
        std::cerr << "Missing parameters" << std::endl;
        usage();
        return EXIT_FAILURE;
    }
}

