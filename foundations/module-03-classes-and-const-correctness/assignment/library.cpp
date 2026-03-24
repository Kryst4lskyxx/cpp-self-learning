#include "library.h"

#include <algorithm>
#include <utility>

void Library::add_book(Book book) {
    books_.push_back(std::move(book));
}

std::size_t Library::size() const noexcept {
    return books_.size();
}

const std::vector<Book>& Library::books() const noexcept {
    return books_;
}

std::optional<std::reference_wrapper<const Book>> Library::find_by_title(std::string_view title) const {
    const auto it = std::find_if(books_.cbegin(), books_.cend(), [title](const Book& book) {
        return book.title == title;
    });

    if (it == books_.cend()) {
        return std::nullopt;
    }

    return std::cref(*it);
}
