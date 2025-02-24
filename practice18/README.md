* signal
    * шлет ОС --> SIGSERV
    * шлет пользователь через terminal
        * ctrl + c --> SIGINT
        * ctrl + z --> SIGTSTP
        * ctrl + / --> SIGQUIT
     * утилитой  kill -SIGKILL pid

* STOP/CONTINUE
    * kill -SIGTSTP pid --> process stopped
    * jobs -- список stopped (еще есть fg, bg)
    * kill -SIGCONT pid
* SIGQUIT --->coredump
* signal
    * syscall: sa_flags = SA_RESTART (выполнить еще раз)
    * sleep прерывается, но не восстанавливается
* man 7 signals
* man 2 sigaction
* man signal-safety
