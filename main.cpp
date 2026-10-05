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

    Player* carl = new Player(1, "Carl");
    Player* fiona = new Player(2, "Fiona");
    Player* liam = new Player(3, "Liam");

    // Deal starting cards.
    carl->drawCard(new Card("Red", "5"));
    carl->drawCard(new Card("Blue", "Skip"));

    fiona->drawCard(new Card("Green", "7"));
    fiona->drawCard(new Card("Yellow", "2"));

    liam->drawCard(new Card("Blue", "9"));
    liam->drawCard(new Card("Red", "Reverse"));

    std::cout << "Table one forms:" << std::endl;

    tableOne->addFront(liam);
    tableOne->addFront(fiona);
    tableOne->addFront(carl);
    tableOne->print();

    // Show Carl's cards.
    std::cout << "Carl's starting hand:" << std::endl;
    carl->printHand();

    // Carl plays the card on top of his stack.
    Card* playedCard = carl->playCard();

    if (playedCard != nullptr) {
        std::cout << "Carl plays: " << *playedCard << std::endl;
        delete playedCard;
    }

    Player* lip = new Player(4, "Lip");

    lip->drawCard(new Card("Yellow", "8"));
    lip->drawCard(new Card("Green", "Draw Two"));

    std::cout << "Lip joins in the middle:" << std::endl;
    tableOne->addAnywhere(1, lip);
    tableOne->print();

    std::cout << "Turn order before Reverse:" << std::endl;
    tableOne->print();

    std::cout << "Turn order after Reverse:" << std::endl;
    tableOne->reverse();
    tableOne->print();

    std::cout << "Fiona runs out of cards and leaves:" << std::endl;
    tableOne->deleteAnywhere(1);
    tableOne->print();

    // Create the second table.
    std::unique_ptr<List<Player>> tableTwo = makeList<Player>();

    Player* monica = new Player(5, "Monica");
    Player* debbie = new Player(6, "Debbie");

    monica->drawCard(new Card("Red", "3"));
    monica->drawCard(new Card("Blue", "Draw Two"));

    debbie->drawCard(new Card("Green", "6"));
    debbie->drawCard(new Card("Yellow", "Skip"));

    tableTwo->addFront(debbie);
    tableTwo->addFront(monica);

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