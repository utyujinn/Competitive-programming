main :: IO()
main = do
  print =<< getLine
  as<-map(read::String->Int) . words <$> getLine
  putStrLn $ if and $ zipWith (<) as (drop 1 as) then "Yes" else "No"
  -- as<-map(read::String->Int) . words <$> getLine
  --	 putStrLn $ if and $ zipWith (<) as (drop 1 as) then "Yes" else "No"
