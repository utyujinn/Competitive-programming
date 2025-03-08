import Control.Monad
sort :: [String] -> [String]
sort [] = []
sort (n:xs) = sort lt++[n]++sort gteq
  where
    lt = [x | x<-xs, length x < length n]
    gteq = [x | x<-xs, length x >= length n]

main = do
  n <- readLn
  ss <- replicateM n getLine
  let ss'= sort ss
  -- print ss'
  putStrLn $ foldl (++) "" ss'
