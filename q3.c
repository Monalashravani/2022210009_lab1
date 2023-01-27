#include <stdio.h>
#include <string.h>

typedef struct MatchDetails {
    int runsScored;
    int ballsPlayed;
} match;

typedef struct PlayerDetails {
    char name[20];
    match matchDetails[10];
} player;

typedef struct TeamDetails {
    char name[20];
    player players[11];
} team;

void fillDetails(team *t, int playerId, char name[], int r, int b, int matchNum) {
    strcpy(t->players[playerId].name, name);
    strcpy(t->players[1].name,"Rohit Sharma");
    strcpy(t->players[2].name,"Virat Kohli");
    t->players[1].matchDetails[1].runsScored=4;
    t->players[1].matchDetails[1].ballsPlayed=7;
    // t->players[1].matchNum=1;
    t->players[2].matchDetails[1].runsScored=82;
    t->players[2].matchDetails[1].ballsPlayed=53;
    // t->players[2].matchNum=1;
    t->players[1].matchDetails[2].runsScored=53;
    t->players[1].matchDetails[2].ballsPlayed=39;
    // t->players[1].matchNum=2;
    t->players[2].matchDetails[2].runsScored=62;
    t->players[2].matchDetails[2].ballsPlayed=44;
    // t->players[2].matchNum=2;
}

void printAvg(player p[]) {
    for (int i = 1; i <= 2; i++) {
        float avg = 0;
        for (int j = 1; j <= 2; j++) {
            avg=p[i].matchDetails[j].runsScored+avg;
        }
        printf("%s\t",p[i].name);
        printf("%0.2f\n",avg/2);
    }
}

int main() {
    team India;
    strcpy(India.name, "India");
    fillDetails(&India, 1, "Rohit Sharma", 4, 7, 1);
    fillDetails(&India, 2, "Virat Kohli", 82, 53, 1);
    fillDetails(&India, 1, "Rohit Sharma", 53, 39, 2);
    fillDetails(&India, 2, "Virat Kohli", 62, 44, 2);
    printAvg(India.players);
}