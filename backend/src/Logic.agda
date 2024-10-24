-- This file can contain Agda logic
-- compiled with agda2hs.
-- But feel free to split logic into multiple files.
{-# OPTIONS --erasure #-}

module Logic where

open import Agda.Builtin.Unit
open import Agda.Builtin.FromString
open import Haskell.Prim.String

exampleFunction : String
exampleFunction = "hello world"
{-# COMPILE AGDA2HS exampleFunction #-}

