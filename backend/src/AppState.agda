-- A data type which will contain
-- the variables of the application
-- in a mutable form.
-- A pointer to it will be passed to C++.
-- This is actually written in Haskell.
{-# OPTIONS --erasure --guardedness #-}

module AppState where

open import Haskell.Data.IORef

-- This has to be mutable,
-- because the C++ side will have a pointer
-- to the same instance
-- all the time.
-- That's why I cannot comfortably use
-- the State monad.

-- Here, add every variable you would like to persist
-- throughout the lifetime of your application,
-- within an IORef.
-- You can also add type variables.
record AppState : Set where
  -- field
    -- sampleMember : IORef a
{-# COMPILE AGDA2HS AppState #-}
