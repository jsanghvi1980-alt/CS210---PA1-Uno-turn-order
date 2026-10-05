#pragma once

#include <ostream>
#include <string>
#include <utility>

class Data {
public:
    Data(int numID, std::string name)
    : numID_(numID), name_(std::move(name)) {
    }

    bool operator==(const Data& other) const {
        return numID_ == other.numID_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Data& data) {
        return out << data.numID_ << " " << data.name_;
    }

private:
    int numID_;
    std::string name_;
};