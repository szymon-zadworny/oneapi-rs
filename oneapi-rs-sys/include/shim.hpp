#pragma once
#include <sycl/sycl.hpp>
#include <string>
#include <vector>
#include <memory>

std::unique_ptr<std::vector<sycl::platform>> get_platforms();
std::unique_ptr<std::string> get_name(sycl::platform const& p);