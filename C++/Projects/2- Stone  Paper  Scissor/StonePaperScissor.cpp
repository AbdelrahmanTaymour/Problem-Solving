
#include <iostream>
using namespace std;

enum enGameChoice{Stone = 1, Paper = 2, Scissors = 3};
enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice PlayerChoice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};
struct stGameResult
{
    short GameRounds = 0;
    short PlayerWinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

short ReadHowManyRounds()
{
    short Number;
    do 
    {
        cout << "How Many Rounds? 1 to 10? ";
        cin >> Number;
    } while (Number < 1 || Number>10);
    return Number;
}

enGameChoice ReadPlayerChoice()
{
    short Choice;
    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?";
        cin >> Choice;

    } while (Choice < 1 || Choice>3);

    return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
        return enWinner::Draw;

    switch (RoundInfo.PlayerChoice)
    {
    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
            return enWinner::Computer;
        break;
    case enGameChoice::Scissors:
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
            return enWinner::Computer;
        break;
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
            return enWinner::Computer;
        break;
    }
    return enWinner::Player;
}

string WinnerName(enWinner Winner)
{
    string arrPlayers[3] = { "Player","Computer","Draw" };
    return arrPlayers[Winner - 1];
}

string ChoiceName(enGameChoice Choice)
{
    string arrChoice[3] = { "Stone","Paper","Scissors" };
    return arrChoice[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player:
        system("color 2F");
        break;
    case enWinner::Computer:
        system("color 4F");
        cout << "\a";
        break;
    case enWinner::Draw:
        system("color 6F");
        break;
    }
}

void PrintRoundResult(stRoundInfo RoundInfo)
{
    cout << "\n____________ Round [" << RoundInfo.RoundNumber << "]____________\n\n";
    cout << "Player   Choice: " << ChoiceName(RoundInfo.PlayerChoice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "RoundWinner    : " << RoundInfo.WinnerName << endl;
    cout << "__________________________________\n" << endl;

    SetWinnerScreenColor(RoundInfo.Winner);
}

enWinner WhoWonTheGame(short PlayerWinTimes, short ComputeWinTimes)
{
    if (PlayerWinTimes == ComputeWinTimes)
        return enWinner::Draw;
    else if (PlayerWinTimes > ComputeWinTimes)
        return enWinner::Player;
    else
        return enWinner::Computer;
}

stGameResult FillGameResult(short GameRounds, short PlayerWinTimes, short ComputeWinTimes, short DrawTimes)
{
    stGameResult GameResult;
    GameResult.GameRounds = GameRounds;
    GameResult.PlayerWinTimes = PlayerWinTimes;
    GameResult.ComputerWinTimes = ComputeWinTimes;
    GameResult.DrawTimes = DrawTimes;
    GameResult.GameWinner = WhoWonTheGame(PlayerWinTimes, ComputeWinTimes);
    GameResult.WinnerName = WinnerName(GameResult.GameWinner);

    return GameResult;
}

stGameResult PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1;GameRound <= HowManyRounds;GameRound++)
    {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.PlayerChoice = ReadPlayerChoice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player)
            PlayerWinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        PrintRoundResult(RoundInfo);
    }
    return FillGameResult(HowManyRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}

string Tab(short HowManyTaps)
{
    string Tab = "";
    for (int i = 1;i < HowManyTaps;i++)
    {
        Tab += "\t";
        cout << Tab;
    }
    return Tab;
}

void SetGameOverScreen()
{
    
    cout << Tab(2) << "__________________________________________________________\n\n";
    cout << Tab(2) << "                 +++ G a m e O v e r +++ \n";
    cout << Tab(2) << "__________________________________________________________\n\n";
}

void ShowFinalGameResult(stGameResult GameResult)
{
    cout << Tab(2) << "_____________________ [ Game Result ] _____________________\n\n";
    cout << Tab(2) << "Game Rounds        : " << GameResult.GameRounds << endl;
    cout << Tab(2) << "Player Won Times   : " << GameResult.PlayerWinTimes << endl;
    cout << Tab(2) << "Computer Won Times : " << GameResult.ComputerWinTimes << endl;
    cout << Tab(2) << "Draw Times         : " << GameResult.DrawTimes << endl;
    cout << Tab(2) << "Final Winner       : " << GameResult.WinnerName << endl;
    cout << Tab(2) << "____________________________________________________________\n\n";

    SetWinnerScreenColor(GameResult.GameWinner);
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        stGameResult GameResult = PlayGame(ReadHowManyRounds());
        SetGameOverScreen();
        ShowFinalGameResult(GameResult);

        cout << endl << Tab(2) << "Do you want play again? Y/N? ";
        cin >> PlayAgain;

    } while (PlayAgain == 'y' || PlayAgain == 'Y');
}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}
