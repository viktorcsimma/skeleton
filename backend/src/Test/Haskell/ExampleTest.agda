-- Tests with the QuickCheck Haskell library.
-- Here, you can finely integrate Agda code
-- with the functions and random generators of QuickCheck.

-- You can run these tests through `cabal test`.

{-# OPTIONS --erasure #-}
module Test.Haskell.ExampleTest where
{-# FOREIGN AGDA2HS {-# LANGUAGE StandaloneDeriving #-} #-}

-- for some reason, ⊤ and tt are needed for literals to work
open import Agda.Builtin.Unit

-- also for literals:
open import Agda.Builtin.FromString

open import Agda.Builtin.Bool
open import Haskell.Prim.String
open import Haskell.Prim.Eq

open import Logic

{-# FOREIGN AGDA2HS
import Test.QuickCheck
#-}

{-
Here, feel free to define Arbitrary instances
and use them in functions.
E.g. an Int -> Int -> Bool
is run with two randomly generated integers
as parameters several times.

Now, we just have a parameterless test.
-}

-- Actually, we can write the functions themselves in Agda.
prop_exampleFunctionIsCorrect : Bool
prop_exampleFunctionIsCorrect = "hello world" == exampleFunction
{-# COMPILE AGDA2HS prop_exampleFunctionIsCorrect #-}


{-# FOREIGN AGDA2HS
-- This contains all the propositions we would like to test.
-- Actually, this will be called by main
-- in TestMain.hs.
exampleTestAll :: IO Bool
exampleTestAll =
  and <$> mapM (isSuccess <$>)
  [ quickCheckResult prop_exampleFunctionIsCorrect
  ]
#-}

