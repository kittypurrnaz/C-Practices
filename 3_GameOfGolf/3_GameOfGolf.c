
/******************************************************************************

PART B: ASSIGNMENT

*******************************************************************************/
#include <stdio.h>

#define rounds 2
#define holes 9

int main()
{
    // declare and initialise working storage
    // hold user input
    char playerName[50];
    int round1 = 0;
    int round2 = 0;
    int assignedScores[rounds][holes] = {{3, 4, 4, 5, 4, 3, 4, 4, 5}, {5, 4, 4, 3, 4, 4, 5, 3, 4}};
    int counter = 0;
    int counter2 = 0;
    int lessAssigned[rounds][holes];
    int similarAssigned[rounds][holes];
    int lessAssignedCount[rounds] = {0};
    int similarAssignedCount[rounds] = {0};
    int roundScores[rounds][holes];
    int totalScores[rounds] = {0};
    int round1Total = 0;
    int round2Total = 0;
    float avgScore = 0;
    
    // prompt the user to enter name
    printf("\nEnter player's name : ");
    scanf("%s", playerName);
    printf("\n");
    printf("=============================\n");
    
    // Prompt the scorer to input the scores for the 2 rounds
    for(counter = 0; counter < rounds; counter++)
    {
        printf("\nEnter the scores for round %d \n\n", counter + 1);
        for(counter2 = 0; counter2 < holes; counter2++)
        {
            printf("Hole %d : ", counter2 + 1);
            scanf("%d", &roundScores[counter][counter2]);
            if(roundScores[counter][counter2] < assignedScores[counter][counter2])
            {
                lessAssigned[counter][lessAssignedCount[counter]++] = counter2 + 1;
            }
            else if(roundScores[counter][counter2] == assignedScores[counter][counter2])
            {
                similarAssigned[counter][similarAssignedCount[counter]++] = counter2 + 1;
            }
        }
        
        // Compute the total score for each round.
        totalScores[counter] = 0;
        for (counter2 = 0; counter2 < holes; counter2++) 
        {
            totalScores[counter] += roundScores[counter][counter2];
        }
        // Compute and display the total score of each rounds
        printf("\nTotal score for round %d: %d \n\n", counter + 1, totalScores[counter]);
        printf("=============================\n");
    }
    
    // compute and print the average score for both rounds (18 holes)
    
    for(int counter = 0; counter < rounds; counter++) 
    {
        for(int counter2 = 0; counter2 < holes; counter2++) 
        {
            round1Total += assignedScores[counter][counter2];
            
        }

        printf("\nPlayer: %s\n", playerName);
        printf("\nRound 1\n");
        printf("Hole\tAssigned score\tPlayer score\n");
        for (counter = 0; counter < holes; counter++) 
        {
            printf("%d\t%d\t\t%d\n", counter + 1, assignedScores[0][counter], roundScores[0][counter]);
        }
        printf("\nRound 2\n");
        printf("Hole\tAssigned score\tPlayer score\n");
        for (counter = 0; counter < holes; counter++) 
        {
            printf("%d\t%d\t\t%d\n", counter + 1, assignedScores[1][counter], roundScores[0][counter]);
        }
        printf("\n=============================\n");
        printf("\nHoles in which the player scored less than the assigned score: \n\n");
        printf("Round 1 : ");
        for (counter = 0; counter < lessAssignedCount[0]; counter++) 
        {
            printf("%d ", lessAssigned[0][counter]);
        }
        printf("\nRound 2 : ");
        for (counter = 0; counter < lessAssignedCount[0]; counter++) 
        {
            printf("%d ", lessAssigned[1][counter]);
        }
        
        printf("\n\nHoles in which the player scored the same as  the assigned score: \n");
        printf("\nRound 1 : ");
        for (counter = 0; counter == similarAssignedCount[0]; counter++) 
        {
            printf("%d ", similarAssigned[0][counter]);
        }
        printf("\nRound 2 : ");
        for (counter = 0; counter == similarAssignedCount[0]; counter++) 
        {
            printf("%d ", similarAssigned[1][counter]);
        }
    
        printf("\n\nThe total score for each round is: \n");
        printf("\nRound 1 : %d ",totalScores[counter]);
        printf("\nRound 2 : %d ",totalScores[counter2]);
        
        avgScore = (float)(totalScores[0] + totalScores[1]) / (rounds * holes);
        printf("\n\nThe average score for for both rounds is: %.2f \n", avgScore);

    }
    return 0;
}
