#ifndef ASYNC_CAPABLE_HPP_
#define ASYNC_CAPABLE_HPP_

#include <iostream>
#include <thread>

// An abstract class containing methods
// to call the Haskell backend interruptibly.
// Add this as a parent of HsCalcStateWrapper
// if you would like to have such calls.
class AsyncCapable {
  private:
    // The thread running the actual interruptible call
    // (if isEvaluating is false, it has either terminated or is invalid;
    // see joinable()).
    // Feel free to comment this out if you don't have asynchronous calls.
    std::thread evaluationThread;
    // Whether there is an asynchronous evaluation in progress.
    bool evaluating;

  protected:
    // Starts executing the given call on the thread stored in the class.
    // Sets isEvaluating() to true until finishing.
    template<class CalledFunction>
    void callAsync(CalledFunction toExecute) {
        // destructing a thread is not safe if it is joinable;
        // even if it has terminated
        if (evaluationThread.joinable()) evaluationThread.join();
        evaluating = true;
        std::cout << "main thread: " << std::this_thread::get_id() << '\n';
        evaluationThread = std::thread([=]() {
            std::cout << "evaluation thread: " << std::this_thread::get_id() << '\n';
            toExecute();
            evaluating = false;
        });
    }

  public:
    // Whether there is an asynchronous calculation running.
    bool isEvaluating() const {return evaluating;}

    // Sends a signal to the Haskell backend
    // by calling the appropriate method of the backend.
    // If you run your calculation there with `runInterruptibly`,
    // this interrupts the evaluation
    // and makes it return a default value provided.
    // If there is no calculation in progress on the thread included,
    // this returns false and does nothing.
    bool interruptEvaluation();

    ~AsyncCapable() {
        if (evaluationThread.joinable()) evaluationThread.join();
    }
};

#endif
