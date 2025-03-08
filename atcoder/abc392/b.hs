main = do
  [n,m] <- map read . words <$> getLine
  a <- map read . words <$> getLine
  let ans = solve n a
  print $ length ans
  putStrLn . unwords . map show $ ans

solve n a = [x | x <- [1..n], x `notElem` a]
