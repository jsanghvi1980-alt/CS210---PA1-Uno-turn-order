#pragma once

#include <iostream>
#include "List.h"

template <typename T>
class ArrayList : public List<T> {
public:
    ArrayList() : data_{}, size_(0) {
    }

    void addFront(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }

        for (int i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }

        data_[0] = value;
        ++size_;
    }

    void deleteFront() override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }

        delete data_[0];

        for (int i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }

        --size_;
        data_[size_] = nullptr;
    }

    bool search(T* value) const override {
        for (int i = 0; i < size_; ++i) {
            if (*data_[i] == *value) {
                return true;
            }
        }

        return false;
    }

    void print() const override {
        for (int i = 0; i < size_; ++i) {
            std::cout << *data_[i] << ",";
        }

        std::cout << std::endl;
    }

    void addAnywhere(int position, T* value) override {
        if (position < 0 || position > size_) {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }

        for (int i = size_; i > position; --i) {
            data_[i] = data_[i - 1];
        }

        data_[position] = value;
        ++size_;
    }

    void deleteAnywhere(int position) override {
        if (position < 0 || position >= size_) {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        delete data_[position];

        for (int i = position; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }

        --size_;
        data_[size_] = nullptr;
    }

    void reverse() override {
        int left = 0;
        int right = size_ - 1;

        while (left < right) {
            T* temporary = data_[left];
            data_[left] = data_[right];
            data_[right] = temporary;

            ++left;
            --right;
        }
    }

    void concat(List<T>* other) override {
        auto* otherList = dynamic_cast<ArrayList<T>*>(other);

        if (otherList == nullptr) {
            std::cout << "List types do not match." << std::endl;
            return;
        }

        if (size_ + otherList->size_ > CAPACITY) {
            std::cout << "ArrayList does not have enough capacity."
                      << std::endl;
            return;
        }

        const int otherSize = otherList->size_;

        for (int i = 0; i < otherSize; ++i) {
            data_[size_ + i] = otherList->data_[i];
            otherList->data_[i] = nullptr;
        }

        size_ += otherSize;
        otherList->size_ = 0;
    }

    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete data_[i];
        }
    }

private:
    static constexpr int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_;
};