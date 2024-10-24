-- A main program for a simple interpreter.
-- This is needed to be written in Haskell;
-- otherwise, Cabal does not accept it.
module Main where

import AppState
import Interaction

main :: IO ()
main = do
  let appState = MkAppState
  putStrLn =<< exampleInteraction' appState