#include <iostream>
#include "ZorkUL.h"
#include <cstdlib>
using namespace std;

int main() {
    ZorkUL game;
    game.play();
    return 0;
}

ZorkUL::ZorkUL() {
    createRooms();
    character = new Character();
}

void ZorkUL::createRooms() {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;
    a = new Room("a");
    a->addItem(new Item("x", 1, 11));
    a->addItem(new Item("y", 2, 22));
    b = new Room("b");
    b->addItem(new Item("xx", 3, 33));
    b->addItem(new Item("yy", 4, 44));
    c = new Room("c");
    d = new Room("d");
    e = new Room("e");
    f = new Room("f");
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");
    j = new Room("j");

    //             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, j, NULL);
    j->setExits(i, NULL, NULL, NULL);

    currentRoom = a;

    rooms[0] = a;
    rooms[1] = b;
    rooms[2] = c;
    rooms[3] = d;
    rooms[4] = e;
    rooms[5] = f;
    rooms[6] = g;
    rooms[7] = h;
    rooms[8] = i;
    rooms[9] = j;
}

void ZorkUL::play() {
    printWelcome();
    bool finished = false;
    
    while (!finished) {
        Command* command = parser.getCommand();
        finished = processCommand(*command);
        delete command;
    }
    cout << "end" << endl;
}

bool ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
        cout << "invalid input" << endl;
        return false;
    }

    string commandWord = command.getCommandWord();
    if (commandWord == "info") {
        printHelp();
    } else if (commandWord == "map") {
        printMap();
    } else if (commandWord == "teleport") {
        teleport();
    } else if (commandWord == "inventory") {
        printInventory();
    } else if (commandWord == "quit") {
        return true; /**signal to quit*/
    } else if (!command.hasSecondWord()) { //MARK: Two word commands
        cout << "incomplete input" << endl;
    } else if (commandWord == "take") {
        takeItem(command);
    } else if (commandWord == "put") {
        //TODO: placing items
    } else if (commandWord == "go") {
        goRoom(command);
    }
    
    return false;
}

//MARK: Commands
void ZorkUL::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();

}

void ZorkUL::printWelcome() {
    cout << "start" << endl;
    cout << "info for help" << endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}

void ZorkUL::printMap() {
    cout << "[h] --- [f] --- [g]" << endl;
    cout << "         |         " << endl;
    cout << "         |         " << endl;
    cout << "[c] --- [a] --- [b]" << endl;
    cout << "         |         " << endl;
    cout << "         |         " << endl;
    cout << "[i] --- [d] --- [e]" << endl;
    cout << " |                 " << endl;
    cout << " |                 " << endl;
    cout << "[j]                " << endl;
}

void ZorkUL::printInventory() {
    cout << character->longDescription() << endl;
}

void ZorkUL::takeItem(Command command) {
    Item* item = currentRoom->takeItem(command.getSecondWord());
    
    if (item == NULL) {
        cout << "Item is not in room" << endl;
        return;
    }
    
    character->addItem(item);
    printCurrentRoomInfo();
}

void ZorkUL::placeItem(Command command) {
    string itemName = command.getSecondWord(); 
}

void ZorkUL::teleport() {
    int roomNumber = rand() % 10;
    currentRoom = rooms[roomNumber];
    printCurrentRoomInfo();
}

void ZorkUL::goRoom(Command command) {
    string direction = command.getSecondWord();
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input" << endl;
    else {
        currentRoom = nextRoom;
        printCurrentRoomInfo();
    }
}

void ZorkUL::printCurrentRoomInfo() {
    cout << currentRoom->longDescription() << endl;
}

string ZorkUL::go(string direction) {
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return ("direction null");
    else {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}
