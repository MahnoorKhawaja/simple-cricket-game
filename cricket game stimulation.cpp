#include <iostream>
#include <cstdlib>
#include <cstring>
#include <conio.h>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

const int NUM_ROWS = 7;
const int NUM_COLS = 6;
int scoreA[NUM_ROWS][NUM_COLS] = {{0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0}};
const int NUM_ROW = 7;
const int NUM_COL = 6;
int scoreB[NUM_ROW][NUM_COL] = {{0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0}};
int batsmanorder[7] = {0, 1, 2, 3, 4, 5, 6};
int batsmanorderB[7] = {0, 1, 2, 3, 4, 5, 6};
char teamA[7][20] = {"sarfaraz", "mohid", "hassan", "taha", "farhan", "amjab", "furqan"};
char teamB[7][20] = {"sikandar", "phelaj", "iftikar", "bashir", "mujtaba", "sohail", "sameer"};
char scorecategories[7][20] = {"name", "runsscored", "ballsfaced", "ballsbowled", "runsgiven", "wicketstaken", "oversbowled"};

int toss() // does the toss if 1 comes A team bats and if 0 comes B team bats
{
    srand(time(NULL));
    int toss = rand() % 2; // generates 0 or 1

    return toss;
}

void updatescoreboard() // updates score card along the code and displays at the end
{
    cout << "       -------- SCORE BOARD OF TEAM A----------" << endl;
    cout << "  ";
    for (int i = 0; i < 7; i++)
    {
        cout << scorecategories[i] << setw(13);
    }
    cout << endl;

    for (int i = 0; i < 7; i++)
    {
        cout << setw(10) << teamA[i];
        for (int j = 0; j < 6; j++)
        {
            cout << setw(11) << scoreA[i][j];
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << "     ------- SCORE BOARD OF TEAM B--------" << endl;
    cout << "  ";
    for (int i = 0; i < 7; i++)
    {
        cout << scorecategories[i] << setw(13);
    }
    cout << endl;

    for (int i = 0; i < 7; i++)
    {
        cout << setw(10) << teamB[i];
        for (int j = 0; j < 6; j++)
        {
            cout << setw(11) << scoreB[i][j];
        }
        cout << endl;
    }
}
int addScore(int total, int runs) // adds the total score of the team
{
    total += runs;
    return total;
}

void fallsofwicketB(int playernumber, int wicketstaken) // calculates the wickets fallen
{

    scoreB[playernumber][4] += wicketstaken;
}
void fallsofwicketA(int playernumber, int wicketstaken)
{

    scoreA[playernumber][4] += wicketstaken;
}
void overbowledA(int playernumber, int overs) // calculates the over bowled
{
    scoreA[playernumber][5] += overs;
}
void overbowledB(int playernumber, int overs)
{
    scoreB[playernumber][5] += overs;
}
void battingboardB(int playernumber, int runsscored, int ballsfaced) // updates the batting score of team B
{
    scoreB[playernumber][0] += runsscored;
    scoreB[playernumber][1] += ballsfaced;
}
void bowlingboardB(int playernumber, int ballsbowled, int runsgiven) // updates the bowling score of team B
{
    scoreB[playernumber][2] += ballsbowled;
    scoreB[playernumber][3] += runsgiven;
}
void battingboard(int playernumber, int runsscored, int ballsfaced) // updates batting score of team A
{
    scoreA[playernumber][0] += runsscored;
    scoreA[playernumber][1] += ballsfaced;
}
void bowlingboard(int playernumber, int ballsbowled, int runsgiven) // for bowling score of team A
{

    scoreA[playernumber][2] += ballsbowled;
    scoreA[playernumber][3] += runsgiven;
}

int main()
{

    int runsscoredA = 0, ballsfacedA = 0, ballsbowled = 0, runsgiven = 0, wickettaken = 0, total = 0, fall = 0, runsscoredB = 0, ballsfacedB = 0, score = 0, scoreb = 0;
    int batsmanofmatchA = 0, ballerofmatchA = 0, max = scoreA[0][0], maxA = scoreA[0][4], ballerofmatchB = 0, batsmanofmatchB = 0, maxB = scoreB[0][0], maxBB = scoreB[0][4];
    int totalplayersbatting = (sizeof(batsmanorder) / sizeof(batsmanorder[0]));
    int playercharc1 = 0, playercharc2 = 1, count = 0, index1 = 0, index2 = 1;
    int enter1, enter2;
    int ball, baller_balls, BALLER_BALLS, overs = 0;
    int entertoss = 0, match = 0, bat = 0;
    bool press = 1;
    char press1;
    int player1 = batsmanorder[index1];
    int player2 = batsmanorder[index2];
    char teammA[40] = "TEAM A WON THE MATCH";
    char teammB[40] = "TEAM B WON THE MATCH";
    char draw[100] = " THE GAME IS DRAWED BOTH TEAMS PLAYED VERY WELL, UNTIL NEXT TIME, SIGN OUT!!!";
    char forfile[60];
    char batsman[20];
    char ballermatch[20];
    // specifies the baller name who is balling
    int b1 = 0, baller = 6;
    cout << "---------CRICKET MATCH---------------" << endl;
    cout << "introducing members of two teams" << endl;
    cout << "TEAM A : " << endl;
    for (int i = 0; i < 7; i++) // introducing teams
    {
        cout << "Player" << i + 1 << "."
             << " " << teamA[i] << endl;
    }

    cout << endl;
    cout << "TEAM B : " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << "Player" << i + 1 << "."
             << " " << teamB[i] << endl;
    }
    cout << endl;
    // reading overs from file
    string filename = "configuration.txt"; // file configuration for number of overs
    string data = "20 overs";

    // Open a file in write mode
    ofstream outfile(filename);

    // Write data to the file
    outfile << data << endl;

    // Close the file
    outfile.close();

    // Open the same file in read mode
    ifstream infile(filename);

    // Read data from the file
    string line;
    getline(infile, line);

    // Print the data to the console
    cout << "Total overs for the game are : " << line << endl;

    // Close the file
    infile.close();

    cout << endl;
    cout << "TIME FOR TOSS" << endl;
    cout << endl;
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "Press ENTER key for toss " << endl; // ascii for enter key is 13
    entertoss = _getch();
    if (entertoss == 13)
    {
        match = toss();
    }

    if (match == 1) // team A bats first and then team B bats
    {
        cout << "TEAM A WON THE TOSS" << endl;
        cout << endl;
        cout << "--------TEAM A will be batting----------- " << endl;
        cout << endl;
        cout << "--------TEAM B will be balling----------- " << endl;
        cout << endl;
        cout << "-----------FIRST INNINGS OF THE MATCH----------------" << endl;
        int overcheck1;
        for (int i = 1; i <= 2; i++) // total 20 overs to be played
        {
            overcheck1 = i;
            cout << "--------" << i << "th over is being played-------" << endl;
            if (count == 5)
            {
                baller--;
                count = 0;
            }
            for (int j = 1; j <= 5; j++) // loop for 4 balls per bowler, making last five players of team B ballers
            {

                cout << "-----------Players on the field--------- " << endl;

                cout << "Player number "
                     << "1" << endl;
                // printing the player names

                cout << teamA[playercharc1];

                cout << endl;

                cout << "Player number"
                     << "2" << endl;
                int p2 = 0;

                cout << teamA[playercharc2];

                cout << endl;

                cout << "BALLING TIME" << endl;
                cout << "ball number : " << j << endl;

                cout << teamB[baller];

                cout << " : Baller of the team B, ball : (press ENTER to ball a ball)" << endl;
                ball = _getch();
                if (ball == 13) // enters to ball
                {
                    baller_balls = rand() % 8 - 1;
                    ballsbowled++;
                }
                else
                {
                    cout << "WRONG KEY HAS BEEN PRESSED CANNOT PLAY FORWARD" << endl;
                    cout << "start the game again.... :(" << endl;
                    return 0;
                }

                cout << "currently batting player :" << endl;
                int index;
                index = batsmanorder[player1];

                cout << teamA[player1];

                cout << endl;
                int bated = 0;
                cout << "enter to bat " << endl; // for bat
                ball = _getch();
                if (ball == 13)
                {
                    bated = rand() % 7;
                }
                runsgiven = bated;
                bowlingboardB(baller, ballsbowled, runsgiven);
                ballsbowled = 0;

                if (baller_balls != -1) // if wicket is not out score is given to batsman
                {
                    cout << "score :" << bated << endl;
                    score += bated;
                    runsgiven = bated;
                    runsscoredA = bated;
                    ballsfacedA++;
                    battingboard(player1, runsscoredA, ballsfacedA);
                    ballsfacedA = 0;
                    if (bated % 2 != 0) // odd runs places changed
                    {

                        int temp;
                        temp = index1;
                        index1 = index2;
                        index2 = temp;
                        player1 = batsmanorder[index1];
                        player2 = batsmanorder[index2];
                        playercharc1 = player1;
                        playercharc2 = player2;
                    }
                }
                else if (baller_balls == -1) // out, displayes the scoreboard and replaces it with a new batsman
                {
                    int outplayer;
                    outplayer = index;
                    ++fall;
                    fallsofwicketB(baller, fall);

                    fall = 0;

                    cout << "PLAYER OUT " << endl;
                    cout << "player got out during the " << overcheck1 << " over" << endl;
                    cout << "------------scoreboard of the player------------------" << endl;
                    cout << endl;
                    for (int i = 0; i < 3; i++)
                    {
                        cout << scorecategories[i] << "     ";
                    }
                    cout << endl;

                    for (int j = 0; j < 20; j++)
                    {
                        cout << teamA[player1][j];
                    }
                    cout << "      ";
                    for (int i = 0; i < 2; i++)
                    {
                        cout << scoreA[player1][i] << "              ";
                    }
                    cout << endl;
                    // deleting the currently player index that got out from the batsman order array
                    for (int i = index1; i <= (totalplayersbatting); i++)
                    {
                        batsmanorder[i] = batsmanorder[i + 1];
                    }
                    totalplayersbatting--;

                    cout << endl;
                    if (totalplayersbatting > 1)
                    {

                        player1 = batsmanorder[0];
                        while (player1 == player2)
                        {
                            player1 = batsmanorder[1];
                        }
                        playercharc1 = player1;
                    }
                    else
                    {
                        cout << " no PAIR of players left thus match ended for team A" << endl;
                        goto innings;
                    }
                }
            }
            count++;
            overs++;
            overbowledB(baller, overs);
            overs = 0;

            int temp1; // swaps places afterevery over as well
            temp1 = index1;
            index1 = index2;
            index2 = temp1;
            player1 = batsmanorder[index1];
            player2 = batsmanorder[index2];
            playercharc1 = player1;
            playercharc2 = player2;
        }
        cout << endl;
        cout << endl;
        // check...
    innings:
        cout << "----------SCOREBOARD OF 1ST INNINGS-------------" << endl;
        cout << "          ------BATTING TEAM A ------" << endl;
        for (int i = 0; i < 3; i++) // prints the categories
        {
            cout << "    " << scorecategories[i];
        }
        cout << endl;
        for (int i = 0; i < 7; i++) // prints the names and scores
        {
            cout << setw(10) << teamA[i];
            for (int j = 0; j < 2; j++)
            {
                cout << setw(10) << scoreA[i][j];
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;

        cout << "------------------TOTAL SCORE MADE BY TEAM A IN FIRST INNINGS IS ----------------------------:   " << score << endl;
        cout << endl;
        cout << endl;
        cout << "          -----BALLING TEAM B-----" << endl;
        cout << "   "
             << "name";
        for (int i = 3; i < 7; i++) // category for team balling
        {
            cout << "    " << scorecategories[i];
        }
        cout << endl;
        for (int i = 0; i < 7; i++) // print names and scores respectively
        {
            cout << setw(10) << teamB[i];
            for (int j = 2; j < 6; j++)
            {
                cout << setw(10) << scoreB[i][j] << "    ";
            }
            cout << endl;
        }
        cout << endl;

        // FIRST INNING HAS BEEN ENDED

        // batting of team B and balling of team A
        int enter;
        cout << "Enter to start the batting of Team B " << endl;
        enter = getch();
        if (enter == 13)
        {
            cout << "LETS GO!!!!!!!!!!" << endl;
            cout << "-----------BATTING FOR TEAM B IS TAKING PLACE RIGHT NOWW---------" << endl;
        }
        srand(time(NULL));
        overs = 0;
        baller = 6;
        player1 = 0;
        player2 = 1;
        playercharc1 = 0;
        playercharc2 = 1;
        fall = 0;
        count = 0;
        total = 0;
        runsgiven = 0;
        ballsbowled = 0;
        index1 = 0;
        index2 = 1;
        player1 = batsmanorderB[index1];
        player2 = batsmanorderB[index2];
        int ballb, overcheck;
        int totalplayersbatting1 = sizeof(batsmanorder) / sizeof(batsmanorder[0]);
        for (int i = 1; i <= 2; i++) // total 20 overs to be played and now team B is batting
        {
            overcheck = i;
            cout << "--------" << i << "th over is being played-------" << endl;
            if (count == 5)
            {
                baller--;
                count = 0;
            }

            for (int j = 1; j <= 5; j++) // loop for 4 balls per bowler, making last five players of team B ballers
            {
                if (scoreb > score)
                {
                    cout << "TEAM SCORED CROSS THE SCORE OF THE OPPONENT, MATCH INNINGS OVER" << endl;
                    goto innings11;
                }
                cout << "-----------Players on the field--------- " << endl;

                cout << "Player number "
                     << "1" << endl;

                // printing the player names team b players

                cout << teamB[playercharc1];

                cout << endl;

                cout << "Player number"
                     << "2" << endl;

                cout << teamB[playercharc2];

                cout << endl;

                cout << "BALLING TIME" << endl;
                cout << "ball number : " << j << endl;

                // specifies the baller name who is balling

                cout << teamA[baller];

                cout << " : Baller of the team B, ball : (press ENTER to ball a ball)" << endl;
                ballb = getch();
                if (ballb == 13)
                {
                    BALLER_BALLS = rand() % 8 - 1;
                    ballsbowled++;
                }
                else
                {
                    cout << "WRONG KEY HAS BEEN PRESSED CANNOT PLAY FORWARD" << endl;
                    cout << "start the game again.... :(" << endl;
                    return 0;
                }

                cout << "currently batting player :" << endl;
                int index;
                index = batsmanorderB[player1];

                cout << teamB[player1];

                cout << endl;
                int batedd;
                cout << "enter to bat " << endl;
                ball = _getch();
                if (ball == 13)
                {
                    batedd = rand() % 7;
                }
                runsgiven = batedd;
                bowlingboard(baller, ballsbowled, runsgiven);
                ballsbowled = 0;
                if (BALLER_BALLS != -1)
                {
                    cout << "score :" << batedd << endl;
                    scoreb += batedd;
                    runsscoredB = batedd;
                    ballsfacedB++;
                    battingboardB(player1, runsscoredB, ballsfacedB);
                    ballsfacedB = 0;
                    if (batedd % 2 != 0)
                    {

                        int temp3;
                        temp3 = index1;
                        index1 = index2;
                        index2 = temp3;
                        player1 = batsmanorderB[index1];
                        player2 = batsmanorderB[index2];
                        playercharc1 = player1;
                        playercharc2 = player2;
                    }
                }
                else if (BALLER_BALLS == -1)
                {
                    int outplayer;
                    outplayer = index;
                    ++fall;
                    fallsofwicketA(baller, fall);
                    fall = 0;
                    cout << "PLAYER OUT " << endl;
                    cout << "player got out during the " << overcheck << " over" << endl;
                    cout << "------------scoreboard of the player------------------" << endl;
                    cout << endl;
                    for (int i = 0; i < 3; i++)
                    {
                        cout << scorecategories[i] << "     ";
                    }
                    cout << endl;

                    for (int j = 0; j < 20; j++)
                    {
                        cout << teamB[player1][j];
                    }
                    cout << "    ";
                    for (int i = 0; i < 2; i++)
                    {
                        cout << scoreB[player1][i] << "              ";
                    }

                    for (int i = index1; i <= (totalplayersbatting1); i++)
                    {
                        batsmanorderB[i] = batsmanorderB[i + 1];
                    }
                    totalplayersbatting1--;

                    cout << endl;
                    if (totalplayersbatting1 > 1)
                    {

                        player1 = batsmanorderB[0];
                        while (player1 == player2)
                        {
                            player1 = batsmanorderB[1];
                        }
                        playercharc1 = player1;
                    }
                    else
                    {
                        cout << " no PAIR of players left thus match ended for team A" << endl;
                        goto innings11;
                    }
                }
            }
            count++;
            overs++;
            overbowledA(baller, overs);
            overs = 0;
            int temp2;
            temp2 = index1;
            index1 = index2;
            index2 = temp2;
            player1 = batsmanorderB[index1];
            player2 = batsmanorderB[index2];
            playercharc1 = player1;
            playercharc2 = player2;
        }
        cout << endl;

    innings11:
        // ADD SECOND INNINGS SCOREBOARD
        cout << "----------SCOREBOARD OF 2ND INNINGS-------------" << endl;
        cout << "          ------BATTING TEAM B ------" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "    " << scorecategories[i];
        }
        cout << endl;
        for (int i = 0; i < 7; i++)
        {
            cout << setw(10) << teamB[i];
            for (int j = 0; j < 2; j++)
            {
                cout << setw(10) << scoreB[i][j];
            }
            cout << endl;
        }
        cout << "------------------  the total score of team B is -------------- " << scoreb << endl;
        cout << endl;
        cout << "          -----BALLING TEAM A-----" << endl;
        cout << "    "
             << "name";
        for (int i = 3; i < 7; i++)
        {
            cout << "    " << scorecategories[i];
        }
        cout << endl;
        for (int i = 0; i < 7; i++)
        {
            cout << setw(10) << teamA[i];
            for (int j = 2; j < 6; j++)
            {
                cout << setw(10) << scoreA[i][j] << "    ";
            }
            cout << endl;
        }
        cout << endl;
        cout << "Do you want to see match summary???? Press enter if yes and A if no." << endl;
        enter1 = _getch();
        if (enter1 == 13)
        {
            updatescoreboard();
        }
        else if (enter1 == 65)
        {
            cout << "got it!! not showing you the summary" << endl;
        }
        cout << endl;
        // final decalarations
        if (scoreb < score)
        {
            cout << teammA << endl;
            strcpy(forfile, teammA);
        }
        else if (scoreb > score)
        {
            cout << teammB << endl;
            strcpy(forfile, teammB);
        }
        else
        {
            cout << draw << endl;
            strcpy(forfile, draw);
        }

        for (int i = 0; i < 7; i++)
        {
            if (scoreA[i][0] > max)
            {
                max = scoreA[i][0];
                batsmanofmatchA = i;
            }
        }
        for (int i = 3; i < 7; i++)
        {
            if (scoreA[i][4] > maxA)
            {
                maxA = scoreA[i][4];
                ballerofmatchA = i;
            }
        }
        for (int i = 0; i < 7; i++)
        {
            if (scoreB[i][0] > maxB)
            {
                maxB = scoreB[i][0];
                batsmanofmatchB = i;
            }
        }
        for (int i = 3; i < 7; i++)
        {
            if (scoreB[i][4] > maxBB)
            {
                maxBB = scoreB[i][4];
                ballerofmatchB = i;
            }
        }

        if (scoreA[batsmanofmatchA][0] < scoreB[batsmanofmatchB][0])
        {
            cout << "---------- BATSMAN OF THE MATCH IS---------------" << endl;

            cout << teamB[batsmanofmatchB];
            strcpy(batsman, teamB[batsmanofmatchB]);
        }
        else
        {
            cout << "---------- BATSMAN OF THE MATCH IS---------------" << endl;

            cout << teamA[batsmanofmatchA];
            strcpy(batsman, teamA[batsmanofmatchA]);
            cout << endl;
        }
        cout << endl;

        if (scoreA[ballerofmatchA][4] < scoreB[ballerofmatchB][4])
        {

            cout << "---------- BALLER OF THE MATCH IS-----------" << endl;
            cout << teamB[ballerofmatchB];
            strcpy(ballermatch, teamB[ballerofmatchB]);

            cout << endl;
        }
        else if (scoreA[ballerofmatchA][4] <= scoreB[ballerofmatchB][4])
        {
            if (scoreA[ballerofmatchA][3] > scoreB[ballerofmatchB][3])
            {
                cout << "---------- BALLER OF THE MATCH IS-----------" << endl;
                cout << teamB[ballerofmatchB];
                strcpy(ballermatch, teamB[ballerofmatchB]);

                cout << endl;
            }
        }
        if (scoreA[ballerofmatchA][4] > scoreB[ballerofmatchB][4])
        {
            cout << "---------- BALLER OF THE MATCH IS---------------" << endl;
            cout << teamA[ballerofmatchA];
            strcpy(ballermatch, teamA[ballerofmatchA]);
            cout << endl;
        }
        else if (scoreA[ballerofmatchA][4] >= scoreB[ballerofmatchB][4])
        {
            if (scoreA[ballerofmatchA][3] < scoreB[ballerofmatchB][3])
            {
                cout << "---------- BALLER OF THE MATCH IS---------------" << endl;
                cout << teamA[ballerofmatchA];
                strcpy(ballermatch, teamA[ballerofmatchA]);
                cout << endl;
            }
        }
        cout << endl;
        cout << "Do you want to save match data on file" << endl;
        cout << "1.  Press A for YES" << endl;
        cout << "2.  Press B for NO  " << endl;
        cin >> press1;
        switch (press1)
        {
        case 'A':
        {
            ofstream savematch("matchdata.txt");

            // Check if the file stream object was created successfully
            if (!savematch.is_open())
            {
                cout << "Unable to open file." << endl;
                return 1;
            }

            // Write data to the file
            savematch << forfile << endl;
            savematch << batsman << endl;
            savematch << ballermatch << endl;

            // Close the file stream object
            savematch.close();

            cout << "Data written to file." << endl;
        }
        break;
        case 'B':
        {
            cout << "As you selected NO, your data has not been saved in file" << endl;
            cout << "Hope you enjoyed the game !!" << endl;
        }
        break;

        default:
        {
            cout << "wrong option has been selected" << endl;
        }
        }
    }

    else // team B bats first and then team A bats
    {
        int overcheck2, overcheck3;
        cout << "TEAM B WON THE TOSS" << endl;
        cout << endl;
        cout << "--------TEAM B will be batting--------" << endl;
        cout << endl;
        cout << "--------TEAM A will be balling-------- " << endl;
        cout << "-----------FIRST INNINGS OF THE MATCH----------------" << endl;
        for (int i = 1; i <= 2; i++) // total 20 overs to be played
        {
            overcheck2 = i;
            cout << "--------" << i << "th over is being played-------" << endl;
            if (count == 5)
            {
                baller--;
                count = 0;
            }
            for (int j = 1; j <= 5; j++) // loop for 4 balls per bowler, making last five players of team B ballers
            {

                cout << "-----------Players on the field--------- " << endl;

                cout << "Player number "
                     << "1" << endl;
                // printing the player names
                cout << teamB[playercharc1];
                cout << endl;

                cout << "Player number"
                     << "2" << endl;
                cout << teamB[playercharc2];
                cout << endl;

                cout << "BALLING TIME" << endl;
                cout << "ball number : " << j << endl;
                cout << teamA[baller];

                cout << " : Baller of the team B, ball : (press ENTER to ball a ball)" << endl;
                ball = _getch();
                if (ball == 13)
                {
                    baller_balls = rand() % 8 - 1;
                    ballsbowled++;
                }
                else
                {
                    cout << "WRONG KEY HAS BEEN PRESSED CANNOT PLAY FORWARD" << endl;
                    cout << "start the game again.... :(" << endl;
                    return 0;
                }

                cout << "currently batting player :" << endl;
                int index;
                index = batsmanorderB[player1];

                cout << teamB[player1];

                cout << endl;
                int bated = 0;
                cout << "enter to bat " << endl;
                ball = _getch();
                if (ball == 13)
                {
                    bated = rand() % 7;
                }
                runsgiven = bated;
                bowlingboard(baller, ballsbowled, runsgiven);
                ballsbowled = 0;

                if (baller_balls != -1)
                {
                    cout << "score :" << bated << endl;
                    scoreb += bated;
                    runsgiven = bated;
                    runsscoredB = bated;
                    ballsfacedB++;
                    battingboardB(player1, runsscoredB, ballsfacedB);
                    ballsfacedB = 0;
                    if (bated % 2 != 0)
                    {
                        int temp;
                        temp = index1;
                        index1 = index2;
                        index2 = temp;
                        player1 = batsmanorderB[index1];
                        player2 = batsmanorderB[index2];
                        playercharc1 = player1;
                        playercharc2 = player2;
                    }
                }
                else if (baller_balls == -1)
                {
                    int outplayer;
                    outplayer = index;
                    ++fall;
                    fallsofwicketA(baller, fall);

                    fall = 0;
                    cout << "PLAYER OUT " << endl;
                    cout << "player got out during the " << overcheck2 << " over" << endl;
                    cout << "------------scoreboard of the player------------------" << endl;
                    cout << endl;
                    for (int i = 0; i < 3; i++)
                    {
                        cout << scorecategories[i] << "     ";
                    }
                    cout << endl;

                    for (int j = 0; j < 20; j++)
                    {
                        cout << teamB[player1][j];
                    }
                    cout << "    ";
                    for (int i = 0; i < 2; i++)
                    {
                        cout << scoreB[player1][i] << "              ";
                    }
                    cout << endl;
                    // deleting the currently player index that got out from the batsman order array
                    for (int i = index1; i <= (totalplayersbatting); i++)
                    {
                        batsmanorderB[i] = batsmanorderB[i + 1];
                    }
                    totalplayersbatting--;

                    cout << endl;
                    if (totalplayersbatting > 1)
                    {

                        player1 = batsmanorderB[0];
                        while (player1 == player2)
                        {
                            player1 = batsmanorderB[1];
                        }
                        playercharc1 = player1;
                    }
                    else
                    {
                        cout << " no PAIR of players left thus match ended for team A" << endl;
                        goto inningss;
                    }
                }
            }
            count++;
            overs++;
            overbowledA(baller, overs);
            overs = 0;
            int temp1;
            temp1 = index1;
            index1 = index2;
            index2 = temp1;
            player1 = batsmanorderB[index1];
            player2 = batsmanorderB[index2];
            playercharc1 = player1;
            playercharc2 = player2;
        }
        cout << endl;
        cout << endl;
        // check...
    inningss:
        cout << "----------SCOREBOARD OF 1ST INNINGS-------------" << endl;
        cout << "          ------BATTING TEAM B ------" << endl;
        for (int i = 0; i < 3; i++) // prints the categories
        {
            cout << "    " << scorecategories[i];
        }
        cout << endl;
        for (int i = 0; i < 7; i++) // prints the names and scores
        {
            cout << setw(10) << teamB[i];
            for (int j = 0; j < 2; j++)
            {
                cout << setw(10) << scoreB[i][j];
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;

        cout << "------------------TOTAL SCORE MADE BY TEAM B IN FIRST INNINGS IS ----------------------------:   " << scoreb << endl;
        cout << endl;
        cout << endl;
        cout << "          -----BALLING TEAM A-----" << endl;
        cout << "   "
             << "name";
        for (int i = 3; i < 7; i++) // category for team balling
        {
            cout << "    " << scorecategories[i];
        }
        cout << endl;
        for (int i = 0; i < 7; i++) // print names and scores respectively
        {
            cout << setw(10) << teamA[i];
            for (int j = 2; j < 6; j++)
            {
                cout << setw(10) << scoreA[i][j] << "    ";
                ;
            }
            cout << endl;
        }
        cout << endl;

        // FIRST INNING HAS BEEN ENDED

        // batting of team B and balling of team A
        int enter;
        cout << "Enter to start the batting of Team A " << endl;
        enter = getch();
        if (enter == 13)
        {
            cout << "LETS GO!!!!!!!!!!" << endl;
            cout << "-----------BATTING FOR TEAM A IS TAKING PLACE RIGHT NOWW---------" << endl;
        }
        srand(time(NULL));
        overs = 0;
        baller = 6;
        player1 = 0;
        player2 = 1;
        playercharc1 = 0;
        playercharc2 = 1;
        fall = 0;
        count = 0;
        total = 0;
        runsgiven = 0;
        ballsbowled = 0;
        index1 = 0;
        index2 = 1;
        player1 = batsmanorder[index1];
        player2 = batsmanorder[index2];
        int ballb;
        int totalplayersbatting1 = sizeof(batsmanorder) / sizeof(batsmanorder[0]);
        for (int i = 1; i <= 2; i++) // total 20 overs to be played and now team B is batting
        {
            overcheck3 = i;
            cout << "--------" << i << "th over is being played-------" << endl;
            if (count == 5)
            {
                baller--;
                count = 0;
            }

            for (int j = 1; j <= 5; j++) // loop for 4 balls per bowler, making last five players of team B ballers
            {
                if (score > scoreb)
                {
                    cout << "TEAM SCORED CROSS THE SCORE OF THE OPPONENT, MATCH FINISHES" << endl;
                    goto innings111;
                }

                cout << "-----------Players on the field--------- " << endl;

                cout << "Player number "
                     << "1" << endl;
                // printing the player names team b player
                cout << teamA[playercharc1];
                cout << endl;

                cout << "Player number"
                     << "2" << endl;

                cout << teamA[playercharc2];
                cout << endl;

                cout << "BALLING TIME" << endl;
                cout << "ball number : " << j << endl;
                int baller_ballss;
                // specifies the baller name who is balling

                cout << teamB[baller];
                cout << " : Baller of the team B, ball : (press ENTER to ball a ball)" << endl;
                ballb = getch();
                if (ballb == 13)
                {
                    BALLER_BALLS = rand() % 8 - 1;
                    ballsbowled++;
                }
                else
                {
                    cout << "WRONG KEY HAS BEEN PRESSED CANNOT PLAY FORWARD" << endl;
                    cout << "start the game again.... :(" << endl;
                    return 0;
                }

                cout << "currently batting player :" << endl;
                int index;
                index = batsmanorder[player1];
                cout << teamA[player1];
                cout << endl;
                int batedd;
                cout << "enter to bat " << endl;
                ball = _getch();
                if (ball == 13)
                {
                    batedd = rand() % 7;
                }
                runsgiven = batedd;
                bowlingboardB(baller, ballsbowled, runsgiven);
                ballsbowled = 0;
                if (BALLER_BALLS != -1)
                {
                    cout << "score :" << batedd << endl;
                    score += batedd;
                    runsscoredA = batedd;
                    ballsfacedA++;
                    battingboard(player1, runsscoredA, ballsfacedA);
                    ballsfacedA = 0;
                    if (batedd % 2 != 0)
                    {

                        int temp3;
                        temp3 = index1;
                        index1 = index2;
                        index2 = temp3;
                        player1 = batsmanorder[index1];
                        player2 = batsmanorder[index2];
                        playercharc1 = player1;
                        playercharc2 = player2;
                    }
                }
                else if (BALLER_BALLS == -1)
                {
                    int outplayer;
                    outplayer = index;
                    ++fall;
                    fallsofwicketB(baller, fall);
                    fall = 0;
                    cout << "PLAYER OUT " << endl;
                    cout << "player got out during the " << overcheck3 << " over" << endl;
                    cout << "------------scoreboard of the player------------------" << endl;
                    cout << endl;
                    for (int i = 0; i < 3; i++)
                    {
                        cout << scorecategories[i] << "     ";
                    }
                    cout << endl;

                    for (int j = 0; j < 20; j++)
                    {
                        cout << teamA[player1][j];
                    }
                    cout << "    ";
                    for (int i = 0; i < 2; i++)
                    {
                        cout << scoreA[player1][i] << "              ";
                    }

                    for (int i = index1; i <= (totalplayersbatting1); i++)
                    {
                        batsmanorder[i] = batsmanorder[i + 1];
                    }
                    totalplayersbatting1--;

                    cout << endl;
                    if (totalplayersbatting1 > 1)
                    {

                        player1 = batsmanorder[0];
                        while (player1 == player2)
                        {
                            player1 = batsmanorder[1];
                        }
                        playercharc1 = player1;
                    }
                    else
                    {
                        cout << " no PAIR of players left thus match ended for team A" << endl;
                        goto innings111;
                    }
                }
            }
            count++;
            overs++;
            overbowledB(baller, overs);
            overs = 0;
            int temp2;
            temp2 = index1;
            index1 = index2;
            index2 = temp2;
            player1 = batsmanorder[index1];
            player2 = batsmanorder[index2];
            playercharc1 = player1;
            playercharc2 = player2;
        }
        cout << endl;

    innings111:
        // ADD SECOND INNINGS SCOREBOARD
        cout << "----------SCOREBOARD OF 2ND INNINGS-------------" << endl;
        cout << "          ------BATTING TEAM A ------" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "    " << scorecategories[i];
        }
        cout << endl;
        for (int i = 0; i < 7; i++)
        {
            cout << setw(10) << teamA[i];
            for (int j = 0; j < 2; j++)
            {
                cout << setw(10) << scoreA[i][j];
            }
            cout << endl;
        }
        cout << "------------------  the total score of team A is -------------- " << score << endl;
        cout << endl;
        cout << "          -----BALLING TEAM B-----" << endl;
        cout << "    "
             << "name";
        for (int i = 3; i < 7; i++)
        {
            cout << "    " << scorecategories[i];
        }
        cout << endl;
        for (int i = 0; i < 7; i++)
        {
            cout << setw(10) << teamB[i];
            for (int j = 2; j < 6; j++)
            {
                cout << setw(10) << scoreB[i][j] << "    ";
            }
            cout << endl;
        }
        cout << endl;
        cout << "Do you want to see match summary???? Press enter if yes and A if no." << endl;
        enter1 = _getch();
        if (enter1 == 13)
        {
            updatescoreboard();
        }
        else if (enter1 == 65)
        {
            cout << "got it!! not showing you the summary" << endl;
        }
        cout << endl;
        // final decalarations
        if (scoreb < score)
        {
            cout << teammA << endl;
            strcpy(forfile, teammA);
        }
        else if (scoreb > score)
        {
            cout << teammB << endl;
            strcpy(forfile, teammB);
        }
        else
        {
            cout << draw << endl;
            strcpy(forfile, draw);
        }

        for (int i = 0; i < 7; i++)
        {
            if (scoreA[i][0] > max)
            {
                max = scoreA[i][0];
                batsmanofmatchA = i;
            }
        }
        for (int i = 3; i < 7; i++)
        {
            if (scoreA[i][4] > maxA)
            {
                maxA = scoreA[i][4];
                ballerofmatchA = i;
            }
        }
        for (int i = 0; i < 7; i++)
        {
            if (scoreB[i][0] > maxB)
            {
                maxB = scoreB[i][0];
                batsmanofmatchB = i;
            }
        }
        for (int i = 3; i < 7; i++)
        {
            if (scoreB[i][4] > maxBB)
            {
                maxBB = scoreB[i][4];
                ballerofmatchB = i;
            }
        }
        if (scoreA[batsmanofmatchA][0] < scoreB[batsmanofmatchB][0])
        {
            cout << "---------- BATSMAN OF THE MATCH IS---------------" << endl;
            cout << teamB[batsmanofmatchB];
            strcpy(batsman, teamB[batsmanofmatchB]);
            cout << endl;
        }
        else
        {
            cout << "---------- BATSMAN OF THE MATCH IS---------------" << endl;
            cout << teamA[batsmanofmatchA];
            strcpy(batsman, teamA[batsmanofmatchA]);
            cout << endl;
        }
        cout << endl;
        if (scoreA[ballerofmatchA][4] < scoreB[ballerofmatchB][4])
        {

            cout << "---------- BALLER OF THE MATCH IS-----------" << endl;
            cout << teamB[ballerofmatchB];
            strcpy(ballermatch, teamB[ballerofmatchB]);

            cout << endl;
        }
        else if (scoreA[ballerofmatchA][4] <= scoreB[ballerofmatchB][4])
        {
            if (scoreA[ballerofmatchA][3] > scoreB[ballerofmatchB][3])
            {
                cout << "---------- BALLER OF THE MATCH IS-----------" << endl;
                cout << teamB[ballerofmatchB];
                strcpy(ballermatch, teamB[ballerofmatchB]);

                cout << endl;
            }
        }
        if (scoreA[ballerofmatchA][4] > scoreB[ballerofmatchB][4])
        {
            cout << "---------- BALLER OF THE MATCH IS---------------" << endl;
            cout << teamA[ballerofmatchA];
            strcpy(ballermatch, teamA[ballerofmatchA]);
            cout << endl;
        }
        else if (scoreA[ballerofmatchA][4] >= scoreB[ballerofmatchB][4])
        {
            if (scoreA[ballerofmatchA][3] < scoreB[ballerofmatchB][3])
            {
                cout << "---------- BALLER OF THE MATCH IS---------------" << endl;
                cout << teamA[ballerofmatchA];
                strcpy(ballermatch, teamA[ballerofmatchA]);
                cout << endl;
            }
        }
        cout << endl;
        cout << "Do you want to save match data on file" << endl;
        cout << "1.  Press A for YES" << endl;
        cout << "2.  Press B for NO  " << endl;
        cin >> press1;
        switch (press1)
        {
        case 'A':
        {
            ofstream savematch("matchdata.txt");

            // Check if the file stream object was created successfully
            if (!savematch.is_open())
            {
                cout << "Unable to open file." << endl;
                return 1;
            }

            // Write data to the file
            savematch << forfile << endl;
            savematch << batsman << endl;
            savematch << ballermatch << endl;

            // Close the file stream object
            savematch.close();

            cout << "Data written to file." << endl;
            cout << "Hope you enjoyed the game !!" << endl;
        }
        break;
        case 'B':
        {
            cout << "As you selected NO, your data has not been saved in file" << endl;
            cout << "Hope you enjoyed the game !!" << endl;
        }
        break;

        default:
        {
            cout << "wrong option has been selected" << endl;
        }
        break;
        }
    }

    system("pause");
    return 0;
}
