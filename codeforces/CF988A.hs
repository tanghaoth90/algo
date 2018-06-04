import Data.Map (Map)
import Data.List
import qualified Data.Map as M
import Control.Monad

readInts :: IO [Int]
readInts = fmap (map read.words) getLine

getmsg k msize
  | msize >= k  = "YES"
  | otherwise   = "NO"

list_as_str :: [Int] -> String
list_as_str ilist = concat $ intersperse " " $ map show ilist
  
main = do
  nkline <- readInts
  numlist <- readInts
  let n = head nkline
  let k = last nkline
  let mp = M.fromList $ zip numlist [1..n]
  let msg = getmsg k $ M.size mp
  putStrLn msg
  when (msg == "YES") $ 
    do putStrLn $ list_as_str $ snd $ unzip $ take k $ M.toList mp
