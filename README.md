# 42'S SUBJECT GET_NEXT_LINE

<h2>MANDATORY PART</h2>
<br>

  **Program name** | <samp>get_next_line</samp> 
  -----------------|----------
  **Prototype** | <code>int get_next_line(int fd, char **line);</code>
  **Turn in files** | <samp>get_next_line.c, get_next_line_utils.c, get_next_line.h</samp>
  **Parameters** | #1.  file descriptor for reading<br>#2.  The value of what has been read
  **Return value** | <code>1</code> :  A line has been read<br><code>0</code> :  <code>EOF</code> has been reached<br><code>-1</code> :  An error happened
  **External functs.** | <code>read</code>, <code>malloc</code>, <code>free</code>
  **Description** | Write a function which returns a line read from a file descriptor, without the newline.
<br> 

- Calling your function <samp>get_next_line</samp> in a loop will then allow you to read the text available on a file descriptor one line at a time until the <code>EOF</code>.
- Make sure that your function behaves well when it reads from a file and when it reads from the standard input.
- <samp>libft</samp> is not allowed for this project. You must add a <samp>get_next_line_utils.c</samp> file which will contain the functions that are needed for your get_next_line to work.
- Your program must compile with the flag <samp>-D BUFFER_SIZE=xx</samp>. which will be used as the buffer size for the read calls in your get_next_line. This value will be modified by your evaluators and by moulinette.
- Compilation will be done this way : <samp>gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c</samp>
- Your read must use the <code>BUFFER_SIZE</code> defined during compilation to read from a file or from stdin.
- In the header file <samp>get_next_line.h</samp> you must have at least the prototype of the function <samp>get_next_line</samp>.

<br>

<samp><b>NOTE</b>: Does your function still work if the BUFFER_SIZE value is 9999? And if the BUFFER_SIZE value is 1?  And 10000000?  Do you know why?</samp>

<samp><b>NOTE</b>: You should try to read as little as possible each time get_next_line is called.  If you encounter a newline, you have to return the current line.  Don’t read the whole file and then process each line.</samp>

<samp><b>NOTE</b>: Don’t turn in your project without testing.  There are many tests to run, cover your bases. Try to read from a file, from a redirection, from standard input.  How does your program behave when you send a newline to the standard output? And CTRL-D?</samp>

<br>

- We consider that <samp>get_next_line</samp> has an undefined behavior if, between two calls, the same file descriptor switches to a different file before <code>EOF</code> has been reached on the first fd.
- <code>lseek</code> is not an allowed function. File reading must be done only once.
- Finally we consider that <samp>get_next_line</samp> has an undefined behavior when reading from a binary file. However, if you wish, you can make this behavior coherent.
- Global variables are forbidden.

<samp><b>HELP</b>: A good start would be to know what a static variable is.</samp>

<br>
<h2>BONUS PART</h2>
<br>

The project <samp>get_next_line</samp> is straightforward and leaves very little room for bonuses, but I am sure that you have a lot of imagination. If you aced perfectly the mandatory part, then by all means complete this bonus part to go further. I repeat, no bonus will be taken into consideration if the mandatory part isn’t perfect.
Turn-in all 3 initial files with <samp>_bonus</samp> for this part.

- To succeed <samp>get_next_line</samp> with a single static variable.
- To be able to manage multiple file descriptor with your <samp>get_next_line</samp>. For example, if the file descriptors 3, 4 and 5 are accessible for reading, then you can call <samp>get_next_line</samp> once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors.
