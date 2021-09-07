# Get Next Line
My implementation of the get_next_line function, similar to the getline from CPP and fgets from C.

### What is GNL?
Get Next Line is an individual project at [42](42sp.org.br) that requires us to create a function similar to the getline from CPP and fgets from C. This function allows a file to be read line after line if called in a loop.

### Application flow
Click [here](https://excalidraw.com/#json=5115731591036928,iHsRSeQ06sqBk1BEotMbyA) for the interactive link or [here](./images/final.png) for the full image.

### Badge
<img src="./images/get_next_linem.png" width="150" height="150"/>

#### Objectives
- Unix logic

#### Skills
- Rigor
- Unix
- Algorithms & AI

#### My grade
<img src="./images/score.png" width="150" height="150"/>


## Getting started
**Follow the steps below**
```bash
# Clone the project and access the folder
git clone https://github.com/wwwwelton/GNL && cd GNL/

# Create a main file
touch main.c
```

```c
/*
** Example of a main, change "myfile.txt"
** to a file you want to read
*/

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char	*temp;
	int	fd;

	fd = open("myfile.txt", O_RDONLY);

	while(1)
	{
		temp = get_next_line(fd);
		if (!temp)
		break ;
		printf("%s", temp);
		free(temp);
	}
	return (0);
}
```

```bash
# Compile the files, example:
clang get_next_line.c get_next_line.h get_next_line_utils.c main.c

# Execute your program
./a.out

# Well done!
```

## Functions table reference
The functions present in the utils are from the [Libft](https://github.com/wwwwelton/libft) with some code optimizations.

<table>
    <thead>
        <tr>
            <th colspan=3><h4>GNL Functions</h4></th>
        </tr>
        <tr>
            <th>Name</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=get_next_line.c>free_ptr</a></td>
            <td>Free the memory and sets to NULL a pointer of type **char.</td>
        </tr>
        <tr>
        <tr>
            <td><a href=get_next_line.c>extract_line</a></td>
            <td>Extracts a string from a string delimited by \n.</td>
        </tr>
        </tr>
            <td><a href=get_next_line.c>read_file</a></td>
            <td>Read a file and save the result in a buffer.</td>
        </tr>
        <tr>
            <td><a href=get_next_line.c>get_line</a></td>
            <td>Returns a string from a buffer.</td>
        </tr>
        <tr>
            <td><a href=get_next_line.c>get_next_line</a></td>
            <td>Reads a line from a file descriptor.</td>
    </tbody>
    <thead>
        <tr>
            <th colspan=3><h4>Libft Functions</h4></th>
        </tr>
        <tr>
            <th>Name</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=get_next_line_utils.c>ft_strlen</a></td>
            <td>Computes the length of the string but not including the terminating null character.</td>
        </tr>
        <tr>
            <td><a href=get_next_line_utils.c>ft_strdup</a></td>
            <td>Returns a pointer to a null-terminated byte string, which is a duplicate of the string.</td>
        </tr>
        <tr>
            <td><a href=get_next_line_utils.c>ft_substr</a></td>
            <td>Converts the string to an integer (type int).</td>
        </tr>
        <tr>
            <td><a href=get_next_line_utils.c>ft_strchr</a></td>
            <td>Returns a substring from the string 's'. The substring begins at index 'start' and is of maximum size 'len'.</td>
        </tr>
        <tr>
            <td><a href=get_next_line_utils.c>ft_strjoin</a></td>
            <td>Returns a new string, which is the result of the concatenation of 's1' and 's2'.</td>
        </tr>
    </tbody>
</table>

## Updating

The project is regularly updated with bug fixes and code optimization.

## 📝 License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](license) file for details.

---

Made by Welton Leite 👋 [See my linkedin](https://www.linkedin.com/in/welton-leite-b3492985/)
