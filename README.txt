Zyra De Los Reyes
CS4280 Project 2

Notes:
	- tree and parser are merged in one file
	- Professor Janikow printed nodes on the tree even though its empty, so mines does something similar
	- if theres an error, my program just terminates
	- there test1-6.input1 are good programs, bad1-4.input1 are bad program
	- minor changes  were made to the BNF.
		- the ':' between <mStat> and <stat> are missing
			- I keep getting error from loop() in parser

BNF
<program>  ->     <vars> <block>
<block>    ->     Begin <vars> <stats> End
<vars>     ->     empty | INT Identifier Integer <vars> 
<expr>     ->     <A> + <expr> | <A> - <expr> | <A>
<A>        ->     <N> * <A> | <N>
<N>        ->     <M> / <N> | <M>
<M>        ->   - <M> |  <R>
<R>        ->   [ <expr> ] | Identifier | Integer
<stats>    ->     <stat>  <mStat>
<mStat>    ->      empty |  <stat> <mStat>
<stat>     ->     <in> | <out> | <block> | <if> | <loop> | <assign>
<in>       ->      Read [ Identifier ]  
<out>      ->      Output [ <expr> ]
<if>       ->      IFF [ <expr> <RO> <expr> ] <stat>
<loop>     ->      Loop [ <expr> <RO> <expr> ] <stat>
<assign>   ->      Identifier  = <expr>  
<RO>       ->     < | = <  | >  | = > | ==  |   =
