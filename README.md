Tournament-Predictor
====================

Existing tournament predictors use a 2-bit saturating counter per branch to choose among two different
predictors based on which predictor (local, global, or even some mix) was most effective in recent 
predictions. As in a simple 2-bit predictor, the saturating counter requires two mispredictions before
changing the identity of the preferred predictor.  

The 21264’s tournament predictor uses 4K 2-bit counters indexed by the local branch address to choose 
from among a global predictor and a local predictor. The global predictor also has 4K entries and is 
indexed by the history of the last 12 branches; each entry in the global predictor is a standard 2-bit
predictor. 
The local predictor consists of a two-level predictor. The top level is a local history table consisting of 
1024 10-bit entries; each 10-bit entry corresponds to the most recent 10 branch outcomes for the entry. 
That is, if the branch was taken 10 or more times in a row, the entry in the local history table will be all 
1s. If the branch is alternatively taken and untaken, the history entry consists of alternating 0s and 1s. 
This 10-bit history allows patterns of up to 10 branches to be discovered and predicted. The selected 
entry from the local history table is used to index a table of 1K entries consisting of 3-bit saturating 
counters, which provide the local prediction. 
N of bits used = 1Kx10 +1Kx3+4Kx2+4Kx2 =29K 
