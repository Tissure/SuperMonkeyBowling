// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoringAPI.h"

int UScoringAPI::CalculateScore(float timeTaken, float timeMin, int pinsKnocked) {
    float diff = timeMin - timeTaken;
    float score = diff * pinsKnocked; //scaled
    return score;
}
