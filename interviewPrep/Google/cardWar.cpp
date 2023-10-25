class Suit{
    private:
        string suitName;
    public: 
        Suit(string name){
            suitName = name;
        }
        string getSuitName(){
            return suitName;
        }
};

class Face{
    private:
        string faceName;
        int faceValue;
    public:
        Face(string name,int val){
            faceName = name;
            faceValue = val;
        }

        int getFaceValue(){
            return faceValue;
        }
        
        string getFaceName(){
            return faceName;
        }
};

class Card{
    private:
        Suit* suit;
        Face* face;
    public: 
        Card(Suit* suit_, Face* face_){
            suit = suit_;
            face = face_;
        }

        int getValue(){
            return face->getFaceValue();
        }

        string getSuit(){
            return suit->getSuitName(); 
        }

        void print(){
            cout << face->getFaceName() << "-" << suit->getSuitName() << "\t";
        }
};

class Player{
    private: 
        string playerName;
        vector <Card*> cardList;
        unordered_map <Card*,int> cardIndexMap;

        Card* fetchRandom(){
            Card* ans;
            if(cardList.size()==1){
                cardIndexMap.clear();
                ans = cardList[0];
                cardList.clear();
                return ans;
            }

            int randomIndex = (rand()%(cardList.size()));
            ans = cardList[randomIndex];
            cardList[randomIndex] = cardList.back();
            cardIndexMap[cardList.back()] = randomIndex;
            cardIndexMap.erase(ans);
            cardList.pop_back();
            return ans;
        }

    public:
        
        Player(string name,vector <Card*> cards){
            playerName = name;
            cardList = cards;
            for(int i=0;i<cards.size();i++){
                cardIndexMap[cards[i]] = i; 
            }
        }

        Card* getRandomCard(){
            if(cardList.size()==0){
                return NULL;   
            }
            return fetchRandom();
        }

        void addCard(vector <Card*> cards){
            for(int i=0;i<cards.size();i++){
                cardIndexMap[cards[i]] = cardList.size();
                cardList.push_back(cards[i]);
            }
        }

        bool hasCard(){
            return cardList.size()>0;
        }

        string getPlayerName(){
            return playerName;
        }

        void printCards(){
            for(auto i:cardList)
                i->print();
            cout << "\n";
        }
};

class Game{
    private:
        Player* player1;
        Player* player2;
        Player* common;
        bool isWon;

        void initialShuffle(){
            vector <Card*> allCards;
            vector <string> suits = {"Club", "Heart", "Spade", "Diamond"};
            vector <pair <string,int>> faces = {{"One",1},{"Two",2}, {"Three",3}, {"Four",4}, {"Five",5},{"Six",6},{"Seven",7},{"Eight",8},{"Nine",9},{"Ten",10},{"Jack",11},{"Queen",12},{"King",13},{"Ace",14}};

            for(auto suit:suits){
                for(auto face:faces){
                    Suit* s = new Suit(suit);
                    Face* f = new Face(face.first,face.second);
                    allCards.push_back(new Card(s,f));
                }
            }
            common = new Player("Common",allCards);
            
            while(common->hasCard()){
                player1->addCard({common->getRandomCard()});
                player2->addCard({common->getRandomCard()});
            }
        }

        void printConfiguration(){
            cout << "Cards of player " << player1->getPlayerName() << " are\n";
            player1->printCards();
            cout << "\nCards of player " << player2->getPlayerName() << " are\n ";
            player2->printCards();
            cout << "\nCards in Common are\n";
            common->printCards();
            cout << "\n";
        }

    public:
        Game(string name1,string name2){
            player1 = new Player(name1,{});
            player2 = new Player(name2,{});
            initialShuffle();
            isWon = false;
            printConfiguration();
        }

        string play(){      
            while(player1->hasCard() && player2->hasCard()){
                Card* c1 = player1->getRandomCard();
                Card* c2 = player2->getRandomCard();
                cout << player1->getPlayerName();
                c1->print();
                cout << player2->getPlayerName();
                c2->print();
                cout << endl;
                
                common->addCard({c1,c2});
                
                if(c1->getValue() == c2->getValue()){
                    cout << "Equal so added in common\n";
                }else if(c1->getValue() > c2->getValue()){
                    while(common->hasCard()){
                        player1->addCard({common->getRandomCard()});
                    }
                    cout << player1->getPlayerName() << " won this round\n";
                    // player1->printCards();
                }else{
                    while(common->hasCard()){
                        player2->addCard({common->getRandomCard()});
                    }
                    cout << player2->getPlayerName() << " won this round\n";
                    // player2->printCards();
                }
            }
            
            cout << "--------------------------------";

            return player1->hasCard() ? player1->getPlayerName() : player2->getPlayerName();
        }
};

int main(){
    Game* game = new Game("Shivang","Avish");
    cout << "Winner is: " << game->play(); 
}