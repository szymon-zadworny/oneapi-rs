#include "oneapi-rs-sys/include/platform.hpp"

namespace sycl_shims {
std::unique_ptr<std::vector<Platform>> Platform::get_platforms() {
  std::vector<Platform> platforms;
  for (auto &&platform : sycl::platform::get_platforms())
    platforms.push_back(platform);

  return std::make_unique<std::vector<Platform>>(platforms);
}

rust::String Platform::get_version() const {
  return this->inner.get_info<sycl::info::platform::version>();
}

rust::String Platform::get_name() const {
  return this->inner.get_info<sycl::info::platform::name>();
}

rust::String Platform::get_vendor() const {
  return this->inner.get_info<sycl::info::platform::vendor>();
}
} // namespace sycl_shims
