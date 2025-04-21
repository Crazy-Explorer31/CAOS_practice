* cat /etc/services
* nc
    * сервер nc -l 33333
    * клиент nc 127.0.0.1 33333
* socket_example.elf localhost 33333
    * lsof | grep 33333
* если не сделать wait, то дочерный будет zombie
    * SIGCHLD --- child умер
* SO_REUSEADDR, SO_REUSEPORT
    * если процесс помрет, то address и port можно использовать
    * после корректного закрытия сервера, сокет еще какое-то время может быть в незакрытом состоянии
* listen(fd, 1)
* simple_server.elf
    * nc 127.0.0.1 33333
    * nc 127.0.0.1 33333
    * lsof | grep 33333
