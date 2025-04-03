(с) Misha Filitov

## Структуры timeval и tm
```c
struct timeval {
    time_t tv_sec; /* секунды */
    long tv_usec; /* микросекунды */
};
```

```c
struct tm { /* время, разбитое на составляющие */
    int tm_sec; /* секунды от начала минуты: [0 -60] */
    int tm_min; /* минуты от начала часа: [0 - 59] */
    int tm_hour; /* часы от полуночи: [0 - 23] */
    int tm_mday; /* дни от начала месяца: [1 - 31] */
    int tm_mon; /* месяцы с января: [0 - 11] */
    int tm_year; /* годы с 1900 года */
    int tm_wday; /* дни с воскресенья: [0 - 6] */
    int tm_yday; /* дни от начала года (1 января): [0 - 365] */
    int tm_isdst; /* флаг перехода на летнее время: <0, 0, >0 */
};
```
## Используемые функции
#### time
```c
#include <time.h>
time_t time(time_t *calptr);
```
* Возвращает количество секунд, прошедших от начала Эпохи – 00:00:00 1 января 1970, в случае успеха
* Возвращает –1 в случае ошибки.

#### localtime
```c
#include <time.h>
struct tm *localtime(const time_t *calptr);
```
Функция localtime превращает time_t в структуру tm.

#### mktime
```c
#include <time.h>
time_t mktime(struct tm *tmptr);
```
* Функция mktime пересчитает структуру tm и превращает ее в time_t.
* Возвращает –1 в случае ошибки

#### asctime & ctime
```c
#include <time.h>
char *asctime(const struct tm *tmptr);
char *ctime(const time_t *calptr);
char *asctime_r(const struct tm *tm, char *buf);
char *ctime_r(const time_t *timep, char *buf);
```
Превращает структуру tm или time_t в строку \
Функции с суффиксом `r` отличаются от обычных тем, что функции без суффикса `r` принимают в себя только `struct tm` или `time_t`. То есть они используют какой-то внутренний буффер. А чтобы применить функции с суффиксом `r` (например, `ctime_r`, `asctime_r`), пользователю нужно сам задать буффер. Например, `char[] buff;`.


#### gettimeofday
```c
#include <sys/time.h>
int gettimeofday(struct timeval *restrict tp, void *restrict tzp);
```
Функция gettimeofday сохраняет время, прошедшее от начала Эпохи до настоящего момента, по адресу tp.

#### strftime
```c
#include <time.h>
size_t strftime(char *restrict buf, size_t maxsize, const char *restrict format,const struct tm *restrict tmptr);
```
* Представляет структуру tm в виде отформатированной строки.
* Возвращает 0 в случае ошибки

## На что обратить внимание:
* time:
    * c 1970
    * time_t знаковый (отрицательные значения до 1970)
    * проблема 2038, если time_t 32-битный тип данных
* struct tm, localtime
    * tm_year -- c 1900
    * tm_sec 0..60 (а не 0..59): високосная секунда, планета неравномерно крутится
* asctime, ctime: возвращают указатель на <<static переменную>> внутри себя. Эксперимент:
    вызвать два раза ctime для разных входных данный; оба результата вывести на экрана;
    они будут одинаковыми (второй результат перезапишет первый). Лучше использовть asctime_r, ctime_r.
* mktime переводит в секунды и нормализует: учитывает, что сутках 24 часа, високосные года.
* clock_gettime, man hwclock

