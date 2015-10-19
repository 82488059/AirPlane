#pragma once

#include "SingletonT.h"

class SelectedLevelManager
{
public:
    SelectedLevelManager();
    ~SelectedLevelManager();

private:

};

typedef SingletonT<SelectedLevelManager> CSelectedLevelManager;

#define  GetSelectedLevelManager CSelectedLevelManager::GetInstance 


