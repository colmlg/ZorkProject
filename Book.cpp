#include "Book.h"

Book::Book() {
	longDescription = "A mysterious glowing book.";
	consumable = true;
	actionDescription = "You are teleported to a new room.";
	icon = new QIcon(QString::fromStdString(":/images/items/Book_03.png"));
}

