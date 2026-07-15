//
// Copyright (C) 2026 Intel Corporation
//
// Under the MIT License or the Apache License v2.0.
// See LICENSE-MIT and LICENSE-APACHE for license information.
// SPDX-License-Identifier: MIT OR Apache-2.0
//

#include "oneapi-rs-sys/include/queue.hpp"
#include "oneapi-rs-sys/src/queue-sys.rs.h"

using sycl::property::queue::in_order;

namespace sycl_shims::queue {
std::unique_ptr<Queue> new_queue() {
  return std::make_unique<Queue>(sycl::queue({in_order()}));
}
std::unique_ptr<Queue> new_queue_from_device(Device const & device) {
  return std::make_unique<Queue>(sycl::queue(device, {in_order()}));
}
} // namespace sycl_shims::queue
