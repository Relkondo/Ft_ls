# ft_ls - @42Born2Code

My own implementation of the famous Unix command: ls, using the C programming language.

### Requirements
To be able to build and run this program you'll need a macbook, because I didn't make it portable for other systems. Sorry :(. As for software Requirements, you'll need:
- GNU make
- GCC

No specific versions, just update them to the latest version if you still can't build the program.

### Building the program

1. Download/Clone the source code
2. `cd` into the root directory
3. Run `make`

Some macros may be modified in the header file [ft_ls.h](./includes/ft_ls.h).  
- `COLOUR`, Forces on `-G` meaning that colours are always on.
- `COLUMN`, Forces on `'x` meannig that columns are always displayed. 

### Running the program

It's pretty simple, instead of calling `ls`, call `./ft_ls` from the root directory of the source code after building it.

#### Supported flags

- Long listing display: `-l` **[MANDATORY]** 
- Display recursively: `-R` **[MANDATORY]** 
- Display all files: `-a` **[MANDATORY]** 
- Reverse sort: `-r` **[MANDATORY]** 
- Sort by modification date: -t **[MANDATORY]** 
- Sort by last status change time: `-c` 
- Directories are listed as plain files (not searched recursively): `-d` 
- Output is not sorted. Forces `-a` on: `-f` 
- List in long format but omit owner: `-g` 
- Show serial number (inode number): `-i` 
- List in long format but omit group: `-o` 
- Display after pathname: `/`directory: `-p` 
- Sort by time of last access: `-u` 
- Displays columns horizontally sorted: `-x` 
- List all entries except for `.` and `..`: `-A` 
- Display after pathname: `/`directory, `*`executable, `@`sym link, `=`socket, `%`whiteout, `|`FIFO: `-F` 
- Coloured output:`-G` 
- *(Not in the original ls)* Displays number of files read: `-N`
- Sort by file size:`-S` 
- Show time information in full:`-T` 
- Sort by time of file creation:`-U` 
- Force output to be one entry per line: `-1`

### Bonus

- Displays all illegal options, instead of only 1 for the real ls.
- As you can see, lots of optional flags compared to the subject requirements.
- Access Control Lists (@ and + in file permissions).

### Notes

- You can find the project instructions by [clicking here](./ft_ls.en.pdf)
- I know comments would have been super useful, this is kind of a big code base, but I'm trying to go fast in my school program, I'll make sure to add them later.
- There are probably better ways to implement it, but we are limited by a set of functions at my school (just to make it harder and give us a deeper understanding of what's happening in the back), please, review the subject before you explain how `X` or `Y` would have been a better way to do it ;)
