f::Int->Int->Int
f x y = x*x*x-y*y*y

nibun::Int->Int->Int->Int->Int
nibun n diff down up
  | up-down==1 = down
  | (f x y)<=n = nibun n mid up 
  | otherwise = nibun n down up
  where
    mid = (down+up)/2
    x = mid+diff
    y = mid 
  
solve::Int->IO Int
solve n = do
  forM [1..1000000] $ \diff -> do
    (nibun n diff 1 1000000) >>= \down ->
    if f x y==n then return (x y) else nop
    where
      x = down+diff
      y = down

main::IO()
main = 
  readLn >>= \n ->
  print =<< solve n
