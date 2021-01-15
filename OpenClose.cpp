/******************************************************************************

 Kaiah Miller. Open Closed Game Implementation in the consol. written in C++

*******************************************************************************/

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;
/* enum to hold the state of the game loop */
enum GameState{
    Ready,
    Playing,
    Gameover,
} ;
/* enum to hold the state of players turns */
enum WhoIsPredictor{
    AIisPredictor,
    PlayerisPredictor
};
/* the computer player implented as an object holding its own data and functionality*/
class AI{
    public:
    char AIleftHand, AIrightHand;
    int prediction = 0;
    
    AI()
    {
        AIleftHand;
        AIrightHand;
        prediction = 0;
    }
    void isPredictor()
    {
        prediction = rand() % 5;
        // integers will hold a random number that represents open or closed, 0 for onen, 1 for closed
        int left = 0, right = 0;
        left = rand() % 2;
        right = rand() % 2;
        if ( left == 0 )
        {
            AIleftHand = 'O';
        }
            else
            {
                AIleftHand ='C';
            }
        if ( right == 0 )
        {
            AIrightHand = 'O';
        }
            else
            {
                AIrightHand ='C';
            }
    }
    
    void isPlayer()
    {
        int left = 0;
        int right = 0;
        left = rand() % 2;
        right = rand() % 2;
        if ( left == 0 )
        {
            AIleftHand = 'O';
        }
            else
            {
                AIleftHand ='C';
            }
        if ( right == 0 )
        {
            AIrightHand = 'O';
        }
            else
            {
                AIrightHand ='C';
            }
    }
    
};

/*function to determine a winner */
bool isWin( AI ai, char lhand, char rhand, int openPrediction)
{
    int openCounter = 0; //this counter will hold the number of open hands each round
    if( ai.AIleftHand == 'O')
    {
        openCounter++;
    }
    if( ai.AIrightHand == 'O' )
    {
        openCounter++;
    }
    if ( lhand == 'O')
    {
        openCounter++;
    }
    if ( rhand == 'O')
    {
        openCounter++;
    }
    
    if( openCounter == openPrediction)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int _gameState, _whoIsPredictor;
   _gameState = GameState::Ready;
   _whoIsPredictor = WhoIsPredictor::AIisPredictor;
    cout << "Welcome to the game!" << endl;
   _gameState = GameState::Playing;
    
    /* bellow is my game loop, where the actual game will take place. */
    while( _gameState == GameState::Playing)
    {
        AI gameAI;
        char leftHand, rightHand;
        int prediction = 0;
        if( _whoIsPredictor == AIisPredictor)
        {
            cout <<"AI is the predictor, whats your input?" << endl;
            cin >> leftHand >> rightHand;
            
            
            while( (leftHand != 79 && leftHand != 67 ) || (rightHand != 79 && rightHand != 67 ) )
            {
             // user input validations
            
                cout << "Bad input: correct input should be of the form CC3, where the first two letters indicate [O]pen or [C]losed state for each hand : ";
                cin >> leftHand >> rightHand;
            }
            
            
            gameAI.isPredictor();
            cout<< "AI: " << gameAI.AIleftHand << gameAI.AIrightHand << gameAI.prediction << endl;
            bool isWIN = isWin( gameAI, leftHand, rightHand, gameAI.prediction);
            if ( isWIN == true)
            {
                cout << "AI WINs!!" << endl;
            }
            else
            {
                cout << "No winner." << endl;
            }
            
        }
        
        else
        {
        cout <<"You are the predictor, whats your input?" << endl;
        cin >> leftHand >> rightHand >> prediction;
            while( (leftHand != 79 && leftHand != 67 ) || (rightHand != 79 && rightHand != 67 ) || ( prediction > 4 || prediction < 0) )
            {
             // user input validations
            
                cout << "Bad input: correct input should be of the form CC3, where the first two letters indicate [O]pen or [C]losed state for each hand, the the third input is a integer (0-4) : ";
                cin >> leftHand >> rightHand >> prediction;
            }
        gameAI.isPredictor();
        bool isWIN = isWin( gameAI, leftHand, rightHand, prediction);
        cout<< "AI: " << gameAI.AIleftHand << gameAI.AIrightHand << endl;

            if ( isWIN == true)
            {
                cout << "AI WINS!!" << endl;;
            }
            else
            {
                cout << "No winner." << endl;
            }
        }
        // below is implementation of play again and changing of player roles
        char playAgain;
        cout << "DO you want to play again?" << endl;
        cout << "Please enter [Y/N] : ";
        cin >> playAgain;
        if( playAgain == 'Y')
        {
            _gameState = GameState::Playing;
            if(_whoIsPredictor == WhoIsPredictor::PlayerisPredictor)
            {
                _whoIsPredictor = WhoIsPredictor::AIisPredictor;
            }
            else
            {
                _whoIsPredictor = WhoIsPredictor::PlayerisPredictor;
            }
        }
        else
        {
            _gameState = GameState::Gameover;
        }
        
    }
    cout << "Ok, bye!";

    return 0;
}
