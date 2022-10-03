// Copyright 2022 Cantab Research Ltd.
// Licensed under the MIT license. See LICENSE.txt in the project root for details.
#include "coro/sync_wait.hpp"
#include <coro/coro.hpp>
#include <iostream>

int main() {
  auto gen = []() -> coro::generator<uint64_t> {
    uint64_t i = 0;
    constexpr uint64_t max_limit = 10000;
    while (i < max_limit) {
      co_yield i++;
    }
  };

  auto print = [](auto input) -> coro::task<void> {
    for (auto val : input()) {
        std::cout << val << std::endl;
    }
    co_return;
  };

  coro::sync_wait(print(gen));
}
