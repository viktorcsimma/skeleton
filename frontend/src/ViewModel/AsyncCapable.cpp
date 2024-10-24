#include "Acorn.h"
#include "ViewModel/AsyncCapable.hpp"

#include <mutex>

AsyncCapable::AsyncCapable():
    // an std::thread with an empty constructor does not really represent a thread
    evaluationThread(), evaluating(false) {}

bool AsyncCapable::interruptEvaluation() {
    // todo: make this atomic if possible
    if (evaluating) {
        // this is defined in Acorn.h
        acornInterruptEvaluation();
        // let's join it; that is safer
        // hopefully, it ends quickly
        evaluationThread.join();

        evaluating = false;
        return true;
    } else return false;
}

AsyncCapable::~AsyncCapable() {
    // todo: make this atomic if possible
    if (evaluating) interruptEvaluation();
    else if (evaluationThread.joinable()) evaluationThread.detach(); // we have to join or detach it before destruction
}
