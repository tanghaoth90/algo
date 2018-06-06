import Data.List
import System.Random (randomRIO)
import Control.Monad (replicateM)

readInts :: String -> [Int]
readInts numline = map read $ words numline

listToStr :: [Int] -> String
listToStr lst = concat $ intersperse " " $ map show lst

randomList :: Int -> Int -> IO [Int]
randomList n m = replicateM n $ randomRIO(1,m)

inputFileName = "nums.in"
outputFileName = "nums.out"

gendata = do
    r <- randomList 1000000 1000000
    writeFile inputFileName $ listToStr r

-- quicksort implementation
quicksort [] = []
quicksort (p:xs) = (quicksort lesser) ++ [p] ++ (quicksort greater)
    where
        lesser = filter (< p) xs
        greater = filter (>= p) xs
    
main = do
    lst <- fmap readInts (readFile inputFileName)
    -- print $ head lst
    -- ** sorting (from Data.List) **
    -- writeFile outputFileName $ listToStr $ sort lst
    -- print $ length (sort lst)
    -- ** quicksort (implemented in this file) **
    -- writeFile outputFileName $ listToStr $ quicksort lst 
    -- print $ length (quicksort lst)
    print $ (sort lst) == (quicksort lst)
