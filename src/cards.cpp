#include "cards.h"

/* Methods for the abstract classes */
bool Card::operator==(const Card &other) const {
    return name == other.name;
}

ostream& operator<<(ostream& out, const Card &card) {
    out << card.name;
    return out;
}

string Card::getName() {
    return name;
}

int Card::getCost() {
    return cost;
}

int TerritoryCard::getPoints() {
    return points;
}

int MoneyCard::getCoins() {
    return coins;
}

void ActionCard::action() {
    cout << "action!" << endl; // TODO actually implement this
}

/* Money cards */
Copper::Copper() {
    name = "Copper";
    cost = 0;
    coins = 1;
}

Silver::Silver() {
    name = "Silver";
    cost = 3;
    coins = 2;
}

Gold::Gold() {
    name = "Gold";
    cost = 6;
    coins = 3;
}

/* Territory Cards */
Estate::Estate() {
    name = "Estate";
    cost = 2;
    points = 1;
}

Dutchie::Dutchie() {
    name = "Dutchie";
    cost = 5;
    points = 3;
}

Province::Province() {
    name = "Province";
    cost = 8;
    points = 6;
}

/* Action Cards */
