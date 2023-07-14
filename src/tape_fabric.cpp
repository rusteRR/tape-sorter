#include "tape_fabric.h"
#include <random>
#include "tape_file.h"

namespace {
std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<int> dist(1, INT32_MAX);
}  // namespace

std::shared_ptr<tape_sorter::tape> tape_sorter::tape_fabric::get_tape() {
    return std::make_shared<tape_file>(get_filename());
}

std::string tape_sorter::tape_fabric::get_filename() {
    std::string filename = tmp_dir + "/" + std::to_string(dist(rng));
    tmp_filenames.push_back(filename);
    return filename;
}

tape_sorter::tape_fabric::~tape_fabric() {
    for (std::string &file_to_delete : tmp_filenames) {
        std::remove(file_to_delete.c_str());
    }
}
