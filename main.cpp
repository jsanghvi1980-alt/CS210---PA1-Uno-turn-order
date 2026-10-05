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

    // ---- Part 2: your Uno scene goes below ----
    std::cout << std::endl << "== Uno Turn Order ==" << std::endl;

    std::unique_ptr<List<Player>> tableOne = makeList<Player>();

    std::cout << "Table one forms:" << std::endl;

    tableOne->addFront(new Player(3, "Carlos"));
    tableOne->addFront(new Player(2, "Bob"));
    tableOne->addFront(new Player(1, "Alice"));
    tableOne->print();

    std::cout << "Daisy joins in the middle:" << std::endl;

    tableOne->addAnywhere(1, new Player(4, "Daisy"));
    tableOne->print();

    std::cout << "Turn order before Reverse:" << std::endl;
    tableOne->print();

    std::cout << "Turn order after Reverse:" << std::endl;
    tableOne->reverse();
    tableOne->print();

    std::cout << "Bob runs out of cards and leaves:" << std::endl;

    tableOne->deleteAnywhere(1);
    tableOne->print();

    std::unique_ptr<List<Player>> tableTwo = makeList<Player>();

    tableTwo->addFront(new Player(6, "Frank"));
    tableTwo->addFront(new Player(5, "Eve"));

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
