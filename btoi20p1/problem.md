### Baltic Olympiad in Informatics: 2020 Day 1, Problem 1

Linda likes to change her hair color from time to time, and would be pleased if her boyfriend Archie would notice the difference between the previous and the new color. Archie always comments on Linda’s hair color if and only if he notices a difference—so Linda always knows whether Archie has spotted the difference or not.

There is a new hair dye series in the market where all available colors are numbered byintegers from ~1~ to ~N~ such that a smaller difference of the numerical values also means less visual difference. 

Linda assumes that for these series there should be some *critical color difference* ~C~ (~1\leq C\leq N~) for which Archie will notice color difference between the current color ~color_{new}~ and the previous color ~color_{prev}~ if ~|color_{new} − color_{prev} | \geq C~ and will not if ~|color_{new} − color_{prev} | < C~.

Now she has bought ~N~ sets of hair dye from the new series—one for each of the colors from ~1~ to ~N~, and is ready to set up an experiment. Linda will change her hair color on a regular basis and will observe Archie’s reaction—whether he will notice the color change or not. Since for the proper dye each set should be used completely, each hair color can be obtained no more than once.

Before the experiment, Linda was using a dye from a different series which is not compatible with the new one, so for the clearness of the experiment Archie’s reaction to the first used color
is meaningless.

Her aim is to find the precise value of ~C~ in a limited number of dyes. Write a program which
finds the value of ~C~ by experimenting with the given ~N~ colors and observing Archie’s reactions
to color changes.

## Communication

This is an interactive task. At the beginning the input contains a single integer—the value of ~N~ (~1 < N \leq 10^{18}~). The value of ~C~ is kept secret by the grading system. Then your program should make queries writing output in the following format: `? P `, where ~P~ is an integer (~1\leq P\leq N~) denoting the next color used. For each query the grading system gives an answer in the next line of the input. The answer is ~1~ if Archie notices the color difference between the last two colors and ~0~ otherwise. No two queries should have the same ~P~ value.

When your program determines ~C~, it should output its value in the following format: `= C` and stop the execution. The grading system will not respond to this output and will not accept further queries.

## Notes

It is possible to receive an `Output isn’t correct` outcome even after printing a correct answer, if task constraints were violated during the communication. Violating the communication protocol itself may result in an `Execution killed` outcome.

## Example

<table class="table" style="max-width:60%">
<tr>
 <th>Input</th>
 <th>Output</th>
 <th>Comments</th>
</tr>
<tr>
 <td>`7`</td>
 <td></td>
 <td>~N = 7~</td>
</tr>
<tr>
 <td></td>
 <td>`? 2`</td>
 <td></td>
</tr>
<tr>
 <td>`1`</td>
 <td></td>
 <td>Answer to the first query is meaningless (can also be 0)</td>
</tr>
<tr>
 <td></td>
 <td>`? 7`</td>
 <td></td>
</tr>
<tr>
 <td>`1`</td>
 <td></td>
 <td>~C\leq 5~</td>
</tr>
<tr>
 <td></td>
 <td>`? 4`</td>
 <td></td>
</tr>
<tr>
 <td>`0`</td>
 <td></td>
 <td>~3 < C \leq 5 \dagger~</td>
</tr>
<tr>
 <td></td>
 <td>`? 1`</td>
 <td></td>
</tr>
<tr>
 <td>`0`</td>
 <td></td>
 <td>~3 < C\leq 5~</td>
</tr>
<tr>
 <td></td>
 <td>`? 5`</td>
 <td></td>
</tr>
<tr>
 <td>`1`</td>
 <td></td>
 <td>~3 < C\leq 4~. Therefore, ~C = 4~.</td>
</tr>
<tr>
 <td></td>
 <td>`= 4`</td>
 <td></td>
</tr>
</table>

~\dagger~ It would be wise to check difference 4. However, this can not be done in the next query
since ~4 + 4 = 8~ and ~4 − 4 = 0~ both are outside the allowed interval ~1\leq P\leq 7~.

## Grading

Your program may use at most ~64~ queries `?` to find the correct value of ~C~.
Subtasks:
1. (~9~ points) ~N ≤ 64~
2. (~13~ points) ~N ≤ 125~
3. (~21~ points) ~N ≤ 1000~
4. (~24~ points) ~N ≤ 10^9~
5. (~33~ points) No further constraints

Note: The official data contains 1256 test cases in total. Grading submissions may take some time.
Note 2: Time limit has been reduced from 0.3s to 0.1s.