#include <iostream>
#include <string>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
#include <laplacian/version.hpp>
#include <laplacian/convolve.hpp>
#include <laplacian/numeric/gaussian.hpp>

#define usage() \
    std::cerr << "Usage: " << argv[0] << " [options] input output" << std::endl << std::endl; \
    std::cerr << "Options: " << std::endl; \
    std::cerr << opts << std::endl; \
    return 0; \


namespace po = boost::program_options;

int main(int argc, char* argv[]) {

    po::variables_map vm;

    po::options_description opts;
    opts.add_options()
        ("help", "produce this help message")
        ("version", "print version information")
        ("input",  po::value<std::string>(), "input file")
        ("output", po::value<std::string>(), "output file")
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

        laplacian::GaussianConvolve<laplacian::numeric::Gaussian1> smoother;

        smoother.convolve(input, output);

    } else {
        std::cerr << "Missing input file" << std::endl;
        usage();
    }
}
