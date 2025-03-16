import Control.Monad
cntfor::[String]->Int
cntfor [] = 0
cntfor (x:xs)  
  | x=="For"  = 1+cntfor xs
  | otherwise = cntfor xs

solve::[String]->Bool
solve xs =
  cntfor xs > length xs `div` 2

main::IO()
main = 
  readLn >>= \n ->
  replicateM n getLine >>= \xs ->
  putStrLn $ if solve xs then "Yes" else "No"
