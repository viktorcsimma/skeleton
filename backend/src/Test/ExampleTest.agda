-- Some simple Agda tests for demonstration.
-- Feel free to add your own under this directory.

-- If added to All.agda,
-- the typechecker checks them at every compilation.
{-# OPTIONS --erasure #-}
module Test.ExampleTest where

open import Agda.Builtin.Equality

-- for some reason, ⊤ and tt are needed for literals to work
open import Agda.Builtin.Unit

-- also for literals:
open import Agda.Builtin.FromString
open import Haskell.Prim.String

open import Logic

exampleTest : "hello world" ≡ exampleFunction
exampleTest = refl
