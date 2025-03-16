main::IO()
main=
  (readLn::IO Float)>>= \x ->
  print $ case x of
    _ | x < 37.5 -> 3::Int
    _ | x < 38.0 -> 2::Int
    _ -> 1::Int
