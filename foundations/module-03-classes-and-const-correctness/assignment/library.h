#ifndef FOUNDATIONS_MODULE_03_CLASSES_AND_CONST_CORRECTNESS_ASSIGNMENT_LIBRARY_H_
#define FOUNDATIONS_MODULE_03_CLASSES_AND_CONST_CORRECTNESS_ASSIGNMENT_LIBRARY_H_

#include <cstddef>
#include <functional>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

struct Book {
    std::string title;
    std::string author;
    int year{};
};

class Library {
public:
    void add_book(Book book);

    std::size_t size() const noexcept;
    std::optional<std::reference_wrapper<const Book>> find_by_title(std::string_view title) const;

private:
    std::vector<Book> books_;
};

#endif  // FOUNDATIONS_MODULE_03_CLASSES_AND_CONST_CORRECTNESS_ASSIGNMENT_LIBRARY_H_
