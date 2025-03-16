import qualified Data.ByteString.Char8 as BS
import Data.Char
import Data.List

import Data.Array

solve::Int->[Int]->Int
solve n as=base+bonus
  where
    ps = accumArray (flip (:)) [] (1,n) $ zip as [1 ..]
    base = length $ filter (not . null) $ elems ps
    arr = accumArray (+) 0 (1,n) $ concat [[(last is, 1), (head is, -1)] | is@(_:_:_) <- elems ps]
    bonus = maximum $ scanl (+) 0 $ elems arr

main::IO()
main=
  readLn >>= \n ->
  (map read.words <$> getLine::IO [Int]) >>= \as ->
  print $ solve n as

