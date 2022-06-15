# minishell
This project is about creating a simple shell.


## Team name  
**SMBASH**  


## Contributors
- amarchan
- abarrier


## Content
- [Historic :clock7:](#historic-clock7)
- [Sources :link:](#sources-link)
- [ToDo :dart:](#todo-dart)


## Historic :clock7:
[Go to content](#content)
|Date _YYYY-MM-DD_|Description|
|:-|:-|
|2022-06-15|init README|


## ToDo :dart:
[Go to content](#content)
- [ ] Display a prompt when waiting for a new command
- [ ] Have a working history
- [ ] Search and launch the right executable (based on the PATH variable or using a relative or an absolute path)
- [ ] Not use more than one global variable. Think about it. You will have to explain its purpose
- [ ] Not interpret unclosed quotes or special characters which are not required by the subject such as \ (backslash) or ; (semicolon)
- [ ] Handle ’ (single quote) which should prevent the shell from interpreting the meta-characters in the quoted sequence
- [ ] Handle " (double quote) which should prevent the shell from interpreting the meta-characters in the quoted sequence except for $ (dollar sign)
- [ ] Implement redirections
	- [ ] < should redirect input
	- [ ] > should redirect output
	- [ ] << should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
	- [ ] >> should redirect output in append mode
- [ ] Implement pipes (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
- [ ] Handle environment variables ($ followed by a sequence of characters) which should expand to their values
- [ ] Handle $? which should expand to the exit status of the most recently executed foreground pipeline
- [ ] Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash
- [ ] In interactive mode
	- [ ] ctrl-C displays a new prompt on a new line
	- [ ] ctrl-D exits the shell
	- [ ] ctrl-\ does nothing
- [ ] Your shell must implement the following builtins
	- [ ] echo with option -n
	- [ ] cd with only a relative or absolute path
	- [ ] pwd with no options
	- [ ] export with no options
	- [ ] unset with no options
	- [ ] env with no options or arguments
	- [ ] exit with no options

> :warning: **_The readline() function can cause memory leaks. You don’t have to fix them. But that doesn’t mean your own code, yes the code you wrote, can have memory leaks._**

## Externals functions
```
readline, rl_clear_history, rl_on_new_line,
rl_replace_line, rl_redisplay, add_history,
printf, malloc, free, write, access, open, read,
close, fork, wait, waitpid, wait3, wait4, signal,
sigaction, sigemptyset, sigaddset, kill, exit,
getcwd, chdir, stat, lstat, fstat, unlink, execve,
dup, dup2, pipe, opendir, readdir, closedir,
strerror, perror, isatty, ttyname, ttyslot, ioctl,
getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
tgetnum, tgetstr, tgoto, tputs
```

### readline
:mag: 

### rl\_clear\_history
:mag: 

### rl\_on\_new\_line
:mag: 

### rl\_replace\_line
:mag: 

### rl\_redisplay
:mag: 

### add\_history
:mag: 

### printf
:mag: 

### malloc
:mag: 

### free
:mag: 

### write
:mag: 

### access
:mag: Use to check permission right on object (files/directory).
:video\_game: pipex

### open
:mag: 

### read
:mag: 

### close
:mag: 

### fork
:mag: Use to clone the active process to a child process
:video\_game: pipex

### wait
:mag: Use to wait a specific process
:video\_game: pipex

### waitpid
:mag: Use to wait a specific process
:video\_game: pipex

### wait3
:mag: 

### wait4
:mag: 

### signal
:mag: 

### sigaction
:mag: 

### sigemptyset
:mag: 

### sigaddset
:mag: 

### kill
:mag: 

### exit
:mag:

### getcwd
:mag: 

### chdir
:mag: 

### stat
:mag: 

### lstat
:mag: 

### fstat
:mag: 

### unlink
:mag: 

### execve
:mag: Use to execute a command
:video\_game: pipex

### dup
:mag: Use to create a new file descriptor according to an existing one
:video\_game: pipex

### dup2
:mag: Use to "replace" an existing file descriptor from another existing one
:video\_game: pipex

### pipe
:mag: Use to create two new file descriptor which can communicate through different process
:video\_game: pipex

### opendir
:mag: 

### readir
:mag: 

### closedir
:mag: 

### strerror
:mag: 

### perror
:mag: 

### isatty
:mag: 

### ttyname
:mag: 

### ttyslot
:mag: 

### ioctl
:mag: 

### getenv
:mag:

### tcsetattr
:mag: 

### tcgetattr
:mag: 

### tgetent
:mag: 

### tgetflag
:mag: 

### tgetnum
:mag: 

### tgetstr
:mag: 

### tgoto
:mag: 

### tputs
:mag: 

## Sources :link:
[Go to content](#content)

### Bash
- https://www.gnu.org/software/bash/manual/html_node/index.html 
(Alicia's note)
- https://docs.google.com/document/d/1JvIKhy3i1cJG7dyi9wVg6Ks37Vdw3P4Qb6tJsEYOMFg/edit 

## Git
- https://github.com/BarrierAntho/Survivor_Note/tree/main/git 

## Shell
- https://explainshell.com/ 
