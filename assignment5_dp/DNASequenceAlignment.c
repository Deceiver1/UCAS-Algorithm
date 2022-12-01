#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001

int getMinScore(int score1, int score2, int score3);
void dnaSequenceAlignment(char dnaSequenceFirst[], char dnaSequenceSecond[]);
int getDNAIndex(char c);

char dnaSequenceFirst[MAX], dnaSequenceSecond[MAX];
int scores[MAX][MAX];
int dna_score_matrix[4][4] = {{0, 5, 5, 5},
                              {5, 0, 5, 5},
                              {5, 5, 0, 4},
                              {5, 5, 4, 0}};

int main()
{
    scanf("%s", dnaSequenceFirst);
    scanf("%s", dnaSequenceSecond);
    dnaSequenceAlignment(dnaSequenceFirst, dnaSequenceSecond);
    return 0;
}

void dnaSequenceAlignment(char dnaSequenceFirst[], char dnaSequenceSecond[])
{
    int index1, index2;
    int len1 = strlen(dnaSequenceFirst), len2 = strlen(dnaSequenceSecond);
    int i = 0, j = 0;
    scores[0][0] = 0;
    for (i = 1; i <= len1; i++)
        scores[0][i] = 3 + scores[0][i - 1];
    for (i = 1; i <= len2; i++)
        scores[i][0] = 3 + scores[i - 1][0];
    for (i = 1; i <= len2; i++)
        for (j = 1; j <= len1; j++)
        {
            index1 = 0, index2 = 0;
            int score1 = 0, score2 = 0, score3 = 0, final_score = 0;
            index1 = getDNAIndex(dnaSequenceSecond[i - 1]);
            index2 = getDNAIndex(dnaSequenceFirst[j - 1]);
            score1 = scores[i - 1][j - 1] + dna_score_matrix[index1][index2];
            score2 = scores[i - 1][j] + 3;
            score3 = scores[i][j - 1] + 3;
            final_score = getMinScore(score1, score2, score3);
            scores[i][j] = final_score;
        }
    printf("%d", scores[len2][len1]);
}

int getMinScore(int score1, int score2, int score3)
{
    if (score1 > score2)
    {
        return score2 > score3 ? score3 : score2;
    }
    return score1 > score3 ? score3 : score1;
}

int getDNAIndex(char c)
{
    switch(c)
    {
        case 'A':
            return 0;
        case 'T':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        default:
            return -1;
    }


}
