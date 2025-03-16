import Control.Monad.ST
import Data.STRef

main :: IO ()
main = do
   let a = do
       b <- newSTRef 1
       modifySTRef b (+1)
       readSTRef b
   print $ runST a
