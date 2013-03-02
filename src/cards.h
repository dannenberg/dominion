#include <string>
#include <iostream>

using namespace std;

/* 
 * This header file defines the abstract classes for the three different types
 * of card in the game as well as the meta-abstract class for cards in general.
 * It also defines the class for each card.
 */

class Card {
    public:
        bool operator==(const Card &other) const;
        string getName();
        int getCost();

        friend ostream& operator<<(ostream &out, const Card &card);
    protected:
        int cost; // cards cost in coin
        string name; // card name
};

/* The following three classes are the abstract classes for the card types */
class TerritoryCard : public Card {
    public:
        int getPoints();
    protected:
        int points; // card value in points
};

class MoneyCard : public Card {
    public:
        int getCoins();
    protected:
        int coins; // card value in coin
};

class ActionCard : public Card {
    public:
        void action(); // method which performs the card action
        void printDescription(); // method to print the card description
    protected:
};

/* This section contains all the Money Cards */
class Copper : public MoneyCard {
    public:
        Copper();
};

class Silver : public MoneyCard {
    public:
        Silver();
};

class Gold : public MoneyCard {
    public:
        Gold();
};

/* This section contains all the Territory Cards */
class Estate : public TerritoryCard {
    public:
        Estate();
};

class Dutchie : public TerritoryCard {
    public:
        Dutchie();
};

class Province : public TerritoryCard {
    public:
        Province();
};

/* This section contains all the Action Cards */
