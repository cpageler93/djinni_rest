// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#pragma once

#include <cstdint>
#include <string>
#include <utility>

namespace djinni_rest_gen {

struct PostModel final {
    int64_t id;
    std::string title;
    std::string body;

    PostModel(int64_t id_,
              std::string title_,
              std::string body_)
    : id(std::move(id_))
    , title(std::move(title_))
    , body(std::move(body_))
    {}
};

}  // namespace djinni_rest_gen
