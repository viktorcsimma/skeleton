#include "ViewModel/HsAppStateWrapper.hpp"
#include "ViewModel/OddParameterException.hpp"
#include "Acorn.h"

HsAppStateWrapper::HsAppStateWrapper():
    AsyncCapable(), appStatePtr(initApp()) {}

std::string HsAppStateWrapper::exampleInteraction() {
    char* temp = ::exampleInteraction(appStatePtr);    // the one in Acorn.h
    std::string toReturn(temp); // this makes a copy
    free(temp);
    return toReturn;
}

HsAppStateWrapper::~HsAppStateWrapper() {
    // there is no guarantee that a StablePtr is anything meaningful,
    // so we have to free it from Haskell
    destructApp(appStatePtr);
}
