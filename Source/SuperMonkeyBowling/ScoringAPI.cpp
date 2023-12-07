// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoringAPI.h"

int UScoringAPI::CalculateScore(float timeTaken, float timeMin, int pinsKnocked) {
    float diff = timeMin - timeTaken;
    float score = diff * pinsKnocked; //scaled
    return score;
}
