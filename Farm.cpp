#include "Farm.h"
#include <iostream>

using namespace std;

Farm::Farm(){
    name = "Farm";
    location = "Adelaide";
    balance = 0;
    dayNum = 0;
    // bellPeppersHarvastCount = 0;
    // onionHarvastCount = 0;
    // carrotHarvastCount = 0;
    // wheatHarvastCount = 0;
    // cornHarvastCount = 0;
    // cherryHarvastCount = 0;
    // appleHarvastCount = 0;
    numPlots = 0;
    maxNumPlots = 5;
    plots = new Plot*[maxNumPlots];
}

Farm::Farm(string name, string location){
    this->name = name;
    this->location = location; 
    balance = 1;
    dayNum = 0;
    // bellPeppersHarvastCount = 0;
    // onionHarvastCount = 0;
    // carrotHarvastCount = 0;
    // wheatHarvastCount = 0;
    // cornHarvastCount = 0;
    // cherryHarvastCount = 0;
    // appleHarvastCount = 0;
    numPlots = 0;
    maxNumPlots = 5;
    plots = new Plot*[maxNumPlots];
}

void Farm::newDay(){
    dayNum += 1;
    //write something!
}

void Farm::addPlot(Plot* plot){
    if (numPlots < maxNumPlots){
        plots[numPlots] = plot;
        numPlots++;
    }else{
        cout << "The farm is full" << endl;
        return;
    }
}

void Farm::addToBalance(int amount){
    balance += amount;
}

void Farm::removeFromBalance(int amount){
    balance -= amount;
}

Plot* Farm::getAvailablePlot(){
    for (int i = 0; i < numPlots; i++){
        if (!plots[i]->hasCrop()){
            return plots[i];
        }
    }
    return nullptr;
}

Plot* Farm::getPlot(int index){
    if (index >= 0 && index < numPlots) {
        return plots[index];
    } else {
        return nullptr; // Return nullptr if index is out of bounds
    }
}

float Farm::getBalance(){
    return balance;
}

int Farm::getDayNum(){
    return dayNum;
}

int Farm::getNumPlots(){
    return numPlots;
}