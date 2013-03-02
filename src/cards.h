#include <string>
#include <iostream>

using namespace std;

/* 
 * This header file defines the abstract classes for the three different types
 * of card in the game as well as the meta-abstract class for cards in general.
 * It also defines the class for each card.
 */

vector<string> kingdomCards({Cellar(),
                            Chapel(),
                            Moat(),
                            cur_Chancellor(),
                            Village(),
                            Woodcutter(),
                            Workshop(),
                            Bureaucrat(),
                            Feast(),
                            Gardens(),
                            Militia(),
                            Moneylender(),
                            Remodel(),
                            Smithy(),
                            Spy(),
                            Thief(),
                            ThroneRoom(),
                            CouncilRoom(),
                            Festival(),
                            Laboratory(),
                            Library(),
                            Market(),
                            Mine(),
                            Witch(),
                            Adventurer()});

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

/* The following classes are the abstract classes for the card types */
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
        virtual void action(); // method which performs the card action
        void printDescription(); // method to print the card description
    protected:
};

class AttackCard : public ActionCard {}

/* This section contains all the basic Money Cards */
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

/* This section contains all the basic Territory Cards */
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

class Curse : public TerritoryCard {
    public:
        Curse();
}

/* This section contains all the basic Action Cards */
class Cellar : public ActionCard {
    public:
        Cellar();
};

class Chapel : public ActionCard {
    public:
        Chapel();
};

class Moat : public ActionCard {
    public:
        Moat();
};

class Chancellor : public ActionCard {
    public:
        Chancellor();
};

class Village : public ActionCard {
    public:
        Village();
};

class Woodcutter : public ActionCard {
    public:
        Woodcutter();
};

class Workshop : public ActionCard {
    public:
        Workshop();
};

class Bureaucrat : public AttackCard {
    public:
        Bureaucrat();
};

class Feast : public ActionCard {
    public:
        Feast();
};

class Gardens : public TerritoryCard {
    public:
        Gardens();
};

class Militia : public AttackCard {
    public:
        Militia();
};

class Moneylender : public ActionCard {
    public:
        Moneylender();
};

class Remodel : public ActionCard {
    public:
        Remodel();
};

class Smithy : public ActionCard {
    public:
        Smithy();
};

class Spy : public AttackCard {
    public:
        Spy();
};

class Thief : public AttackCard {
    public:
        Thief();
};

class ThroneRoom : public ActionCard {
    public:
        ThroneRoom();
};

class CouncilRoom : public AttackCard {
    // only an attack to have access to other players (moat should not block)
    public:
        CouncilRoom();
};

class Festival : public ActionCard {
    public:
        Festival();
};

class Laboratory : public ActionCard {
    public:
        Laboratory();
};

class Library : public ActionCard {
    public:
        Library();
};

class Market : public ActionCard {
    public:
        Market();
};

class Mine : public ActionCard {
    public:
        Mine();
};

class Witch : public AttackCard {
    public:
        Witch();
};

class Adventurer : public ActionCard {
    public:
        Adventurer();
};
