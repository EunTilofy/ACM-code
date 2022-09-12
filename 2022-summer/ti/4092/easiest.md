Given a comma-separated table with $n$ rows and $m$ columns, your task is to plot the table as a bordered table and output it as text.

The output requirements are as follows:

+ The output is a character matrix containing $n+1$ horizontal lines and $m+1$ vertical lines, where the first and last rows are horizontal lines and the first and last columns are vertical lines;
+ The position on the horizontal line is \t{-} (ASCII code 45), the position on the vertical line is \t{|} (ASCII code 124), the position where the horizontal line and the vertical line intersect is \t{+} (ASCII code 43);
+ Every two horizontal lines are separated by exactly one line;
+ The contents of the cells in row $i$ and column $j$ in the table should be completely filled in the area enclosed by the $i-th$ horizontal line, the $i+1-th$ horizontal line, the $j-th$ vertical line, and the $j+1-th$ vertical line. The length of the cell content is smaller than the interval between the two vertical lines, and spaces should be added to the left and right sides of the content.

Here, we require the content of each column to be aligned in a given way. Given a string $s$ of length $m$ and only contains \t{L} (ASCII code 76), \t{C} (ASCII code 67), \t{R} (ASCII code 82), and use $s_i$ to represent the $i-th$ character of $s$, then:

+ If $s_i=$ \t{L}, then the $i-th$ column is left-aligned, that is, there can be no spaces on the left side of each cell;
+ If $s_i=$ \t{R}, then the $i-th$ column is right-aligned, that is, there can be no spaces on the right side of each cell;
+ If $s_i=$ \t{C}, the $i-th$ column is centered, that is, each cell has the same number of spaces on the left and right sides, or one more space on the right side than on the left side.

On this basis, you should make the width of the output table as small as possible.

Please output the table that meets the conditions.