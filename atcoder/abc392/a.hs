import Data.List
main = do
  a <- map read . words <$> getLine :: IO [Int]
  let [x,y,z] = sort a
  putStrLn $ if x*y==z then "Yes" else "No"
