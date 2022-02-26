#include <iostream>
#include <iomanip>

class Date {
public:
    Date(int year = 0, unsigned int month = 0u, unsigned int day = 0u) :
        year(year), month(month), day(day) {}

    bool operator<(Date other) const {
        return std::tuple(year, month, day) <
            std::tuple(other.year, other.month, other.day);
    }

    bool operator==(Date other) const {
        return std::tuple(year, month, day) ==
            std::tuple(other.year, other.month, other.day);
    }

    bool operator>(Date other) const {
        return !(*this < other) && !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream&, Date);

    friend std::istream& operator>>(std::istream&, Date&);

private:
    int year;
    unsigned month, day;
};

std::ostream& operator<<(std::ostream& os, Date date) {
    return os << std::setfill('0')
        << std::setw(2) << date.day << '.'
        << std::setw(2) << date.month << '.' << date.year;
}

std::istream& operator>>(std::istream& is, Date& date) {
    char trash;
    return is >> date.day >> trash >> date.month >> trash >> date.year;
}

int main() {
    Date date, other_date;
    std::cin >> date >> other_date;
    std::cout << date << ' ' << other_date << std::endl;
    std::cout << std::boolalpha << (date < other_date);

    return 0;
}
