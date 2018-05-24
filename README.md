# minishell1
B-PSU-110_minishell1

The minishell1 is the first step of one of the largest projects of the Epitech's first year, the 42sh.
This shell is based on tcsh shell but in a less complete version.

## Compiling
You will need the standard libC and Make.
Just execute the following command :

    make all clean

## Usage
Start the shell with the following command :

    ./mysh
And then type any command in the prompt.
Dont use "advanced" commands such as :

 - cd && ls
 - cd ; ls
 - man google | less
 - echo "read man" >> todo_list

In fact only singles commands are supported, any of these commands will return an error.
You can close the shell either with a Ctrl-C, Ctrl-D or the command exit.

## Notes
Feel free to submit any ideas or report bugs.
I encourage you to fork the project and use it in any way.
