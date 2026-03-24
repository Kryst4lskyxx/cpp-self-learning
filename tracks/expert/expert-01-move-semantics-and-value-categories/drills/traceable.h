#pragma once

#include <string>
#include <utility>

class Traceable {
public:
    explicit Traceable(std::string value)
        : value_(std::move(value)) {}

    Traceable(const Traceable& other)
        : value_(other.value_), copy_count_(1) {}

    Traceable(Traceable&& other) noexcept
        : value_(std::move(other.value_)), move_count_(1) {}

    Traceable& operator=(const Traceable& other) {
        if (this != &other) {
            value_ = other.value_;
            ++copy_count_;
        }
        return *this;
    }

    Traceable& operator=(Traceable&& other) noexcept {
        if (this != &other) {
            value_ = std::move(other.value_);
            ++move_count_;
        }
        return *this;
    }

    [[nodiscard]] const std::string& value() const noexcept {
        return value_;
    }

    [[nodiscard]] int copy_count() const noexcept {
        return copy_count_;
    }

    [[nodiscard]] int move_count() const noexcept {
        return move_count_;
    }

private:
    std::string value_;
    int copy_count_ = 0;
    int move_count_ = 0;
};
