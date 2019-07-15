
#include <grpcpp/impl/codegen/allocator.h>

#include <string>

namespace grpc {
using rtstring =
    std::basic_string<char, std::char_traits<char>, allocator<char>>;
}  // namespace grpc
