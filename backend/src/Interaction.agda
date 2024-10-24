-- A file which contains
-- most of the interface of the application
-- to the C++ side.
{-# OPTIONS --erasure #-}

module Interaction where

import Logic

{-# FOREIGN AGDA2HS

{-# LANGUAGE ForeignFunctionInterface, ScopedTypeVariables #-}

import Prelude hiding (Rational)

import Data.IORef
import Foreign.C.String
import Foreign.C.Types
import Foreign.StablePtr
import Foreign.Ptr

import Logic
import AppState
import Platform

import Control.Concurrent
#-}

{-# FOREIGN AGDA2HS
-- Initialises the application state and returns a StablePtr for the C side.
-- From there, we can reach the actual state of the application from there.
-- Required type constraints have to be provided here, too.
initApp :: IO (StablePtr AppState)
initApp = newStablePtr MkAppState
-- If AppState has type variables, you have to provide concrete instantiations;
-- only those can be exported.
foreign export ccall initApp :: IO (StablePtr AppState)

-- An example interaction that can be triggered from C.
exampleInteraction :: StablePtr AppState -> IO CString
exampleInteraction ptr = do
  appState <- deRefStablePtr ptr
  -- We call on a function operating on Haskell types.
  hsString <- exampleInteraction' appState
  -- And we return the result in a C format.
  -- Beware: C strings have to be freed on the client side!
  newCString hsString
foreign export ccall exampleInteraction :: StablePtr AppState -> IO CString

-- The Haskell code behind exampleInteraction.
-- This will eventually call the Agda side.
exampleInteraction' :: AppState -> IO String
exampleInteraction' appState = do
  -- interacting with the appState...
  -- return exampleFunction
  show <$> myThreadId

-- Frees the StablePtr pointing to the AppState instance.
-- Should be called before the application finishes.
destructApp :: StablePtr AppState -> IO ()
destructApp = freeStablePtr
foreign export ccall destructApp :: StablePtr AppState -> IO ()
#-}
