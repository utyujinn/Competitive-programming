import Data.Char
main = do
  [s1,s2] <- words <$> getLine
  case s1 s2 of
    s1=="sick",s2=="sick" = pri
