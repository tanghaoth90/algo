import Control.Monad
import Data.List
import Data.Ord
import Data.String

subpair t = isInfixOf (fst t) (snd t)

main = do
  fline <- getLine
  let n = read fline::Int
  strs <- replicateM n getLine
  let sstrs = sortBy (comparing length) strs
  let pstrs = zip (take (n-1) sstrs) (tail sstrs)
  let judge = foldl (&&) True $ map subpair pstrs
  if judge 
    then do putStrLn "YES";
	        mapM_ putStrLn sstrs
    else do putStrLn "NO"
  
  