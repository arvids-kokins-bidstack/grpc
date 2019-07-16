
#pragma once
#include <grpc/support/alloc.h>
#include <new>

namespace grpc {

template <class T>
struct allocator {
  typedef T value_type;
  allocator() = default;
  template <class U>
  constexpr allocator(const allocator<U>&) noexcept {}
  T* allocate(std::size_t n) {
    if (n > std::size_t(-1) / sizeof(T)) throw std::bad_alloc();
    if (auto p = static_cast<T*>(gpr_malloc(n * sizeof(T)))) return p;
    throw std::bad_alloc();
  }
  void deallocate(T* p, std::size_t) noexcept { gpr_free(p); }
};
template <class T, class U>
bool operator==(const allocator<T>&, const allocator<U>&) {
  return true;
}
template <class T, class U>
bool operator!=(const allocator<T>&, const allocator<U>&) {
  return false;
}

}
