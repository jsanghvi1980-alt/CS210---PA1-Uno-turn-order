#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;

    std::unique_ptr<List<int>> nums = makeList<int>();

    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();

    nums->addAnywhere(1, new int(99));
    nums->print();

    nums->deleteAnywhere(2);
    nums->print();

    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;

    std::unique_ptr<List<int>> more = makeList<int>();

    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();

    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: Uno scene ----
    std::cout << std::endl << "== Uno Turn Order ==" << std::endl;

    std::unique_ptr<List<Player>> tableOne = makeList<Player>();

    Player* alice = new Player(1, "Alice");
    Player* bob = new Player(2, "Bob");
    Player* carlos = new Player(3, "Carlos");

    // Deal starting cards.
    alice->drawCard(new Card("Red", "5"));
    alice->drawCard(new Card("Blue", "Skip"));

    bob->drawCard(new Card("Green", "7"));
    bob->drawCard(new Card("Yellow", "2"));

    carlos->drawCard(new Card("Blue", "9"));
    carlos->drawCard(new Card("Red", "Reverse"));

    std::cout << "Table one forms:" << std::endl;

    tableOne->addFront(carlos);
    tableOne->addFront(bob);
    tableOne->addFront(alice);
    tableOne->print();

    // Show Alice's hand.
    std::cout << "Alice's starting hand:" << std::endl;
    alice->printHand();

    // Alice plays the card on top of her stack.
    Card* playedCard = alice->playCard();

    if (playedCard != nullptr) {
        std::cout << "Alice plays: " << *playedCard << std::endl;
        delete playedCard;
    }

    Player* daisy = new Player(4, "Daisy");

    daisy->drawCard(new Card("Yellow", "8"));
    daisy->drawCard(new Card("Green", "Draw Two"));

    std::cout << "Daisy joins in the middle:" << std::endl;
    tableOne->addAnywhere(1, daisy);
    tableOne->print();

    std::cout << "Turn order before Reverse:" << std::endl;
    tableOne->print();

    std::cout << "Turn order after Reverse:" << std::endl;
    tableOne->reverse();
    tableOne->print();

    std::cout << "Bob runs out of cards and leaves:" << std::endl;
    tableOne->deleteAnywhere(1);
    tableOne->print();

    // Create the second table.
    std::unique_ptr<List<Player>> tableTwo = makeList<Player>();

    Player* eve = new Player(5, "Eve");
    Player* frank = new Player(6, "Frank");

    eve->drawCard(new Card("Red", "3"));
    eve->drawCard(new Card("Blue", "Draw Two"));

    frank->drawCard(new Card("Green", "6"));
    frank->drawCard(new Card("Yellow", "Skip"));

    tableTwo->addFront(frank);
    tableTwo->addFront(eve);

    std::cout << "Table one before merging:" << std::endl;
    tableOne->print();

    std::cout << "Table two before merging:" << std::endl;
    tableTwo->print();

    tableOne->concat(tableTwo.get());

    std::cout << "Table one after merging:" << std::endl;
    tableOne->print();

    std::cout << "Table two after merging:" << std::endl;
    tableTwo->print();

    return 0;
}