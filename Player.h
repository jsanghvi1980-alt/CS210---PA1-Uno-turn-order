#pragma once

#include <ostream>
#include <string>

#include "Card.h"
#include "Stack.h"

class Player {
public:
    Player(int id, const std::string& name)
        : id_(id), name_(name), hand_(new Stack<Card>()) {
    }

    bool operator==(const Player& other) const {
        return id_ == other.id_;
    }

    void drawCard(Card* card) {
        hand_->push(card);
    }

    Card* playCard() {
        return hand_->pop();
    }

    void printHand() const {
        hand_->print();
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& player) {
        return out << player.id_ << " " << player.name_;
    }

    ~Player() {
        delete hand_;
    }

    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

private:
    int id_;
    std::string name_;
    Stack<Card>* hand_;
};