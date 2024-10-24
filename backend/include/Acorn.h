#ifndef ACORN_H_
#define ACORN_H_

#include "TinyHsFFI.h"
#if defined(__cplusplus)
extern "C" {
#endif

// from the FFI

// Initialises an AppState
// and returns a StablePtr to it.
extern HsStablePtr initApp(void);

// An example interaction.
extern char* exampleInteraction(HsStablePtr appState);

// Frees the StablePtr to the CalcState object,
// as this could not be done from the C side.
extern void destructApp(HsStablePtr calcState);

// This is written in src/acornInterruptEvaluation.c.
// It can be used to interrupt a running calculation
// by listening on the "/AcornInterruptSemaphore" POSIX semaphore (on Unix)
// or the "AcornInterruptEvent" event (on Windows).
extern void acornInterruptEvaluation();

#if defined(__cplusplus)
}
#endif

#endif
