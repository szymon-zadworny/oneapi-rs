//
// Copyright (C) 2026 Intel Corporation
//
// Under the MIT License or the Apache License v2.0.
// See LICENSE-MIT and LICENSE-APACHE for license information.
// SPDX-License-Identifier: MIT OR Apache-2.0
//

#pragma once

#include "rust/cxx.h"
#include "oneapi-rs-sys/include/types.hpp"

#include <sycl/sycl.hpp>

#include <memory>

namespace sycl_shims {
struct DevicePtr;
struct ContextPtr;
} // namespace sycl_shims

namespace sycl_shims::context {
std::unique_ptr<Context> new_context(rust::Vec<DevicePtr>);
std::unique_ptr<SourceKernelBundle> create_kernel_bundle_from_source(Context const &ctxt,
                                                                     rust::Str source);
} // namespace sycl_shims::context
