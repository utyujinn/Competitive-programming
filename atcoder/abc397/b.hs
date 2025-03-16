solve::String->Int
solve "" = 0
solve (c1:c2:st)
  | c1=='i' && c2=='o' = solve st 
  | otherwise = 1+solve (c2:st)
solve _ = 1
  
main::IO()
main=
  getLine >>= \s ->
  print $ solve s
